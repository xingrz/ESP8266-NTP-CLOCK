#include "hspi.h"

static const char *TAG = "hspi";

void
hspi_init(void)
{
	ESP_LOGV(TAG, "hspi_init enter");

	spi_config_t spi = {
			.interface.val = SPI_DEFAULT_INTERFACE,
			.intr_enable.val = 0,
			.mode = SPI_MASTER_MODE,
			.clk_div = SPI_80MHz_DIV,
			.event_cb = NULL,
	};

	spi_init(HSPI_HOST, &spi);

	ESP_LOGV(TAG, "hspi_init exit");
}

static inline void
hspi_write_item(uint32_t data, uint32_t len)
{
	spi_trans_t trans = {
			.mosi = &data,
			.bits = {.mosi = len * 8},
	};

	spi_trans(HSPI_HOST, &trans);
}

void
hspi_write8(uint8_t val)
{
	hspi_write_item(val, sizeof(uint8_t));
}

void
hspi_write16(uint16_t val)
{
	hspi_write_item(val, sizeof(uint16_t));
}

void
hspi_write32(uint32_t val)
{
	hspi_write_item(val, sizeof(uint32_t));
}
