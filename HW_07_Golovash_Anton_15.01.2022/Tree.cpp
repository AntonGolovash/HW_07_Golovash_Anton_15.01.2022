#include "Tree.h"
template<class T>
Tree<T>::Tree() : _root(nullptr)
{
    cout << "Constructor default:\t" << endl;
}

template<class T>
Tree<T>::~Tree()
{
    if (_root != nullptr)
    {
        cout << "Destructor root:\t" << _root->data << this << endl;
        delete _root;
    }
}

template<class T>
void Tree<T>::AddIteratively(T data) // ����������� ����� ������
{
    Node* newNode = new Node;
    newNode->parent = nullptr;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;

    Node** tmp = &_root;
    while (*tmp != nullptr)
    {
        if ((*tmp)->data == data) return; // � ������ ��� ���������� ���������

        if (*tmp != nullptr && (*tmp)->data < data)
        {
            tmp = &(*tmp)->left; // left branch
        }

        if (*tmp != nullptr && (*tmp)->data > data)
        {
            tmp = &(*tmp)->right; // right branch
            //parent = tmp;
        }
    }

    *tmp = newNode;
}

template<class T>
void Tree<T>::AddRecursively(T data) // ����������� ����� ������
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;

    AddRecursivelyNode(&_root, &newNode);
}

template<class T>
void Tree<T>::AddRecursivelyNode(Node** root, Node** newNode)
{
    if ((*root) != nullptr)
    {
        if ((*root)->data == (*newNode)->data) return;
        if ((*root)->data > (*newNode)->data) AddRecursivelyNode(&(*root)->right, &(*newNode));
        if ((*root)->data < (*newNode)->data) AddRecursivelyNode(&(*root)->left, &(*newNode));
    }
    else
    {
        *root = (*newNode); // �������� ����� Node
    }
}

template<class T>
void Tree<T>::DisplayMaxMin()
{
    DisplayRecursivelyMaxMin(&_root);
}

template<class T>
void Tree<T>::DisplayRecursivelyMaxMin(Node** root) // max - min
{
    if ((*root) != nullptr)
    {
        DisplayRecursivelyMaxMin(&(*root)->left);
        cout << (*root)->data << "\t";
        DisplayRecursivelyMaxMin(&(*root)->right);
    }
}

template<class T>
void Tree<T>::DisplayMinMax()
{
    DisplayRecursivelyMinMax(&_root);
}

template<class T>
void Tree<T>::DisplayRecursivelyMinMax(Node** root) // min - max
{
    if ((*root) != nullptr)
    {
        DisplayRecursivelyMinMax(&(*root)->right);
        cout << (*root)->data << "\t";
        DisplayRecursivelyMinMax(&(*root)->left);
    }
}

template<class T>
T& Tree<T>::GetRoot()
{
    return _root->data;
}

template<class T>
T& Tree<T>::Previous(T* node)
{
    // TODO: �������� ����� �������� return
}

