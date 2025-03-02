#include <iostream>
class VectorDynamic
{
	private:
	int* vector;
	int current_size;
	int size_max;
	public:
	VectorDynamic(int size_max)
	{
		this->size_max = size_max;
		if(size_max == 0)
		{
			this->size_max = 1;
		}
		current_size = 0;
		vector = new int[size_max];
	}
	~VectorDynamic()
	{
		delete[] vector;
	}
	void insert(int value)
	{
		if(current_size == size_max)
		{
			resize();
		}
		vector[current_size] = value;
		current_size++;
		std::cout << "insert new element with value: " << value << " in position " << current_size << std::endl;
	}
	void resize()
	{
		int new_size = size_max * 2;
		int* vectorAux = new int[new_size];
		for (int i = 0; i < size_max; i++)
		{
			vectorAux[i] = vector[i];
		}
		delete[] vector;
		size_max = new_size;
		vector = vectorAux;
		std::cout << "Resize" << std::endl;
	}
	void printVector()
	{
		for (int i = 0; i < current_size; i++)
		{
			std::cout << "Print Vector Values: " << vector[i] << std::endl; 
		}
		
	}
};

/*int main()
{
	VectorDynamic vector(0);
	vector.insert(10);
	vector.insert(20);
	vector.insert(30);
	vector.insert(40);
	vector.insert(50);
	vector.insert(60);
	vector.insert(70);
	vector.insert(80);
	vector.insert(90);
	vector.insert(100);
	vector.insert(110);
	vector.insert(120);
	vector.insert(130);
	vector.insert(140);
	vector.insert(150);
	vector.insert(160);
	vector.insert(170);



	vector.printVector();

	return 0;
}*/