#include <cstdlib>
#include <iostream>

struct Node {
  int data;
  Node *next;
};

Node *create_list(int size) {

  if (size == 0)
    return nullptr;

  Node *ptr = new Node;
  ptr->data = std::rand() % (10 + 1);
  ptr->next = nullptr;
  Node *head = ptr;

  for (int i = 1; i < size; i++) {
    Node *q = new Node;
    q->data = std::rand() % (10 + 1);
    q->next = nullptr;
    ptr->next = q;
    ptr = q;
  }
  return head;
}

int get_list_size(Node *list) {
  int size = 0;
  while (list != nullptr) {
    size++;
    list = list->next;
  }
  return size;
}

void display_list(Node *list) {
  while (list != nullptr) {
    std::cout << list->data << std::endl;
    list = list->next;
  }
}

void append_on_list(Node *&list, int value) {

  if (!list) {
    Node *p = new Node;
    p->next = nullptr;
    p->data = value;
  } else {
    Node *q = new Node;
    q->data = value;
    q->next = nullptr;
    list->next = q;
  }
}

Node *create_interleaved_list(Node *list1, Node *list2) {

  // Get size of both lists
  int size1 = get_list_size(list1);
  int size2 = get_list_size(list2);

  int totalsize = size1 + size2;
  std::cout << "Total size is :" << totalsize << std::endl;

  Node *p = new Node;
  p->next = nullptr;
  Node *head = p;

  bool flag = true;
  int counter = 0;
  while (((list1 != nullptr) || (list2 != nullptr)) && (counter < totalsize)) {
    if (flag) {
      append_on_list(list1, list1->data);
      list1 = list1->next;
      flag = !flag;
      counter++;

    } else if (!flag) {
      append_on_list(list2, list2->data);
      list2 = list2->next;
      flag = !flag;
      counter++;
    }
  }

  return head;
}

int main() {

  Node *list1 = create_list(3);
  Node *list2 = create_list(3);

  std::cout << "___________________________" << std::endl;
  display_list(list1);
  std::cout << "___________________________" << std::endl;
  display_list(list2);
  std::cout << "___________________________" << std::endl;

  std::cout << "___________________________" << std::endl;
  Node *interleaved = create_interleaved_list(list1, list2);
  display_list(interleaved);

  return 0;
}
