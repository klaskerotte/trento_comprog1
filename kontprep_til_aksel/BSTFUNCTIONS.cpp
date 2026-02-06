#include "BSTFUNCTIONS.h"
#include <cstdlib>
#include <iostream>

// Dette er en sourcefil
// Funksjonssignaturene som er skrevet opp i "BSTFUNCTIONS.h" er programmert
// her. "BSTFUNCTIONS.h" er på en måte hvordan disse funksjonene fungerer kort
// fortalt "BSTFUNCTIONS.cpp" er funksjonenes logikk.
//
// I mainfilen "BST2.cpp" er headerfilen "BSTFUNCTIONS.h" inkludert, men
// "BSTFUNCTIONS.cpp" må kompileres sammen med mainfilen
//

int *createarray(int size) {

  // Sett av nok minne til å holde alle integersa dine. Se på dette som "size"
  // antall tomme prikker i lufta.
  int *array = new int[size];

  // Sett in et random tall i hver index av arrayen
  for (int i = 0; i < size; i++)
    array[i] = std::rand() % (10 + 1);

  // Spytt ut den lagde arrayen din
  return array;
}

void printarray(int *array, int size) {

  // Lag en tekststreng
  std::string out = "[";

  // For hvert element i arrayen sett inn tallet i strengen din
  for (int i = 0; i < size; i++) {
    out += std::to_string(array[i]);
    if (i != size - 1)
      out += " ";
  }
  out += "]";
  std::cout << out << std::endl;
  std::cout << "\n" << std::endl;
}

node *insert_element(node *tree, int value) {

  // Hvis du ikke peker på en node, lag en med verdien av interesse
  if (!tree)
    return new node{value, nullptr, nullptr};

  // Hvis verdien er større/mindre enn nodeverdien du ser på, gå til
  // høyre/venstre og prøv der.
  if (value > tree->data)
    tree->right = insert_element(tree->right, value);
  else
    tree->left = insert_element(tree->left, value);

  // Spytt ut treet du har laget med den innsatte verdien
  return tree;
}

node *createBST(int *array, int size) {
  // Hvis arrayen din ikke eksisterer returner nada niks null
  if (size == 0)
    return nullptr;

  // Lag første node med første verdien i arrayen
  node *tree = new node{array[0], nullptr, nullptr};

  // For hvert element i arrayen din, sammenlign med treet du har bygd og sett
  // inn på riktig plass. Se "insert_element" funksjonen over
  for (int i = 1; i < size; i++) {
    tree = insert_element(tree, array[i]);
  }

  // Returner det lagde treet
  return tree;
}

void fancyprintBST(node *tree, int depth = 0) {
  // Hvis du peker på ingenting returner ingenting og avslutt funksjonen
  if (!tree)
    return;

  // Start en rekursivitet hvor du går til høyre frem til du når slutten og
  // print ut
  fancyprintBST(tree->right, depth + 1);
  for (int i = 0; i < depth; i++) {
    std::cout << "   ";
  }

  // Print ut verdien av interesse
  std::cout << tree->data << std::endl;

  // Start en rekursivitet hvor du går til venstre frem til du når slutten.
  fancyprintBST(tree->left, depth + 1);
}
