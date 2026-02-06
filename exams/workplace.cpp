#include <iostream>

// Enter list
// Exit list
// ID list

struct Node {
  int data;
  Node *next;
};

void disp_list(Node *list) {
  while (list != nullptr) {
    std::cout << list->data << std::endl;
    list = list->next;
  }
}

Node *create_linked_list(int size) {
  std::cout << "creating list of size " << size << std::endl;

  Node *p = new Node;
  Node *head = p;
  p->next = nullptr;

  int counter = 1;
  while (counter < size) {
    std::cout << "iteration: " << counter << std::endl;
    Node *q = new Node;
    q->next = nullptr;
    p->next = q;
    p = q;
    counter++;
  }
  return head;
}

int get_list_size(Node *list) {
  std::cout << "Getting list size" << std::endl;
  int size = 0;
  while (list != nullptr) {
    size++;
    list = list->next;
  }
  return size;
}

int get_ID_count(Node *list, int id) {
  std::cout << "Getting ID-count" << std::endl;

  int count = 0;
  while (list != nullptr) {
    if (list->data == id)
      count++;
    list = list->next;
  }
  std::cout << "Finished with ID count" << std::endl;
  return count;
}

Node *get_entry_exit_diff(Node *entry, Node *exit) {
  std::cout << "Getting entry-exit-difference" << std::endl;

  Node *diff = create_linked_list(get_list_size(entry));
  Node *diffhead = diff;

  while (entry != nullptr) {
    diff->data = (entry->data - exit->data);
    entry = entry->next;
    exit = exit->next;
    diff = diff->next;
  }
  return diff;
}

Node *create_warning_list(Node *id, Node *enter, Node *exit) {
  std::cout << "Creating warning list" << std::endl;

  // Get sizes of the lists
  int sizeID = get_list_size(id);
  int sizeENTER = get_list_size(enter);
  int sizeEXIT = get_list_size(exit);

  std::cout << "There were " << sizeID << " ID`s" << std::endl;
  std::cout << "There were " << sizeENTER << " entries" << std::endl;
  std::cout << "There were " << sizeEXIT << " Exits" << std::endl;

  // Get count of each id-enter in one list

  Node *p = create_linked_list(sizeENTER); // Create empty list
  Node *enter_count_head = p;

  Node *IDhead = id;

  // List of enters per ID
  while (p != nullptr) {
    p->data = get_ID_count(enter, id->data);
    p = p->next;
    id = id->next;
  }

  std::cout << "RESETTING ID-HEAD" << std::endl;
  id = IDhead;
  std::cout << "ID-COUNT FOR ENTRIES DONE " << std::endl;

  Node *q = create_linked_list(sizeEXIT);
  Node *exit_count_head = q;

  // List of exits per ID
  while (q != nullptr) {
    q->data = get_ID_count(exit, id->data);
    q = q->next;
    id = id->next;
  }

  std::cout << "CHECKING DIFFERENCE PER ID" << std::endl;

  // Check the difference for each id
  Node *diff = get_entry_exit_diff(enter, exit);

  return diff;
}

int main() {

  Node *p1 = new Node;
  p1->data = 1;

  Node *p2 = new Node;
  p2->data = 2;

  Node *p3 = new Node;
  p3->data = 3;

  Node *p4 = new Node;
  p4->data = 4;

  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = nullptr;

  Node *entries = create_linked_list(10);
  Node *entryhead = entries;
  while (entries != nullptr) {
    entries->data = std::rand() % 5;
    entries = entries->next;
  }

  Node *exits = create_linked_list(10);
  Node *exithead = exits;
  while (exits != nullptr) {
    exits->data = std::rand() % 5;
    exits = exits->next;
  }

  Node *warninglist = create_warning_list(p1, entryhead, exithead);

  disp_list(entryhead);
  std::cout << "_______________" << std::endl;
  disp_list(exithead);
  std::cout << "_______________" << std::endl;
  disp_list(warninglist);
  std::cout << "_______________" << std::endl;

  delete[] p1;
  delete[] p2;
  delete[] p3;
  delete[] p4;
}
