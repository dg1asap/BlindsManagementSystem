#include "bluetooth.h"

Bluetooth bluetooth = {{0}, 0, 0};

void msgHandler(Bluetooth* bluetooth) {
	if (strncmp(bluetooth->buffer, "SERWO MAX UP", strlen("SERWO MAX UP")) == 0)
		handleSerwoMaxUp(bluetooth);
	else if (strncmp(bluetooth->buffer, "SERWO MAX DOWN", strlen("SERWO MAX DOWN")) == 0)
		handleSerwoMaxDown(bluetooth);
	else if (strncmp(bluetooth->buffer, "SERWO UP", strlen("SERWO UP")) == 0)
		handleSerwoUp(bluetooth);
	else if (strncmp(bluetooth->buffer, "SERWO DOWN", strlen("SERWO DOWN")) == 0)
		handleSerwoDown(bluetooth);
	else if (strncmp(bluetooth->buffer, "SET MIN LDR READING xxxx", strlen("SET MIN LDR READING")) == 0)
		handleSetMinLDRreading(bluetooth);
	else if (strncmp(bluetooth->buffer, "SET MAX LDR READING xxxx", strlen("SET MAX LDR READING")) == 0)
		handleSetMaxLDRreading(bluetooth);
	else if (strncmp(bluetooth->buffer, "SET UPPER LDR CONTROL LIMIT xxxx", strlen("SET UPPER LDR CONTROL LIMIT")) == 0)
		handleSetUpperLDRcontrolLimit(bluetooth);
	else if (strncmp(bluetooth->buffer, "SET LOWER LDR CONTROL LIMIT xxxx", strlen("SET LOWER LDR CONTROL LIMIT")) == 0)
		handleSetLowerLDRcontrolLimit(bluetooth);
	else if (strncmp(bluetooth->buffer, "SET SERVO MAX POSITION xxx", strlen("PRINT SERVO MAX POSITON")) == 0)
		handleSetServoMaxPosition(bluetooth);
	else if (strncmp(bluetooth->buffer, "PRINT MIN LDR READING", strlen("PRINT MIN LDR READING")) == 0)
		handlePrintMinLDRreading(bluetooth);
	else if (strncmp(bluetooth->buffer, "PRINT MAX LDR READING", strlen("PRINT MAX LDR READING")) == 0)
		handlePrintMaxLDRreading(bluetooth);
	else if (strncmp(bluetooth->buffer, "PRINT UPPER LDR CONTROL LIMIT", strlen("PRINT UPPER LDR CONTROL LIMIT")) == 0)
		handlePrintUpperLDRcontrolLimit(bluetooth);
	else if (strncmp(bluetooth->buffer, "PRINT LOWER LDR CONTROL LIMIT", strlen("PRINT LOWER LDR CONTROL LIMIT")) == 0)
		handlePrintLowerLDRcontrolLimit(bluetooth);
	else if (strncmp(bluetooth->buffer, "PRINT SERVO MAX POSITION", strlen("PRINT SERVO MAX POSITON")) == 0)
		handlePrintServoMaxPosition(bluetooth);
	else if (strncmp(bluetooth->buffer, "TIMER UP xxxx", strlen("TIMER UP")) == 0)
		handleTimerUp(bluetooth);
	else if (strncmp(bluetooth->buffer, "TIMER DOWN xxxx", strlen("TIMER DOWN")) == 0)
		handleTimerDown(bluetooth);
	else if (strncmp(bluetooth->buffer, "LDR TURN ON", strlen("LDR TURN ON")) == 0)
		handleTurnOnLDR(bluetooth);
	else if (strncmp(bluetooth->buffer, "LDR TURN OFF", strlen("LDR TURN OFF")) == 0)
		handleTurnOffLDR(bluetooth);
	else if (strncmp(bluetooth->buffer, "SCHEDULER UP ON", strlen("SCHEDULER UP ON")) == 0)
		handleSchedulerUpTurnOn(bluetooth);
	else if (strncmp(bluetooth->buffer, "SCHEDULER UP OFF", strlen("SCHEDULER UP OFF")) == 0)
		handleSchedulerUpTurnOff(bluetooth);
	else if (strncmp(bluetooth->buffer, "SCHEDULER DOWN ON", strlen("SCHEDULER DOWN ON")) == 0)
		handleSchedulerDownTurnOn(bluetooth);
	else if (strncmp(bluetooth->buffer, "SCHEDULER DOWN OFF", strlen("SCHEDULER DOWN OFF")) == 0)
		handleSchedulerDownTurnOff(bluetooth);
	else
		handleIncorrectCommand(bluetooth);

	memset(bluetooth->buffer, 0, sizeof(bluetooth->buffer));
	bluetooth->buffer_index = 0;
	bluetooth->timer_count = 0;
}

void handleSerwoMaxUp(Bluetooth* bluetooth) {
	setPositionToMax(&servo);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going up to min.\n", strlen("Servo going up to min.\n"), 500);
}

void handleSerwoMaxDown(Bluetooth* bluetooth) {
	setPositionToMin(&servo);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going down to max.\n", strlen("Servo going down to max.\n"), 500);
}

void handleSerwoUp(Bluetooth* bluetooth) {
	increasePositionBy(&servo, 1);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going up by 1.\n", strlen("Servo going up by 1.\n"), 500);
}

void handleSerwoDown(Bluetooth* bluetooth) {
	increasePositionBy(&servo, -1);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Servo going down by 1.\n", strlen("Servo going down by 1.\n"), 500);
}

void handleSetMinLDRreading(Bluetooth* bluetooth) {
	uint16_t ldrValue = getLastWordAsInt(bluetooth->buffer);
	setMinReading(&ldr, ldrValue);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Operation ended sucessful\n", strlen("Operation ended sucessful\n"), 500);
}

void handleSetMaxLDRreading(Bluetooth* bluetooth) {
	uint16_t ldrValue = getLastWordAsInt(bluetooth->buffer);
	setMaxReading(&ldr, ldrValue);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Operation ended sucessful\n", strlen("Operation ended sucessful\n"), 500);
}

void handleSetUpperLDRcontrolLimit(Bluetooth* bluetooth) {
	uint16_t ldrValue = getLastWordAsInt(bluetooth->buffer);
	setUpperControlLimit(&ldr, ldrValue);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Operation ended sucessful\n", strlen("Operation ended sucessful\n"), 500);
}

void handleSetLowerLDRcontrolLimit(Bluetooth* bluetooth) {
	uint16_t ldrValue = getLastWordAsInt(bluetooth->buffer);
	setLowerControlLimit(&ldr, ldrValue);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Operation ended sucessful\n", strlen("Operation ended sucessful\n"), 500);
}

void handlePrintMinLDRreading(Bluetooth* bluetooth) {
	uint16_t ldrValue = getMinReading(&ldr);
	printValue(bluetooth, "minLDRreading", ldrValue);
}

void handlePrintMaxLDRreading(Bluetooth* bluetooth) {
	uint16_t ldrValue = getMaxReading(&ldr);
	printValue(bluetooth, "maxLDRReading", ldrValue);
}

void handlePrintUpperLDRcontrolLimit(Bluetooth* bluetooth) {
	uint16_t ldrValue = getUpperControlLimit(&ldr);
	printValue(bluetooth, "upperLDRcontrolLimit", ldrValue);
}

void handlePrintLowerLDRcontrolLimit(Bluetooth* bluetooth) {
	uint16_t ldrValue = getLowerControlLimit(&ldr);
	printValue(bluetooth, "lowerLDRcontrolLimit", ldrValue);
}

void handleSetServoMaxPosition(Bluetooth* bluetooth) {
	uint16_t newMaxPosition_ = getLastWordAsInt(bluetooth->buffer);
	setMaxPositon(&servo, newMaxPosition_);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Operation ended sucessful\n", strlen("Operation ended sucessful\n"), 500);
}
void handlePrintServoMaxPosition(Bluetooth* bluetooth) {
	uint16_t maxPostion = getMaxPositon(&servo);
	printValue(bluetooth, "servoMaxPosition", maxPostion);
}

void handleIncorrectCommand(Bluetooth* bluetooth) {
	strcat(bluetooth->buffer, "\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)bluetooth->buffer, strlen(bluetooth->buffer), 500);
}

void handleTimerUp(Bluetooth* bluetooth) {
	handleTimerUp(bluetooth);
	uint16_t newServoUpTime_ = getLastWordAsInt(bluetooth->buffer);
	setServoUpTime(&servoScheduler, newServoUpTime_);
	turnOnServoUp(&servoScheduler);
	printValue(bluetooth, "Servo up in", newServoUpTime_);
}

void handleTimerDown(Bluetooth* bluetooth) {
	uint16_t newServoUpTime_ = getLastWordAsInt(bluetooth->buffer);
	setServoUpTime(&servoScheduler, newServoUpTime_);
	turnOnServoUp(&servoScheduler);
	printValue(bluetooth, "Servo down in", newServoUpTime_);
}

void handleTurnOnLDR(Bluetooth* bluetooth) {
	turn0n(&ldr);
	HAL_UART_Transmit(&huart1, (uint8_t*)"LDR is turn on\n", strlen("LDR is turn on\n"), 500);
}

void handleTurnOffLDR(Bluetooth* bluetooth) {
	turnOff(&ldr);
	HAL_UART_Transmit(&huart1, (uint8_t*)"LDR is turn off\n", strlen("LDR is turn off\n"), 500);
}

void handleSchedulerUpTurnOn(Bluetooth* bluetooth) {
	turnOnServoUp(&servoScheduler);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Scheduler up is turn on\n", strlen("Scheduler up is turn on\n"), 500);
}

void handleSchedulerUpTurnOff(Bluetooth* bluetooth) {
	turnOffServoUp(&servoScheduler);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Scheduler up is turn off\n", strlen("Scheduler up is turn off\n"), 500);
}

void handleSchedulerDownTurnOn(Bluetooth* bluetooth) {
	turnOnServoDown(&servoScheduler);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Scheduler down is turn on\n", strlen("Scheduler down is turn on\n"), 500);
}

void handleSchedulerDownTurnOff(Bluetooth* bluetooth) {
	turnOffServoDown(&servoScheduler);
	HAL_UART_Transmit(&huart1, (uint8_t*)"Scheduler down is turn off\n", strlen("Scheduler down is turn off\n"), 500);
}


void printValue(Bluetooth* bluetooth, char* text, uint16_t value) {
	char info[50];
	char stringValue[50];
	strcpy(info, text);
	sprintf(stringValue, "=%d", value);
	strcat(info, stringValue);
	strcat(info, "\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)info, strlen(info), 500);
}

