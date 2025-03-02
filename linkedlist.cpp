#include <iostream>

struct Node
{
	int data;
	Node* next;
};
class linkedlist {
private:
	Node* head;
public:
	linkedlist() {
		head = nullptr;
	}
	~linkedlist() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	void insertAtBeginning(int value) {// coloca no come�o 
		Node* no = new Node;
		no->data = value;
		no->next = head;
		head = no;
	}
	void insertAtEnd(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
		
	}

	void remove(int value) {
		if (head == nullptr) {
			std::cout << "A Lista est� vazia" << std::endl;
		}
		else {
			Node* current = head;
			Node* prev = nullptr;
			while (current != nullptr && current->data != value) {
				prev = current;
				current = current->next;
			}
			if (current == nullptr) {
				return;
			}
			if (prev == nullptr) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
		}
	}

	void traverse(){//imprimi na tela
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->data << std::endl;
			current = current->next;
		}
		std::cout << "Lista vazia!" << std::endl;
	}
};