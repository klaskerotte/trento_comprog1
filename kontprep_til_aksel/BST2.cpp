#include "BSTFUNCTIONS.h" // Inkluderer funksjonene deklarert i BSTFUNCTIONS.h som er programmert i BSTFUNCTIONS.cpp
#include <cstdlib>
#include <iostream>

int main() {
  // Setter random seed, hvilket betyr at std::rand() funksjonen faktisk lager
  // forskjellige tall
  std::srand(time(nullptr));

  // Definerer størrelsen på arrayen som genereres
  int arrsize = 20;

  // Genererer en array med random tall fra 0 til 10 (se BSTFUNCTIONS.cpp)
  int *arr = createarray(arrsize);

  // Printer arrayen
  printarray(arr, arrsize);

  // Lager et binært søketre utifra arrayen generert tidligere
  node *tree = createBST(arr, arrsize);

  // Viser frem treet på en kul måte
  fancyprintBST(tree, 0);

  return 0;
}
