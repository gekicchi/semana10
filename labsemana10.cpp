#include <iostream>
#include <queue>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//ejercicio 2
void ImpresionPreOrder(Node* root)
{
	if (root == NULL)
		return;
		
	cout << root->data << " ";
	ImpresionPreOrder(root->left);
	ImpresionPreOrder(root->right);
}

//ejercicio 3
void ImpresionInOrder(Node* root)
{
	if (root == NULL)
		return;
		
	ImpresionInOrder(root->left);
	cout << root->data << " ";
	ImpresionInOrder(root->right);
}

// ejercicio 4
void ImpresionPostOrder(Node* root)
{
	if (root == NULL)
		return;
		
	ImpresionPostOrder(root->left);
	ImpresionPostOrder(root->right);
	cout << root->data << " ";
}

// ejercicio 5
Node* InsertarNodo(Node* root, Node* nuevoNodo)
{
	if (root == NULL)
	{
		root = nuevoNodo;
	}
	else
	{
		if (nuevoNodo->data <= root->data)
			root->left = InsertarNodo(root->left, nuevoNodo);
		else
			root->right = InsertarNodo(root->right, nuevoNodo);
	}
}

// ejercicio 6
Node* BusquedaProfundidad(Node* root, int dat)
{
	if (root == NULL || root->data == dat) // se llego al final de la rama o se encontro un match
		return root;
		
	Node* izq = BusquedaProfundidad(root->left, dat); // buscando por la izquierda de la rama
	if (izq != NULL) // escapando de la recursividad por la izquierda
		return izq;
		
	Node* der = BusquedaProfundidad(root->right, dat); // buscando por la derecha de la rama
	if (der != NULL) // escapando de la recursividad por la derecha
		return der;
		
	return NULL;
}

// ejercicio 7
Node* BusquedaAmplitud(Node* root, int dat)
{
	queue<Node*> q; // cola de puntero a nodo
	q.push(root); // se añade el nodo raiz a la cola
	
	while (!q.empty()) // mientras la cola no esta vacia
	{
		Node* current = q.front(); // se trabaja con el frente de la cola
		q.pop(); // se saca el nodo del frente de la fila
		
		if (current->data == dat) // encontro match
			return current;
			
		if (current->left != NULL) // añade el nodo izquierdo a la cola
			q.push(current->left);
		
		if (current->right != NULL) // añade el nodo derecho a la cola
			q.push(current->right);
	}
	
	return NULL;
}

int main()
{
	srand(time(NULL));
	int random;
	// ejercicio 1
		// creando nodos
	Node* nodo1 = new Node;
	nodo1->data = 1;
	Node* nodo2 = new Node;
	nodo2->data = 2;
	Node* nodo3 = new Node;
	nodo3->data = 3;
	Node* nodo4 = new Node;
	nodo4->data = 4;
	Node* nodo5 = new Node;
	nodo5->data = 5;
	Node* nodo6 = new Node;
	nodo6->data = 6;
	Node* nodo7 = new Node;
	nodo7->data = 7;
	
		// armando arbol
	nodo1->left = nodo2;
	nodo1->right = nodo3;
	
	nodo2->left = nodo4;
	nodo2->right = nodo5;
	
	nodo3->left = nodo6;
	nodo3->right = nodo7;
	
	nodo4->left = nodo4->right = nodo5->left = nodo5->right = nodo6->left = nodo6->right = nodo7->left = nodo7->right = NULL;
	
	//ejercicio 2
	cout << "Prueba ejercicio 2" << endl;
	cout << "Impresion Pre-Order: ";
	ImpresionPreOrder(nodo1);
	cout << endl;

	// ejercicio 3
	cout << endl << "Prueba Ejercicio 3" << endl;
	cout << "Impresion In-Order: ";
	ImpresionInOrder(nodo1);
	cout << endl;

	// ejercicio 4
	cout << endl << "Prueba ejercicio 4" << endl;
	cout << "Impresion Post-Order: ";
	ImpresionPostOrder(nodo1);
	cout << endl;

	// ejercicio 5
	cout << endl << "Prueba Ejercicio 5" << endl;
	int datas[10] = {12, 9, 18, 6, 10, 15, 21, 5, 7, 19};
	Node* rootEj5 = NULL;
	for (int i=0; i<10; i++) // armando arbol
	{
		Node* nodoEj5 = new Node;
		nodoEj5->data = datas[i];
		nodoEj5->left = nodoEj5->right = NULL;
		rootEj5 = InsertarNodo(rootEj5, nodoEj5);
	}
	cout << "Impresion In-Order: ";
	ImpresionInOrder(rootEj5);
	cout << endl;
	cout << "Impresion Pre-Order: ";
	ImpresionPreOrder(rootEj5);
	cout << endl;
	cout << "Impresion Post-Order: ";
	ImpresionPostOrder(rootEj5);
	cout << endl;
	
	// ejercicio 6
	cout << endl << "Prueba Ejercicio 6" << endl;
	for (int i=0; i<4; i++) // buscando 4 numeros random por profundidad
	{
		random = rand()%10;
		cout << "Buscando " << random << " por Profundidad" << endl;
		Node* profundidad = BusquedaProfundidad(nodo1, random);
		if (profundidad != NULL)
		{
			cout << "Nodo Encontrado" << endl;
		}
		else
		{
			cout << "Nodo no Encontrado" << endl;
		}
	}
	
	// ejercicio 7
	cout << endl << "Prueba Ejercicio 7" << endl;
	for (int i=0; i<4; i++) // buscando 4 numeros random por amplitud
	{
		random = rand()%10;
		cout << "Buscando " << random << " por Amplitud" << endl;
		Node* amplitud = BusquedaAmplitud(nodo1, random);
		if (amplitud != NULL)
		{
			cout << "Nodo Encontrado" << endl;
		}
		else
		{
			cout << "Nodo no Encontrado" << endl;
		}
	}
	
	return 0;
}
