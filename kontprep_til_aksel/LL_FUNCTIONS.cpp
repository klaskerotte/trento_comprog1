#include "LL_FUNCTIONS.h"
#include <cstdlib>
#include <iostream>

node *createlist(int size) {
  node *head = new node{std::rand() % (10 + 1), nullptr};

  node *temp = head;
  for (int i = 1; i < size; i++) {
    node *p = new node{std::rand() % (10 + 1), nullptr};
    temp->next = p;
    temp = p;
  }
  return head;
}

void printLL(node *head) {
  node *tmp = head;
  std::string out = "[";
  while (tmp != nullptr) {
    out += std::to_string(tmp->data);
    out += " ";
    tmp = tmp->next;
  }
  out += "]";
  std::cout << "List: " << out << std::endl;
}

node *array2list(int *array, int size) {
  node *head = new node{array[0], nullptr};

  node *tmp = head;
  for (int i = 1; i < size; i++) {
    node *p = new node{array[i], nullptr};
    tmp->next = p;
    tmp = p;
  }
  return head;
}

int *createIDs(int size) {
  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = i;
  return arr;
}

int *create_entries(int IDcount, int size) {
  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % (IDcount + 1);
  return arr;
}

int *create_exits(int IDcount, int size) {
  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % (IDcount + 1);
  return arr;
}

node *create_discrepancyLL(node *LLID, node *LL1, node *LL2) {

  node *DLL = nullptr;
  node *DLLhead = nullptr;

  node *tmpID = LLID;
  while (tmpID != nullptr) {
    int sum = 0;

    node *tmp1 = LL1;
    while (tmp1 != nullptr) {
      if (tmp1->data == tmpID->data) {
        sum++;
      }

      tmp1 = tmp1->next;
    }
    node *tmp2 = LL2;
    while (tmp2 != nullptr) {
      if (tmp2->data == tmpID->data) {
        sum--;
      }
      tmp2 = tmp2->next;
    }

    if (sum != 0) {
      node *n = new node{tmpID->data, nullptr};
      if (DLLhead == nullptr) {
        DLLhead = n;
        DLL = n;
      } else {
        DLL->next = n;
        DLL = n;
      }
    }

    tmpID = tmpID->next;
  }
  return DLLhead;
}
