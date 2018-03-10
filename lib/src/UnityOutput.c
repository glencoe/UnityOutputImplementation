#include "lib/include/UnityOutput.h"
#include "lib/include/platform/io.h"
#include <stdbool.h>

static void setBaudRate(uint16_t baud_rate);
static void enableTransmitter(void);
static void set8BitCharacterSize(void);
static bool notReady(void);

void UnityOutput_init(uint16_t baud_rate) {
    setBaudRate(baud_rate);
    enableTransmitter();
    set8BitCharacterSize();
}

void UnityOutput_write(uint8_t byte) {
    while( notReady() ) {}
    *unity_output_usart_data_register = byte;
}

void setBaudRate(uint16_t baud_rate) {
    uint16_t baud_rate_register_value = (uint16_t)(cpu_frequency/(16*baud_rate) - 1);
    *unity_output_usart_baud_rate_register_low = (uint8_t) (baud_rate_register_value >> 8);
    *unity_output_usart_baud_rate_register_high = (uint8_t) baud_rate_register_value;
}

void enableTransmitter(void) {
    *unity_output_usart_control_and_status_register_b |= 1 << 3;
}

void set8BitCharacterSize(void) {
    uint8_t unity_output_usart_8bit_character_size = 0b11 << unity_output_usart_character_size_offset;
    *unity_output_usart_control_and_status_register_c |= unity_output_usart_8bit_character_size;
}

bool notReady(void) {
    return !(*unity_output_usart_control_and_status_register_a & (1 << unity_output_usart_transmit_complete_bit));

}
