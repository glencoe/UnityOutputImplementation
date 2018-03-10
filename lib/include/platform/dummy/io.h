#ifndef UNITYOUTPUTIMPLEMENTATIONS_DUMMY_IO_H
#define UNITYOUTPUTIMPLEMENTATIONS_DUMMY_IO_H

#include <stdint.h>

static uint64_t cpu_frequency = 16000000;
static const uint8_t unity_output_usart_transmitter_enable_bit = 3;
static const uint8_t unity_output_usart_character_size_offset = 2;
static const uint8_t unity_output_usart_transmit_complete_bit = 6;

extern uint8_t usart_baud_rate_low;
static uint8_t * const unity_output_usart_baud_rate_register_low = &usart_baud_rate_low;
extern uint8_t usart_baud_rate_high;
static uint8_t * const unity_output_usart_baud_rate_register_high = &usart_baud_rate_high;
extern uint8_t usart_control_and_status_a;
static uint8_t *const unity_output_usart_control_and_status_register_a = &usart_control_and_status_a;
extern uint8_t usart_control_and_status_b;
static uint8_t *const unity_output_usart_control_and_status_register_b = &usart_control_and_status_b;
extern uint8_t usart_control_and_status_c;
static uint8_t *const unity_output_usart_control_and_status_register_c = &usart_control_and_status_c;
extern uint8_t usart_data;
static uint8_t *const unity_output_usart_data_register = &usart_data;

void resetDummyIO();


#endif //UNITYOUTPUTIMPLEMENTATIONS_IO_H
