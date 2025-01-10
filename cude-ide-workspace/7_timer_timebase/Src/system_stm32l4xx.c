#include <stdint.h>

uint32_t SystemCoreClock = 4000000U;

const uint32_t MSIRangeTable[] = {100000, 200000, 400000, 800000, 1000000, 2000000, 4000000, 8000000, 16000000, 24000000, 32000000, 48000000};
//const uint32_t APBPrescTable[8] = {0, 1, 2, 4, 8, 16, 64, 128};

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};
