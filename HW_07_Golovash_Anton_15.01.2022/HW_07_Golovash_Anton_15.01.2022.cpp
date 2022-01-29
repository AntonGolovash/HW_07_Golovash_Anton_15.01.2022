#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
#include "Tree2.h"
#include "Tree2.cpp"

int main()
{
	Tree2<int> tree2;
	tree2.AddRecursively(5);
	tree2.AddRecursively(4);
	tree2.AddRecursively(3);
	tree2.AddRecursively(2);
	tree2.AddRecursively(1);
	tree2.AddRecursively(6);
	tree2.AddRecursively(7);
	tree2.AddRecursively(8);
	tree2.AddRecursively(9);

}