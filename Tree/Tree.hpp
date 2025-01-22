#pragma once

#include <iostream>
#include<stdexcept>
namespace ds {

	//链表节点
	template<typename T>
	struct ListNode
	{
		ListNode(T d) :data{d},next { nullptr } {}

		T data;
		ListNode* next;
	};

	//树节点
	template<typename T>
	struct TreeNode {

		TreeNode() :data{},children { nullptr } {}
		
		void addChild(TreeNode<T>* node) {

			ListNode< TreeNode<T>* >* childNode = new ListNode< TreeNode<T>* >{ node };
			if (!children) {
				children = childNode;
			}
			else {
				childNode->next = children;
				children = childNode;
			}
		}

		ListNode< TreeNode<T>* >* children;
		T data;
	};


	//树
	template<typename T>
	class Tree {

	public:
		Tree(int NodeNums);
		~Tree();
		TreeNode<T>* getNode(int id) const;
		void setRoot(int id);
		void addChild(int pid, int cid);
		void assignData(int id , T data);
		void print(TreeNode<T>* node);
		void deleteNode(TreeNode<T>* node);

	private:
		TreeNode<T>* root;
		TreeNode<T>* nodes;
		int nodeCounts;
	};

	//树的成员函数定义
	

	template<typename T>
	inline Tree<T>::Tree(int NodeNums) :root{ nullptr }, nodes{ new TreeNode<T>[NodeNums] }, nodeCounts{NodeNums}
	{
		
	}

	template<typename T>
	inline Tree<T>::~Tree()
	{
		deleteNode(root);
		delete[] nodes;
	}

	template<typename T>
	inline void Tree<T>::deleteNode(TreeNode<T>* node)
	{
		if (!node) return;
		ListNode<TreeNode<T>*>* child = node->children;
		while (child) {
			deleteNode(child->data);
			ListNode<TreeNode<T>*>* temp = child; 
			child = child->next;
			delete temp;
		}
	}


	template<typename T>
	inline TreeNode<T>* Tree<T>::getNode(int id) const
	{
		if (id < 0 || id >= nodeCounts) throw std::range_error{ "No such node" };
		return &nodes[id];
	}

	template<typename T>
	inline void Tree<T>::setRoot(int id)
	{
		root = getNode(id);
	}

	template<typename T>
	inline void Tree<T>::addChild(int pid, int cid)
	{
		TreeNode<T>* parentNode = getNode(pid);
		TreeNode<T>* childNode = getNode(cid);
		parentNode->addChild(childNode);
	}

	template<typename T>
	inline void Tree<T>::assignData(int id, T data)
	{
		nodes[id].data = data;
	}

	template<typename T>
	inline void Tree<T>::print(TreeNode<T>* node)
	{
		if (!node) {
			node = root;
		}
		std::cout << node->data;
		ListNode<TreeNode<T>*>* temp = node->children;
		while (temp) {
			print(temp->data);
			temp = temp->next;
		}

	}

	

}

