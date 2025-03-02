void trade(int* value1, int* value2)
{
	int temp = 0;
	temp = *value1;
	*value1 = *value2;
	*value2 = temp;

	return;
}