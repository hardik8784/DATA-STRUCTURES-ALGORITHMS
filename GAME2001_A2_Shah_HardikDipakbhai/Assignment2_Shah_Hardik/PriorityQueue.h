#pragma once

#include "PriorityQueueDoublyLinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class PriorityQueue 
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {};
	// Priority queue functions

	void push(T val, int priority)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push(val, priority);
		}
		else
		{
				LinkIterator<T> it;
				it = m_elements.Begin();

				while (it.isValid())		// Move iterator to the correct spot (or null)
				{
					if (priority < it.getPriority())
					{
						break;
					}

					it++;
				}

				if (it.isValid())
				{
					m_elements.Insert_Before(it, val, priority);
				}
				else
				{
					m_elements.Push(val, priority);
				}
			
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front() 
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}

	T& back() 
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}
	// Helper functions
	int GetSize() 
	{
		return m_elements.GetSize();
	}

	int GetMaxSize() 
	{
		return m_size;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize() 
	{
		assert(m_size > 0);
		m_size = m_size;
	}

	LinkedList<T>* GetElements() {
		return &m_elements;
	}

	friend ostream& operator<<(ostream& os, PriorityQueue<T>& Elements) {
		LinkIterator<T> it;

		it = Elements.GetElements()->Begin();

		while (it.isValid()) {
			os << " Data: " << *it << " -------";
			os << " Priority: " << it.getPriority() << endl;

			it++;
		}

		return os;
	}

private:
	LinkedList<T> m_elements;
	int m_size;
};