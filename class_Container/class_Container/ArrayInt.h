#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert>

class ArrayInt {
private:
	int m_length;
	int *m_data;//array can chage

public:
  ArrayInt() :m_length(0), m_data(nullptr) {
	
  }

  ArrayInt(int length) :m_length(length) {
	assert(length >= 0);
		
	if (length > 0)
	  m_data = new int[length];
	else
	  m_data = nullptr;
  }

  ~ArrayInt() {
	delete[] m_data;
  }

  void erase() {
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
  }

  //change element(N index)
  int &operator [] (int index) {
	assert(index >= 0 && index < m_length);
	return m_data[index];
  }

  //realloccated() change size array.All element were delet
  void reallocate(int newLength) {
    //delete all element
	  erase();

	if (newLength <= 0)
	  return;

	m_data = new int[newLength];
	m_length = m_length;
  }

  //resize() change size array. All element are save
  void resize(int newLenth) {
	if (newLenth == m_length)
	  return;
      
	if (newLenth <= 0) {
	  erase();
	  return;
	}

	//create new array
	int *data = new int[newLenth];

	//element copy from previous
	if (m_length > 0) {
	  int elementsToCopy = (newLenth > m_length) ? m_length : newLenth;

	  for (int index = 0; index < elementsToCopy; ++index)
	  data[index] = m_data[index];
	}

	//delete old array
	delete[] m_data;

	//new array are using
	m_data = data;
	m_length = newLenth;
  }

  void insertBefore(int value, int index) {
	assert(index >= 0 && index <= m_length);

	//create new element
	int *data = new int[m_length + 1];

	//copy all element
	for (int before = 0; before < index; ++before)
	  data[before] = m_data[before];
  
	//old element delete, new elemet are using
	delete[] m_data;
	m_data = data;
	++m_length;
  }

  void remove(int index) {
	assert(index >= 0 && index < m_length);

	if (m_length == 1) {
	  erase();
	  return;
	}
      
	//new array creat
	int *data = new int[m_length - 1];

	//all element copy uo to delete
	for (int before = 0; before < index; ++before)
	  data[before] = m_data[before];

	//all element copy after deleted element
	for (int after = index + 1; after < m_length; ++after)
	  data[after - 1] = m_data[after];

	//old array delete
	delete[] m_data;
	m_data = data;
	--m_length;
  }

  void insertAtBeginning(int value) {
	insertBefore(value, 0);
  }

  void insertAtEnd(int value) {
	insertBefore(value, m_length);
  }

  int getLength() {
	return m_length;
  }
};

#endif