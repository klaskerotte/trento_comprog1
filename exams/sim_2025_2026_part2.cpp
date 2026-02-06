#include <cstdlib>
#include <iostream>

struct Node {
  int data;

  Node *next;
  Node *prev;
};

void displayarray(int *&arr, int size) {
  std::string disp = "[";
  std::cout << "\nThe array is: " << std::endl;
  for (int i = 0; i < size; i++) {
    disp += std::to_string(arr[i]);
    disp += ' ';
  }
  disp += "]\n";
  std::cout << disp << std::endl;
}

int *create_rand_array(int size) {

  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = std::rand();
  return arr;
}

Node *create_dlist(int *&arr, int size) {
  //  std::cout << "\n Creating list" << std::endl;

  Node *dlist = new Node;
  Node *head = dlist;
  dlist->data = arr[0];
  dlist->next = nullptr;
  dlist->prev = nullptr;
  // std::cout << "First node " << dlist << std::endl;
  // std::cout << "First address " << dlist->data << std::endl;
  // std::cout << "First next " << dlist->next << std::endl;
  // std::cout << "First prev " << dlist->prev << std::endl;

  for (int i = 1; i < size; i++) {
    //    std::cout << "Initialized Node number " << i << std::endl;
    Node *ptr = new Node;
    ptr->data = arr[i];
    ptr->prev = dlist;
    ptr->next = nullptr;
    dlist->next = ptr;
    dlist = ptr;
    //   std::cout << "Node address = " << ptr << std::endl;
    //   std::cout << "Node data = " << ptr->data << std::endl;
    //   std::cout << "Node prev = " << ptr->prev << std::endl;
    //   std::cout << "Node next = " << ptr->next << std::endl;
  }
  return head;
}

void traverse_forward(Node *&list) {
  Node *head = list;

  int index = 0;
  //  std::cout << "\nTraversing list" << std::endl;
  while (list != nullptr) {
    //   std::cout << "Pointing to: " << list << std::endl;
    std::cout << "Data stored at index: " << index << " is equal to "
              << list->data << std::endl;
    list = list->next;
    index++;
    // std::cout << "Now pointing to: " << std::endl;
  }
  // Reset to headpointer
  list = head;
}

void insert_element(int position, Node *&list, int value) {
  // Grab head
  Node *head = list;

  // Make indexcounter
  int index = 0;

  // Traverse until before position or end of list
  while ((list->next != nullptr) && (index < position)) {
    list = list->next;
    index++;
  }

  // Initializa new node and give it desired value
  Node *ptr = new Node;

  ptr->data = value;
  ptr->prev = nullptr;
  ptr->next = nullptr;

  if (position == 0) { // If new node is to be first
    list->prev = ptr;  // Wire the head to the new node backwards
    ptr->next = list;  // Wire new node to the the head forwards

  } else if (list->next == nullptr) { // If node at the end of the list
    list->next = ptr;                 // Wire the end-node to new node forwards
    ptr->prev = list;                 // Wire new node to endpoint backwards
  } else {
    list->next->prev = ptr; // Traversed index +1 points to new node bw
    ptr = list->next;       // New node points to the traversed index +1 fwd
    list->next = ptr;       // Traversed index now points to new node
    ptr->prev = list;       // New node points to traversed index bw
  }

  // Reset list
  if (position == 0) {
    list = ptr;
  } else {
    list = head;
  }
}

int main() {

  // Seed
  std::srand(time(NULL));

  // Random size of array, max 16.
  int size = std::rand() % (16 + 1);
  while (size == 0)
    size = std::rand() % (16 + 1);

  // if (size <= 0) {
  // std::cout << "Size of array less than or equal to 0, run script again"
  //           << std::endl;
  // return 0;}

  // Create the array of random integers
  int *randarray = create_rand_array(size);
  displayarray(randarray, size);

  // Create a doubly linked list with the values from the array
  Node *dlist = create_dlist(randarray, size);
  Node *head = dlist;

  delete[] randarray;

  // Traverse the list

  traverse_forward(dlist);
  std::cout << "____________________________________\n" << std::endl;

  // Insert element at position X
  insert_element(0, dlist, 10);

  traverse_forward(dlist);

  Node *temp = head;
  while (temp->next != nullptr) {
    Node *next = temp->next;
    delete temp;
    temp = next;
  }
  head = nullptr;

  return 0;
}
