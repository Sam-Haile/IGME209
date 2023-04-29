#pragma once
#include <iostream>
using namespace std;
template<typename T>

class Stack
{

public:
	T* m_data;
	// keeps track of size/top of stack
	int m_head;
	// Size of stack
	int m_size;

	Stack(int size) : m_size(size), m_head(-1), m_data(new T[size]) {}

	Stack(Stack &stack): m_size(stack.m_size), m_head(stack.m_head), m_data(stack.m_data){}

	~Stack() {
		delete[] m_data;
	}

	/// <summary>
	/// Adds new value to stack and double the stack
	/// if there is no space
	/// </summary>
	/// <param name="value"></param>
	void Push(T value) {

		// If there is enough space to hold the data
		if (m_head >= m_size - 1)
		{
			// create new array
			T* new_data = new T[m_size * 2];

			for (int i = 0; i < m_size; i++)
			{
				new_data[i] = m_data[i];
			}

			//delete old array
			delete[] m_data;

			//update pointer
			m_data = new_data;
			m_size *= 2;
		}
		
		// add value to stack
		m_head++;
		m_data[m_head] = value;
	}

	/// <summary>
	/// Read in newest value in stack and remove it
	/// </summary>
	/// <returns>Top value in stack</returns>
	T* Pop() {

		// return last element of stack and remove it
		if (m_head <= -1)
		{
			std::cout << "Stack Underflow Error" << std::endl;
			return nullptr;
		}
		// return most recent data
		T* data = new T(m_data[m_head]);
		// make that data inaccessible 
		m_head--;
		return data;
	}

	/// <summary>
	/// Print all values in stack
	/// </summary>
	void Print() {
		
		// print all values in the stack
		for (int i = 0; i < m_size ; i++)
		{
			if (i <= m_head)
			{
				std::cout << m_data[i] << std::endl;
			}
		}
	}

	/// <summary>
	/// Gets size of elements currently stored
	/// </summary>
	/// <returns> Size of elements in array</returns>
	int GetSize() {

		int size = 0;

		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != nullptr)
			{
				size++;
			}
		}

		return size;
	}

	/// <summary>
	/// Checks whether the stack is empty
	/// </summary>
	bool IsEmpty() {
		return m_head <= -1;
	}


};

