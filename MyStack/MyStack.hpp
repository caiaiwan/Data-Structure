#pragma once

#include<stdexcept>

namespace ds {

	template<typename T>
	class MyStack {

	public:
		MyStack();
		T top() const;
		void pop();
		void push(T data);
		bool empty() const;
		size_t size() const;
		~MyStack();
	private:

		struct Node
		{
			Node(T data) :m_data{ data }, m_next{ nullptr } {}
			T m_data;
			Node* m_next;
		};

		Node* m_head;
		size_t m_size;
	};

	template<typename T>
	inline MyStack<T>::MyStack() :m_head{ nullptr }, m_size{0}
	{
	}

	template<typename T>
	inline T MyStack<T>::top() const
	{
		if (m_head) {
			return m_head->m_data;
		}
		throw std::underflow_error{ "Stack is empty." };
		
	}

	template<typename T>
	inline void MyStack<T>::pop()
	{
		if (!m_head) {
			throw std::underflow_error{ "Stack is empty." };
		}
		Node* temp = m_head;
		T data = m_head->m_data;
		m_head = m_head->m_next;
		delete temp;
		--m_size;
	}

	template<typename T>
	inline void MyStack<T>::push(T data)
	{
		Node* node = new Node{data};
		node->m_next = m_head;
		m_head= node;
		++m_size;

	}

	template<typename T>
	inline bool MyStack<T>::empty() const
	{
		return m_size == 0;
	}

	template<typename T>
	inline size_t MyStack<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	inline MyStack<T>::~MyStack()
	{
		while (m_head) {
			Node* temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}
		
	}

}