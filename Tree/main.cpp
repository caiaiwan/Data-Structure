#include "Tree.hpp"

using namespace ds;

int main()
{
	
	Tree<char> tree{ 9 };
	//分配数据
	tree.setRoot(0);
	tree.assignData(0, 'a');
	tree.assignData(1, 'b');
	tree.assignData(2, 'c');
	tree.assignData(3, 'd');
	tree.assignData(4, 'e');
	tree.assignData(5, 'f');
	tree.assignData(6, 'g');
	tree.assignData(7, 'h');
	tree.assignData(8, 'i');
	
	//分配边
	tree.addChild(3, 6);
	tree.addChild(3, 7);
	tree.addChild(3, 8);
	tree.addChild(1, 3);
	tree.addChild(2, 4);
	tree.addChild(2, 5);
	tree.addChild(0, 1);
	tree.addChild(0, 2);

	tree.print(tree.getNode(0)); 

	std::cout << '\n';
	
	tree.print(tree.getNode(2));

	return 0;
}
