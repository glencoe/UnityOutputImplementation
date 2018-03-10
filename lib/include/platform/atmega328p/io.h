#ifndef UNITYOUTPUTIMPLEMENTATIONS_ATMEGA328P_IO_H
#define UNITYOUTPUTIMPLEMENTATIONS_ATMEGA328P_IO_H

#include <stdint.h>
#include <avr/io.h>

static uint64_t cpu_frequency = F_CPU;
static const uint8_t unity_output_usart_transmitter_enable_bit = TXEN0;
static const uint8_t unity_output_usart_character_size_offset = UCSZ00;
static const uint8_t unity_output_usart_transmit_complete_bit = TXC0;
static volatile uint8_t *const unity_output_usart_baud_rate_register_low = &UBRR0L;
static volatile uint8_t *const unity_output_usart_baud_rate_register_high = &UBRR0H;
static volatile uint8_t *const unity_output_usart_control_and_status_register_a = &UCSR0A;
static volatile uint8_t *const unity_output_usart_control_and_status_register_b = &UCSR0B;
static volatile uint8_t *const unity_output_usart_control_and_status_register_c = &UCSR0C;
static volatile uint8_t *const unity_output_usart_data_register = &UDR0;


#endif //UNITYOUTPUTIMPLEMENTATIONS_IO_H
