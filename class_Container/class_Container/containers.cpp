#include <iostream>
#include "ArrayInt.h"

int main() {
  ArrayInt array(10);

  for (int i = 0; i < 10; i++)
    array[i] = i + 1;

  //change size
  array.resize(7);

  //number '15' insert with index '4'
  array.insertBefore(15, 4);

  //element with index '5' delete
  array.remove(5);

  //number '35' '50' add in head and tail
  array.insertAtEnd(35);
  array.insertAtBeginning(50);

  //element outpun
  for (int j = 0; j < array.getLength(); j++)
	std::cout << array[j] << " ";

  return 0;
}