#pragma once

#include <new>
#include <iostream>

template<class T>
class COwnList
{
public:
	COwnList();
	~COwnList();
	void pop_front();
	void push_back(T value);
	void clear();
	int GetSize() { return m_ListSize; }
	T& operator[](int index);
	void push_front(T value);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();


private:

	template<typename D>
	class Node
	{
	public:
		Node* m_NodePointerOnNext;
		D m_NodeValue;

		explicit Node(D value = D(), Node* pNext = nullptr)
		{
			this->m_NodeValue = value;
            try
            {
                this->m_NodePointerOnNext = pNext;
            }
            catch (std::bad_alloc e)
            {
                std::cout << e.what() << std::endl;
            }
		}
	};
	int m_ListSize;
	Node<T>* m_NodeHead;
};


template<typename T>
COwnList<T>::COwnList()
{
    m_ListSize = 0;
    m_NodeHead = nullptr;
}


template<typename T>
COwnList<T>::~COwnList()
{
	clear();
}


template<typename T>
void COwnList<T>::pop_front()
{
	Node<T>* temp = m_NodeHead;
    m_NodeHead = m_NodeHead->m_NodePointerOnNext;
	delete temp;
	m_ListSize--;
}

template<typename T>
void COwnList<T>::push_back(T value)
{
	if (m_NodeHead == nullptr) {
        try
        {
            m_NodeHead = new Node<T>(value);
        }
        catch (std::bad_alloc e)
        {
            std::cout << e.what() << std::endl;
        }
    }
	else
	{
		Node<T>* current = this->m_NodeHead;
		while (current->m_NodePointerOnNext != nullptr)
		{
			current = current->m_NodePointerOnNext;
		}
        try
        {
            current->m_NodePointerOnNext = new Node<T>(value);
        }
        catch (std::bad_alloc e)
        {
            std::cout << e.what() << std::endl;
        }
	}
	m_ListSize++;
}

template<typename T>
void COwnList<T>::clear()
{
	while (m_ListSize)
	{
		pop_front();
	}
}


template<typename T>
T& COwnList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->m_NodeHead;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->m_NodeValue;
		}
		current = current->m_NodePointerOnNext;
		counter++;
	}
}

template<typename T>
void COwnList<T>::push_front(T value)
{
    try
    {
        m_NodeHead = new Node<T>(value, m_NodeHead);
        m_ListSize++;
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
void COwnList<T>::insert(T value, int index)
{

	if (index == 0)
		push_front(value);
	else
	{
		Node<T>* previous = this->m_NodeHead;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->m_NodePointerOnNext;
		}
		try {
            auto *newNode = new Node<T>(value, previous->m_NodePointerOnNext);
            previous->m_NodePointerOnNext = newNode;
            m_ListSize++;
        }
        catch (std::bad_alloc e)
        {
            std::cout << e.what() << std::endl;
        }


	}

}

template<typename T>
void COwnList<T>::removeAt(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* previous = this->m_NodeHead;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->m_NodePointerOnNext;
		}
		Node<T>* toDelete = previous->m_NodePointerOnNext;
		previous->m_NodePointerOnNext = toDelete->m_NodePointerOnNext;
		delete toDelete;
		m_ListSize--;
	}

}

template<typename T>
void COwnList<T>::pop_back()
{
	removeAt(m_ListSize - 1);
}

