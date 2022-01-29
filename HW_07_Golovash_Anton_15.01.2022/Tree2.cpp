#include "Tree2.h"
template<class T>
Tree2<T>::Tree2() : _root(nullptr)
{
    cout << "Constructor default:\t" << endl;
}

template<class T>
Tree2<T>::~Tree2()
{
    if (_root != nullptr)
    {
        cout << "Destructor root:\t" << _root->data << this << endl;
        delete _root;
    }
}

template<class T>
void Tree2<T>::AddIteratively(T data) // Итеративный обход дерева
{
    Node* newNode = new Node;
    newNode->parent = nullptr;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;

    Node** tmp = &_root;
    while (*tmp != nullptr)
    {
        if ((*tmp)->data == data) return; // В дереве нет одинаковых элементов

        if (*tmp != nullptr && (*tmp)->data < data)
        {
            tmp = &(*tmp)->left; // left branch
        }

        if (*tmp != nullptr && (*tmp)->data > data)
        {
            tmp = &(*tmp)->right; // right branch
        }
    }
    *tmp = newNode;
}

template<class T>
void Tree2<T>::AddRecursively(T data) // Рекурсивный обход дерева
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;

    AddRecursivelyNode(&_root, &newNode);
}

template<class T>
void Tree2<T>::AddRecursivelyNode(Node** root, Node** newNode)
{
    if ((*root) != nullptr)
    {
        if ((*root)->data == (*newNode)->data) return;

        if ((*root)->data > (*newNode)->data)
        {
            //(*root)->left = *newNode;
            AddRecursivelyNode(&(*root)->left, &(*newNode));
        }

        if ((*root)->data < (*newNode)->data)
        {
            //(*root)->right = *newNode;
            AddRecursivelyNode(&(*root)->right, &(*newNode));
        }
    }
    else
    {
        *root = (*newNode); // Добавить новый Node
    }
} 

template<class T>
void Tree2<T>::DisplayMaxMin()
{
    DisplayRecursivelyMaxMin(&_root);
}

template<class T>
void Tree2<T>::DisplayRecursivelyMaxMin(Node** root) // max - min
{
    if ((*root) != nullptr)
    {
        DisplayRecursivelyMaxMin(&(*root)->left);
        cout << (*root)->data << "\t";
        DisplayRecursivelyMaxMin(&(*root)->right);
    }
}

template<class T>
void Tree2<T>::DisplayMinMax()
{
    DisplayRecursivelyMinMax(&_root);
}

template<class T>
void Tree2<T>::DisplayRecursivelyMinMax(Node** root) // min - max
{
    if ((*root) != nullptr)
    {
        DisplayRecursivelyMinMax(&(*root)->right);
        cout << (*root)->data << "\t";
        DisplayRecursivelyMinMax(&(*root)->left);
    }
}

template<class T>
T& Tree2<T>::GetRoot()
{
    return _root->data;
}
