#include "bluetooth.h"

uint8_t buffer_index = 0;
uint8_t timer_count = 0;
char buffer[50];
char info[50];

void msgHandler(void) {
	if (stringCompare(buffer, "SERWO MAX UP", strlen("SERWO MAX UP"))) {
		setPositionToMax(&servo);
		HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going up to min.\n", strlen("Servo going up to min.\n"), 500);
	} else if (stringCompare(buffer, "SERWO MAX DOWN", strlen("SERWO MAX DOWN"))) {
		setPositionToMin(&servo);
		HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going down to max.\n", strlen("Servo going down to max.\n"), 500);
	} else if (stringCompare(buffer, "SERWO UP", strlen("SERWO UP"))) {
		increasePositionBy(&servo, 1);
		HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going up by 1.\n", strlen("Servo going up by 1.\n"), 500);
	} else if (stringCompare(buffer, "SERWO DOWN", strlen("SERWO DOWN"))) {
		increasePositionBy(&servo, -1);
		HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going down by 1.\n", strlen("Servo going down by 1.\n"), 500);
	} else if (strncmp(buffer, "SET MIN LDR READING xxxx", strlen("SET MIN LDR READING")) == 0) {
		uint16_t ldrValue = getLastWordAsInt(buffer);
		setMinReading(&ldr, ldrValue);
	} else if (strncmp(buffer, "SET MAX LDR READING xxxx", strlen("SET MAX LDR READING")) == 0) {
		uint16_t ldrValue = getLastWordAsInt(buffer);
		setMaxReading(&ldr, ldrValue);
	} else if (strncmp(buffer, "SET UPPER LDR CONTROL LIMIT xxxx", strlen("SET UPPER LDR CONTROL LIMIT")) == 0) {
		uint16_t ldrValue = getLastWordAsInt(buffer);
		setUpperControlLimit(&ldr, ldrValue);
	} else if (strncmp(buffer, "SET LOWER LDR CONTROL LIMIT xxxx", strlen("SET LOWER LDR CONTROL LIMIT")) == 0) {
		uint16_t ldrValue = getLastWordAsInt(buffer);
		setLowerControlLimit(&ldr, ldrValue);
	} else if (stringCompare(buffer, "PRINT MIN LDR READING", strlen("PRINT MIN LDR READING"))) {
		uint16_t ldrValue = getMinReading(&ldr);
		sprintf(info, "minLdrReading=%d", ldrValue);
		strcat(info, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)info, strlen(info), 500);
	} else if (stringCompare(buffer, "PRINT MAX LDR READING", strlen("PRINT MAX LDR READING"))) {
		uint16_t ldrValue = getMaxReading(&ldr);
		sprintf(info, "maxLdrReading=%d", ldrValue);
		strcat(info, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)info, strlen(info), 500);
	} else if (stringCompare(buffer, "PRINT UPPER LDR CONTROL LIMIT", strlen("PRINT UPPER LDR CONTROL LIMIT"))) {
		uint16_t ldrValue = getUpperControlLimit(&ldr);
		sprintf(info, "upperLdrControlLimit=%d", ldrValue);
		strcat(info, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)info, strlen(info), 500);
	} else if (stringCompare(buffer, "PRINT LOWER LDR CONTROL LIMIT", strlen("PRINT LOWER LDR CONTROL LIMIT"))) {
		uint16_t ldrValue = getLowerControlLimit(&ldr);
		sprintf(info, "lowerLdrControlLimit=%d", ldrValue);
		strcat(info, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)info, strlen(info), 500);
	} else {
		strcat(buffer, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 500);
	}

	memset(buffer, 0, sizeof(buffer));
	buffer_index = 0;
	timer_count = 0;
}
