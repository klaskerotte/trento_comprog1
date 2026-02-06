#include <cstdlib>
#include <ctime>
#include <iostream>

int *create_array(int &size) {
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  size = std::rand() % 17;

  int *arr = new int[size];

  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % 11;

  return arr;
}

struct Node {

  int data;

  Node *prev;
  Node *next;
};

Node *create_dub_list(int *arr, int size) {
  if (size == 0)
    return nullptr;

  Node *head = new Node;
  head->data = arr[0];
  head->prev = nullptr;
  head->next = nullptr;

  Node *current = head;

  for (int i = 1; i < size; i++) {
    Node *node = new Node;

    node->data = arr[i];
    node->prev = current;
    node->next = nullptr;
    current->next = node;

    current = node;
  }
  return head;
}

void display_list_forwards(Node *&ptr) {
  int index = 0;

  Node *head = ptr;
  while (ptr != nullptr) {
    std::cout << "value at index = " << index << " is " << ptr->data
              << std::endl;
    ptr = ptr->next;
    index++;
  }
  ptr = head;
}

Node *insert_Node(int position, int &size, Node *doublelist, int value) {
  Node *head = doublelist;

  Node *temp = new Node;
  temp->data = value;
  temp->prev = nullptr;
  temp->next = nullptr;

  if (size == 0)
    head = temp;

  if ((position == 0) || (doublelist == nullptr)) {
    temp->next = doublelist;
    if (doublelist != nullptr)
      doublelist->prev = temp;
    head = temp;
  }

  else if (position > size) {
    std::cout << "Position greater than list size, appending to end of list"
              << std::endl;
    while (doublelist->next != nullptr) {
      doublelist = doublelist->next;
    }
    temp->prev = doublelist;
    doublelist->next = temp;
  }

  else if (position == size) {
    std::cout << "Position equal to size" << std::endl;
    while (doublelist->next != nullptr)
      doublelist = doublelist->next;
    if (doublelist->prev != nullptr) {
      doublelist->prev->next = temp;
      temp->prev = doublelist->prev;
      temp->next = doublelist;
      doublelist->prev = temp;
    } else {
      std::cout << "Oh shit you done goofed" << std::endl;
    }

  } else {
    std::cout << "Position less than size " << position << std::endl;

    for (int i = 0; i < position; i++) {
      doublelist = doublelist->next;
    }
    temp->prev = doublelist->prev;
    doublelist->prev->next = temp;
    temp->next = doublelist;
    doublelist->prev = temp;
  }
  size++;
  return head;
}

int main() {

  // Create array of random size less than 16 with random values.
  int size;
  int *arr = create_array(size);
  std::cout << "SIZE = " << size << std::endl;

  for (int i = 0; i < size; i++)
    std::cout << arr[i] << std::endl;

  std::cout << "_________________________" << std::endl;

  // Create double linked list
  Node *dlist = create_dub_list(arr, size);

  // Display double linked list
  display_list_forwards(dlist);

  // Insert element at position p
  std::cout << "--------------- Inserting element at position p --------- "
            << std::endl;

  std::cout << "_____________________" << std::endl;
  dlist = insert_Node(std::rand() % 10, size, dlist, std::rand());

  // Display again
  display_list_forwards(dlist);

  // Delete double linked list and array
  Node *temp;
  while (dlist != nullptr) {
    temp = dlist;
    dlist = dlist->next;
    delete temp;
  }

  delete[] arr;

  return 0;
}
