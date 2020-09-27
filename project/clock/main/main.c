#include "common.h"

static const char *TAG = "main";

void
app_main(void)
{
	BaseType_t ret = pdFALSE;
	EventGroupHandle_t boot = xEventGroupCreate();

	ret = xTaskCreate(lcd_proc_task, "lcd_proc_task", 2048, boot, 10, NULL);
	if (ret != pdPASS) ESP_LOGE(TAG, "Failed xTaskCreate(lcd_proc_task): %d", ret);

	xEventGroupWaitBits(boot, BOOT_TASK_ALL, pdFALSE, pdTRUE, portMAX_DELAY);
	ESP_LOGI(TAG, "SYSTEM READY");

	while (1) {
		vTaskDelay(10);
	}
}
