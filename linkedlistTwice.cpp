#include <iostream>
struct Node
{
    int value;
    Node* next;
    Node* prev;
};

class LinkedListTwice
{
	private:
	Node* head;
	Node* tail;
	public:
	LinkedListTwice()
	{
		head = nullptr;
		tail = nullptr;
	}
	~LinkedListTwice()
	{
		Node* currentNode = head;
		Node* next = nullptr;
		while(currentNode != nullptr)
		{
			next = currentNode->next;
			delete currentNode;
			currentNode = next;
		}
	}
	void insertAtBegin(int value)
	{
		Node* node = new Node;
		node->value = value;
		if(head == nullptr)  
		{
			node->next = nullptr;
			node->prev = nullptr;
			head = node;
			tail = head;
			//std::cout << "New head: " << head->value << std::endl;
			//std::cout << "New tail: " << tail->value << std::endl;
		}
		else
		{
			node->next = head;
			node->prev = nullptr;
			head->prev = node;
			head = node;
			//std::cout << "New head: " << head->value << std::endl;
			//std::cout << "New tail: " << tail->value << std::endl;
		}
	}
	void insertAtMid(int value)
	{
		Node* node = new Node;
		if(head == nullptr)
		{
			node->value = value;
			node->next = nullptr;
			node->prev = nullptr;
			head = node;
			tail = node;
		}
		else
		{
			int mid = 0;
			Node* currentNode = head;
			Node* prevNode = nullptr;
			Node* nextNode = nullptr;
			while(currentNode != nullptr)
			{
				mid++;
				currentNode = currentNode->next;
			}
			currentNode = head;
			if(mid % 2 == 0)
			{
				mid = mid/2;
			}
			else
			{
				mid = (mid + 1) / 2;
			}
			for(int i = 1; i <= mid; i++)
			{
				currentNode = currentNode->next;
			}
			node->value = value;
			nextNode = currentNode;
			prevNode = currentNode->prev;
			node->next = nextNode;
			node->prev = prevNode;
			nextNode->prev = node;
			prevNode->next = node;
		}
	}
	void insertAtEnd(int value)
	{
		Node* node = new Node;
		Node* currentNode = head;
		if(head == nullptr)
		{
			node->value = value;
			node->next = nullptr;
			node->prev = nullptr;
			head = node;
			tail = node;
		}
		else
		{
			while(currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = node;
			node->value = value;
			node->prev = currentNode;
			node->next = nullptr;
			tail = node;
		}
	}
	void remove(int value)
	{
		Node* nextNode = nullptr;
		Node* prevNode = nullptr;
		Node* currentNode = head;
		if(head == nullptr)
		{
			std::cout << "List clean" << std::endl;
		}
		else
		{
			while(currentNode != nullptr && currentNode->value != value)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			if(currentNode == nullptr) //Se tiver somente um e o proximo for nulo current fica nulo
			{
				std::cout << "value not found" << std::endl;
				return;
			}
			bool flag = false;
			if(currentNode->prev == nullptr && currentNode->next == nullptr)
			{
				flag = true;
				head = nullptr;
				tail = nullptr;
			}
			else if(prevNode == nullptr)
			{
				head = currentNode->next;
				head->prev = nullptr;
				flag = true;
			}
			else if(currentNode->next == nullptr)
			{
			 	tail = prevNode;
			 	tail->next = nullptr;
				flag = true;
			}
			else
			{
				nextNode = currentNode->next;
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
				flag = true;	
			}
			if(flag)
			{
				delete currentNode;
			}
		}
	}
	void printList()
	{
		Node* currentNode = head;
		if(head == nullptr)
		{
			std::cout << "List is clean" << std::endl;	
		}
		else
		{
			while(currentNode != nullptr)
			{
				std::cout << "Values: " << currentNode->value << std::endl;
				currentNode = currentNode->next;
			}
			std::cout << "Head final: " << head->value << std::endl;
			std::cout << "Tail final: " << tail->value << std::endl;
		}
	}
};
/*int main() {
    LinkedListTwice lista;
    lista.insertAtEnd(100);     // Lista: [100]
    lista.insertAtBegin(50);    // Lista: [50] <-> [100]
    lista.insertAtMid(75);      // Lista: [50] <-> [75] <-> [100]
    lista.insertAtEnd(200);     // Lista: [50] <-> [75] <-> [100] <-> [200]
    lista.insertAtMid(150);     // Lista: [50] <-> [75] <-> [150] <-> [100] <-> [200]
    lista.printList();          // Saída: 50, 75, 150, 100, 200
	lista.remove(50);
	lista.remove(200);
	lista.remove(150);
	lista.remove(75);
	lista.remove(1000);
	lista.remove(100);
	lista.printList();
	lista.remove(1000);
    return 0;
}*/
