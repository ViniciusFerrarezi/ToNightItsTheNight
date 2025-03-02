#include <iostream>
	
class Tree
{
	private:
		struct Node
		{
			int value;
			Node* right;
			Node* left;
		};
		Node* root;
	public:
		Tree()
		{
			root = nullptr;
		}
		~Tree()
		{
			destructorPostOrder(root);
		}
		void destructorPostOrder(Node* current)
		{
			if(current == nullptr)
			{
				return;
			}
			destructorPostOrder(current->left);
			destructorPostOrder(current->right);
			delete current;
		}

		void insert(int value)
		{
			insertLeafs(root, value);
		}
		void insertLeafs(Node*& node, int value) // Node*& faz uma referencia a um Node ou seja alterar ele altera oq ele esta referindo tambem nao e uma copia de um ponteiro desgraca
		{
			if(node == nullptr)
			{
				Node* newNode = new Node;
				newNode->value = value;
				newNode->left = nullptr;
				newNode->right = nullptr;
				node = newNode;
			}
			else if(value < node->value)
			{
				insertLeafs(node->left, value);
			}
			else
			{
				insertLeafs(node->right, value);
			}
		}
		void preOrder()
		{
			preOrder(root);
		}
		//percusos as chamadas recursivas sempre passam por todos os nos verificando a esquerda e direita
		//Ex: preOrder
		//Entra na raiz imprime - vai para esquerda da raiz imprime e assim por diante
		//Quando der nullptr ele vai para a direita do ultimo Node q acessou
		//Se tiver algum ele imprimi se nao ele retorna e vai para a direita do anterior
		//Ira sempre verificar a esquerda e direita de cada Node
		void preOrder(Node* current)
		{
			if(current == nullptr)
			{
				return;
			}
			std::cout << "Value: " << current->value << std::endl;
			preOrder(current->left);
			preOrder(current->right);
		}
		void inOrder()
		{
			inOrder(root);
		}
		void inOrder(Node* current)
		{
			if(current == nullptr)
			{
				return;
			}
			inOrder(current->left);
			std::cout << "Value: " << current->value << std::endl;
			inOrder(current->right);
		}
		void postOrder()
		{
			postOrder(root);
		}
		void postOrder(Node* current)
		{
			if(current == nullptr)
			{
				return;
			}
			postOrder(current->left);
			postOrder(current->right);
			std::cout << "Value: " << current->value << std::endl;
		}
		Node* findMin(Node* node)
		{
			if(node == nullptr)
			{
				return nullptr;
			}
			while(node->left != nullptr)
			{
				node = node->left;
			}
			return node;
		}
		void remove(int value)
		{
			remove(root, value, root);
		}
		void remove(Node*& current, int value, Node*& prev)
		{
			if(current == nullptr)
			{
				return;
			}
			else if(value < current->value)
			{
				remove(current->left, value, current);
			}
			else if(value > current->value)
			{
				remove(current->right, value, current);
			}
			else
			{
				if(current->left != nullptr && current->right != nullptr)
				{
					Node* min = findMin(current->right);
					current->value = min->value;
					remove(current->right, min->value, current);
				}
				else if(current->left == nullptr && current->right == nullptr)
				{
					if(prev->left == current)
					{
						std::cout << "Remove Value: " << value << std::endl;
						delete current;
						prev->left = nullptr;
					}
					else
					{
						std::cout << "Remove Value: " << value << std::endl;
						delete current;
						prev->right = nullptr;
					}
					return;
				}
				else
				{
					Node* nextRight = current->right;
					Node* nextLeft = current->left;
					if(current == root)
					{
						if(nextLeft != nullptr)
						{
							root = nextLeft;
						}
						else
						{
							root = nextRight;
						}
					}
					else
					{
						if(prev->left == current)
						{
							if(nextLeft != nullptr)
							{
								prev->left = nextLeft;
							}
							else
							{
								prev->left = nextRight;
							}
						}
						else
						{
							if(nextRight != nullptr)
							{
								prev->right = nextRight;
							}
							else
							{
								prev->right = nextLeft;
							}
						}
					}
					std::cout << "Remove Value: " << value << std::endl;
					delete current;
					return;
				}
			}

		}
};

int main()
{
	Tree tree;
	tree.insert(50);
	tree.insert(25);
	tree.insert(100);
	tree.insert(80);
	tree.insert(60);
	tree.insert(90);
	tree.insert(15);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.postOrder();	
	tree.remove(50);
	tree.postOrder();
	return 0;
}