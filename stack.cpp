#include <iostream>
struct Node
{
	int value;
	Node* next;
};
class Stack
{
	private:
		Node* top;
	public:
		Stack()
		{
			top = nullptr;
		}
		~Stack()
		{
			Node* current = top;
			Node* next = nullptr;
			while(current != nullptr)
			{
				next = current->next;
				delete current;
				current = next;
			}
		}
		void push(int value)
		{
			Node* node = new Node;
			if(top == nullptr)
			{
				node->value = value;
				node->next = nullptr;
				top = node;
			}
			else
			{
				node->value = value;	
				node->next = top; //O next recebe o top anterior
				top = node; //Atualiza o Top para o novo
			}
		}
		int pop()
		{
			if(top == nullptr)
			{
				std::cout << "Void list" << std::endl;
				return -1;
			}
			else
			{
				Node* next = nullptr;
				next = top->next;
				int value = top->value;
				delete top;
				top = next;
				return value;
			}
		}
		void PrintStack()
		{
			if(top == nullptr)
			{
				std::cout << "Void List" << std::endl;
				return;
			}
			else
			{
				Node* current = top;
				while(current != nullptr)
				{
					std::cout << "Values: " << current->value << std::endl;
					current = current->next;
				}
			}
		}
};
/*
int main()
{
	Stack pilha;
	pilha.push(10);
	pilha.push(20);
	pilha.push(30);
	pilha.PrintStack();
    return 0;
}*/