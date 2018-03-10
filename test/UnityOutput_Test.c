#include "src/unity.h"
#include "lib/include/UnityOutput.h"
#include "lib/include/platform/io.h"

void setUp(void) {
    resetDummyIO();
}

void test_initSetsBaudRate(void) {
    uint16_t baud_rate = 9600;
    UnityOutput_init(baud_rate);
    uint16_t expected_baud_rate_register_value = (uint16_t)(cpu_frequency/(16 * baud_rate) - 1);
    TEST_ASSERT_EQUAL_UINT8(expected_baud_rate_register_value >> 8, *unity_output_usart_baud_rate_register_high);
    TEST_ASSERT_EQUAL_UINT8((uint8_t)(expected_baud_rate_register_value), *unity_output_usart_baud_rate_register_low);
}

void test_initEnablesTransmitter(void) {
    UnityOutput_init(9600);
    TEST_ASSERT_BIT_HIGH(unity_output_usart_transmitter_enable_bit, *unity_output_usart_control_and_status_register_b);
}

void test_initDoesNotTouchOtherValuesInStatusControlRegisterB(void) {
    uint8_t some_arbitrary_value = 0xAC;
    *unity_output_usart_control_and_status_register_b = some_arbitrary_value;
    UnityOutput_init(9600);
    TEST_ASSERT_BITS(~(1 << unity_output_usart_transmitter_enable_bit),
                     some_arbitrary_value,
                     *unity_output_usart_control_and_status_register_b);
}

void test_initUses8BitCharacterSize(void) {
    UnityOutput_init(9600);
    TEST_ASSERT_BITS_HIGH( 0b11 << unity_output_usart_character_size_offset,
                      *unity_output_usart_control_and_status_register_c);
}

void test_initDoesNotTouchUnncessaryValuesInControlRegisterC(void) {
    *unity_output_usart_control_and_status_register_c = 0xFB;
    UnityOutput_init(9600);
    TEST_ASSERT_BITS( ~(0b11 << unity_output_usart_character_size_offset),
                      0xFB, *unity_output_usart_control_and_status_register_c);
}

