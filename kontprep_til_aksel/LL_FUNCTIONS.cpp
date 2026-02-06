#include "LL_FUNCTIONS.h"
#include <cstdlib>
#include <iostream>

node *createlist(int size) {

  // Definerer første node av listen
  node *head = new node{std::rand() % (10 + 1), nullptr};

  // Peker på første node
  node *temp = head;

  // Lager en ny node og kobler noden før til den frem til listen er av
  // størrelse "size"
  for (int i = 1; i < size; i++) {
    node *p = new node{std::rand() % (10 + 1), nullptr}; // Lager ny node
    temp->next = p; // Setter forrige node sin "neste" til den nye noden
    temp = p;       // Hopper frem til nyeste node
  }
  return head; // Returnerer første node ut
}

void printLL(node *head) {
  node *tmp = head; // Peker nå på første node
  std::string out = "[";
  while (tmp !=
         nullptr) { // Så lenge man peker på en node som eksisterer så legger du
                    // til i outputstrengen og går videre til neste node
    out += std::to_string(tmp->data);
    out += " ";
    tmp = tmp->next;
  }
  out += "]";
  std::cout << "List: " << out << std::endl; // Print listen
}

node *array2list(int *array, int size) {
  node *head =
      new node{array[0], nullptr}; // Tar første element av arrayen og lager en
                                   // node, initialiserer listen med andre ord

  node *tmp = head; // Pek på første node

  for (int i = 1; i < size;
       i++) { // For hvert element i arrayen (bortsett fra første) lag en ny
              // node og koble noden før til den nye
    node *p = new node{array[i], nullptr};
    tmp->next = p;
    tmp = p; // Hold styr på "siste" node
  }
  return head; // Spytt ut første node
}

int *createIDs(int size) {
  int *arr = new int[size]; // Alloker minne for "size" integers

  // Fyll hver integer som er lagd med tallet "i". [0 1 2 3 ..... size]
  for (int i = 0; i < size; i++)
    arr[i] = i;

  return arr; // Spytt ut arrayen du har laget
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
  // Lykke til. Spør hvis du faktisk lurer

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
