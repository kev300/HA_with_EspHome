uint8_t min_temp = 10;
uint8_t max_temp = 43;

bool checkTmp(float temp) {
	return temp < min_temp || temp > max_temp;
}
