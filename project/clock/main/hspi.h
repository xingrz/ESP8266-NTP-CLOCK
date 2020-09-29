#ifndef _CLOCK_HSPI_
#define _CLOCK_HSPI_

#include "common.h"

#define HSPI_MAX_LEN 64

void hspi_init(void);

void hspi_write(void *buf, uint32_t len);
void hspi_write8(uint8_t val);
void hspi_write16(uint16_t val);
void hspi_write32(uint32_t val);

#endif  // _CLOCK_HSPI_
