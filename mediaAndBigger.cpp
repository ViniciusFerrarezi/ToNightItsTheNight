//#include <iostream>
float mediaAndbigger(float* numbersOfNotes, int size)
{
	float sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum = sum + numbersOfNotes[i];
	}
	float media = sum/size;
	return media;
}

float biggerNumber(float* target, int size)
{
	float bigger = target[0];
	for(int i = 1; i < size; i++)
	{
		if(target[i] > bigger)
		{
			bigger = target[i];
		}
	}
	return bigger;
}

/*int main()
{
	int size;
	std::cout << "Hello, how many notes do you want calculate" << std::endl;
	std::cin >> size;
	std::cout << "Say the notes" << std::endl;
	float* numbersOfNotes = new float [size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Note: ";
		std::cin >> numbersOfNotes[i];
	}
	float media = mediaAndbigger(numbersOfNotes, size);
	float bigger = biggerNumber(numbersOfNotes, size);

	std::cout << "Media is " << media << " and " << "bigger is " << bigger << std::endl;

	delete[] numbersOfNotes;
	return 0;
}
*/