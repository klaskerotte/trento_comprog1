#include <iostream>

struct node {
  int data;

  node *next;
};

int main() {

  // Initialize nodes
  node first;
  node second;
  node third;

  //
  first.data = 10;
  second.data = 20;
  third.data = 312;

  first.next = &second;
  second.next = &third;
  third.next = nullptr;

  node *temp2 = &first;

  while (temp2 != nullptr) {
    std::cout << temp2->data << std::endl;
    temp2 = temp2->next;
  }

  return 0;
}
