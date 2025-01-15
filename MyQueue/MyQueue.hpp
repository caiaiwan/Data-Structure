
#pragma once
#include<stdexcept>

namespace ds {
	template<typename T>
	class MyQueue {

	public:
		
		MyQueue();
		~MyQueue();

		T& front();
		const T& front() const;
		
		T& back();
		const T& back() const;

		bool empty() const;

		size_t size() const;

		void push(T&& data);
		void push(const T& data);

		void pop();

	private:

		struct Node {
			Node(T data) :m_data{ data }, m_next{ nullptr } {}
			T m_data;
			Node* m_next;
		};

		Node* m_front;
		Node* m_tail;
		size_t m_size;


	};
	template<typename T>
	inline MyQueue<T>::MyQueue() :m_front{ nullptr }, m_tail{ nullptr }, m_size{0}
	{
	}

	template<typename T>
	inline MyQueue<T>::~MyQueue()
	{
		while (m_front) {
			Node* temp = m_front;
			m_front = m_front->m_next;
			delete temp;
		}
	}
	
	template<typename T>
	inline T& MyQueue<T>::front()
	{
		if (empty()) {
			throw std::underflow_error{ "Queue is empty." };
		}
		return m_front->m_data;
	}
	
	template<typename T>
	inline const T& MyQueue<T>::front() const
	{
		if (empty()) {
			throw std::underflow_error{ "Queue is empty." };
		}
		return m_front->m_data;
	}
	
	template<typename T>
	inline T& MyQueue<T>::back()
	{
		if (empty()) {
			throw std::underflow_error{ "Queue is empty." };
		}
		return m_tail->m_data;
	}
	
	template<typename T>
	inline const T& MyQueue<T>::back() const
	{
		if (empty()) {
			throw std::underflow_error{ "Queue is empty." };
		}
		return m_tail->m_data;
	}
	
	template<typename T>
	inline bool MyQueue<T>::empty() const
	{
		return m_size == 0;
	}
	
	template<typename T>
	inline size_t MyQueue<T>::size() const
	{
		return m_size;
	}
	template<typename T>
	inline void MyQueue<T>::push(T&& data)
	{
		Node* node{ new Node{std::move(data)} };
		if (empty()) {
			m_tail = node;
			m_front = m_tail;
		}
		else {
			m_tail->m_next = node;
			m_tail = node;
		}
		++m_size;
	}
	template<typename T>
	inline void MyQueue<T>::push(const T& data)
	{
		Node* node{ new Node{data} };
		if (empty()) {
			m_tail = node;
			m_front = m_tail;
		}
		else {
			m_tail->m_next = node;
			m_tail = node;
		}
		++m_size;
	}

	template<typename T>
	inline void MyQueue<T>::pop()
	{
		if (empty()) {
			throw std::underflow_error{ "Queue is empty" };
		}
		Node* temp = m_front;
		m_front = m_front->m_next;
		delete temp;
		if (--m_size == 0) {
			m_front = nullptr;
			m_tail = nullptr;
		}
			
		
	}
}


