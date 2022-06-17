#pragma once
#include <array>
#include <stdexcept>

template <typename T>
class LinkedListArray
{
	long long current_size;
	std::array<T, 10> container;
	
	short insert_status;
	short erase_status;
public:
	const short INSERT_STATUS_NIL = -1;
	const short INSERT_STATUS_OK = 0;
	const short INSERT_STATUS_LIST_IS_FULL = 1;
	const short INSERT_STATUS_INVALID_INDEX = 2;

	const short ERASE_STATUS_NIL = -1;
	const short ERASE_STATUS_OK = 0;
	const short ERASE_STATUS_INVALID_INDEX = 0;

	LinkedListArray();
	LinkedListArray(long size);
	
	LinkedListArray(const LinkedListArray& other);
	LinkedListArray(LinkedListArray&& other);

	bool operator==(const LinkedListArray& other);
	T operator[](const long long index);


	//Pre-condition: LinkedList has a free space from elem
	//Post-condition: elem was added to LinkedList
	void push_back(T elem);

	//Pre-condition:  LinkedList has a free space from elem. 
	//				  Given a correct index
	//Post-condition: Elem was added to LinkedList
	void insert_at(T elem, long long index);

	//Pre-condition: given a correct index
	//Post-condition: elem at given index was removed to LinkedList
	//				  and rest of lists was moved <----
	void erase(long long index);

	//Pre-condition:
	//Post-condition: returns an element at index
	const long at(long long index);

	//Pre-condition:
	//Post-condition: return current_size of array
	const long size();

	const short get_insert_status();
	const short get_erase_status();
};

template<typename T>
LinkedListArray<T>::LinkedListArray() : insert_status(-1), current_size(0)
{
	for (long long i = 0; i < 10; i++)
		container[i] = -1;
}

template<typename T>
LinkedListArray<T>::LinkedListArray(long size) : insert_status(-1), current_size(0)
{
	delete[] container;
	container = std::array<T, size>;
	for (long long i = 0; i < 10; i++)
		container[i] = -1;
}

template<typename T>
LinkedListArray<T>::LinkedListArray(const LinkedListArray& other)
{
	if(container.max_size() != other.container.max_size())
		throw std::invalid_argument("LinkedListArray must have equals size!");

	for (long long i = 0; i < other.current_size; i++)
		container[i] = other.container[i];
};


template<typename T>
LinkedListArray<T>::LinkedListArray(LinkedListArray&& other)
{
	if (container.max_size() != other.container.max_size())
		throw std::invalid_argument("LinkedListArray must have equals size!");

	container = other.container;
	
	for (long long i = 0; i < other.container.max_size(); i++)
		other.container[i] = -1;

	other.current_size = 0;
};

template<typename T>
inline void LinkedListArray<T>::push_back(T elem)
{
	if (current_size == container.max_size())
	{
		insert_status = INSERT_STATUS_LIST_IS_FULL;
	}
	else {
		container[current_size] = elem;
		current_size++;
		insert_status = INSERT_STATUS_OK;
	}
}

template<typename T>
inline void LinkedListArray<T>::insert_at(T elem, long long index)
{
	if (index < 0 || index > container.max_size())
	{
		insert_status = INSERT_STATUS_INVALID_INDEX;
		return;
	}

	if (current_size == container.max_size())
	{
		insert_status = INSERT_STATUS_LIST_IS_FULL;
	}
	else {
		for (long long i = current_size; i > index ; i--)
			container[i] = container[i-1];

		container[index] = elem;

		current_size++;
		insert_status = INSERT_STATUS_OK;
	}
};

template<typename T>
inline void LinkedListArray<T>::erase(long long index)
{
	if (index < 0 || index > container.size())
	{
		erase_status = ERASE_STATUS_INVALID_INDEX;
		return;
	}
		
	for (long long i = index; i < current_size - 1; i++)
		container[i] = container[i + 1];

	current_size--;
	erase_status = ERASE_STATUS_OK;
};

template<typename T>
const long LinkedListArray<T>::at(long long index)
{
	if (index < 0 || index > container.size())
		throw std::invalid_argument("Index must be equal or greater than zero and less than max LinkedListArray size");
	return container[index];
};

template<typename T>
const long LinkedListArray<T>::size()
{
	return current_size;
};

template<typename T>
const short LinkedListArray<T>::get_insert_status()
{
	return insert_status;
};

template<typename T>
const short LinkedListArray<T>::get_erase_status()
{
	return erase_status;
};

template<typename T>
bool LinkedListArray<T>::operator==(const LinkedListArray& other)
{
	for (long long i = 0; i < current_size; i++)
		if (container[i] != other.container[i])
			return false;
	return true;
}

template<typename T>
T LinkedListArray<T>::operator[](const long long index)
{
	auto tmp = container[index];
	return container[index];
};
