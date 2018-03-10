#ifndef UNITYOUTPUTIMPLEMENTATIONS_UNITYOUTPUT_H
#define UNITYOUTPUTIMPLEMENTATIONS_UNITYOUTPUT_H

#include <stdint.h>

void UnityOutput_init(uint32_t baud_rate);
void UnityOutput_write(uint8_t byte);

#endif //UNITYOUTPUTIMPLEMENTATIONS_UNITYOUTPUT_H
