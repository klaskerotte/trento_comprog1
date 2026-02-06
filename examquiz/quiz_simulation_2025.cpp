#include <iostream>

/* Exam simulation 2025 questions*/

// Task 1

/*
void print(int m, int n) {
  while (m <= n) {
    std::cout << m << " ";
    ++m;
    print(m, n);
    break;
  }
}

int main() {
  int n, m;
  std::cout << "m? n? (m,n >=0): ";
  std::cin >> m >> n;
  std::cout << "print(" << m << ", " << n << ") = \n";
  print(m, n);
  return 0;
}
*/

// Task 2
// True or false

/*
 * 1 --> True n1 and n2 are global.
 * 2 --> Function declarations are mandatory (True)
 * 3 --> pow(x,y) is a function provided by the cmath library (True)
 * 4 --> The use of functions decrease the program readability since the code is
 * split between files(False)
 * 4 --> In parameter passing by value there is a
 * duplication of parameters (True)
 * 5 --> Libraries are a set of functions that
 * need to be compiled (False)
 */

// Task 3
// What is the output?

/*
int main() {
  int i = 0, j = 1; // Init i and j;
  int *p, *q;       // Declare pointers *p and *q
  p = &i;           // p now points to i
  q = &j;           // q now points to j
  *p = *q;          // Value of object pointed to by p (i) is now the value of
the object pointed to by q i = 1 i++;              // i = 1 + 1 = 2 j--; // j =
1 - 1 = 0 q = p;            // pointer q is now pointing to the same object as
pointer p (i)
  (*p)++;           // The value of the object pointed to by p is increased by
1, i = 2 + 1 = 3
  (*q)++;           // The value of the object pointed to by q is increased by
1, i = 3 + 1 = 4 i++;              // i is incremented by 1, i = 4 + 1 = 5 j--;
// j is decremented by 1, j = 0 - 1 = - 1 std::cout << "i = " << i << std::endl;
// 5 std::cout << "j = " << j << std::endl;   // -1 std::cout << "*p = " << *p
<< std::endl; // 4 std::cout << "*q = " << *q << std::endl; // 4 std::cout <<
"&i = " << &i << std::endl; // addressi std::cout << "p = " << p << std::endl;
// addressi std::cout << "q = " << q << std::endl;   // addressi
}
*/

// Task 4
// Match the definitions

// It is declarative programming --> Functional programming
// It offers features like abstraction encapsulation.... --> Object-oriented
// programming It is interpreted -->Scripting
// A program is a set of sentences in logical form, expressing facts, rules and
// questions --> Logic programming A program is structured in instructions and
// functions --> Procedural programming It is machine dependent --> Assembly
// programming The program flow is driven by events such as user actions.... -->
// Event driven programming
//

// Task 5
// Convert -5.25 in floating point with 32 bits (single precision), clearly show
// S, EXP, Mantissa

// 32 bit floating point can be represented with:
// [Sign bit (1 bit) | Exponent (8 bits) | Fraction/Mantissa (23 bits)]
//
// In this case our sign is negative --> S = 1
// Then we compute the absolute value to binary
//      - integer part = 5 --> 101
//      - Fractional part:
//          - 0.25 --> 0.25 * 2 = 0.5 -> 0
//          - 0.2  -- > 0.5 * 2 = 1 -> 0
//      - Making the fractional part --> 01
//
// Then we combine the integer and fractional part
//      - 5.25 --> 101,01_{2}
//
// Then we normalize the binary number by moving the binary point and using the
// exponent (2)j 101.01_{2} = 1.0101 x 2^2
//
// For single precision the field uses a bias of 127
// This result in the exponent being 127+2 = 129
// 129_{10} = 10000001
// Determining the mantissa --> drop the leading 1 from the normalized binary
// number and pad to 23 bits Mantissa = 01010000000000000000000 (0100 padded
// with 19 zeros)
//
// Assemble final conversion:
// [1 | 10000001 | 01010000000000000000000]

// Task 6
// ASCII and char

/*
int main() {
  char c = 'a'; // c = 97
  c += 3;       // c = 100

  std::cout
      << "c++ = " << c++
      << std::endl; // char c = 100, display 100 and then increment c to 101

  std::cout << ((c >= 'a') && (c <= 'z'))
            << std::endl; // c(101) >= a(97) is true c(101) <= z(122) is true
                          // --> meaning that this outputs 1 as a bool.

  std::cout << ((c >= '0') && (c <= '9'))
            << std::endl; // Outputs 0 because 'a' >= '9'

  c = 65; // makes c into 'A'

  std::cout << "c = " << c << std::endl; // c = A

  std::cout << ((c >= 'A') && (c <= 'Z'))
            << std::endl; // Outputs 1 since c = 'A' and 'A' <= 'Z'

  c -= 'a' - 'A' - 3; // c =65 - (97-65-3) = 65-29 = 36 = '$'

  std::cout << "c = " << c << std::endl; // c = '$' // idk

  c = 142 / 2 + c;                       // 71+36 = 107 = 'k'
  std::cout << "c = " << c << std::endl; // id

  return 0;
}
*/

// Task 7
// Print statements and referred declaration scope

/*
// global declaration
int x = 0;

void f1() { // declaration f1

  x = x + 10;
  std::cout << "f1 x = " << x << "\n"; // global // f1 x = 12

  x = 5;
}

void f2() { // declaration f2

  int x = 10;

  f1();

  std::cout << "f2 x = " << x << "\n" << std::endl; // f1 // f2 x = 10
}

int main() {
  x += 2; // global

  std::cout << "main 1x = " << x << "\n"; // global // main1x = 2

  f2();
  std::cout << "main 2x = " << x << "\n"; // f1 // main2x = 5

  return 0;
}
*/

// Task 8
// Print the output of type operations (write the value of given pieces of code)

/*
int main() {
  int b;
  int a = 7;
  std::cout << a++ << std::endl; // output = 7

  a = 11;
  std::cout << ++a << std::endl; // output = 12

  a = 12, b;
  b = a++;
  std::cout << b << "," << a << std::endl; // output = 12, 13

  a = 9, b;
  b = ++a;
  std::cout << b << "," << a << std::endl; // 10, 10

  a = 5, b;
  a++;
  b = ++a;
  std::cout << b << "," << a << std::endl; // 7, 7

  a = 2, b;
  a++;
  b = a--;
  std::cout << b << "," << a << std::endl; // 3,2

  return 0;
}
*/

// Task 9
// Print statements for 2dim array

/*
int main() {
  const int d1 = 2;
  const int d2 = 3;

  int i = 1, j = 2;

  int mat[d1][d2] = {{1, 2, 3}, {4, 5, 6}};

  std::cout << "(*(mat+1) == mat[1]): " << (*(mat + 1) == mat[1])
            << std::endl; // True --> 1 (*(mat +1) points to the second row, so
does mat[1]

  std::cout << "mat[" << i << "," << j << "] = " << mat[i][j] << std::endl; // 6

  std::cout << "(mat[1] == &mat[1][1]): " << (mat[1] == &mat[1][1])
            << std::endl; // False --> 0 mat[1] decays to &mat[1][0]

  std::cout << "mat[i][j++] = " << mat[i][j++] << std::endl; // 6

  return 0;
}
*/

// Task 10
// Printed value in LinkedList

struct node {
  int data;
  node *next;
};

void f(node *&p, int val) {
  node *q = new node; // Create new node q
  q->data = val;      // assign value to q
  q->next = p;        // q now points to the same object as p (node a)
  // std::cout << p->data; // the value stored in the object pointed to by p is
  //  printed = 2
  p = q;
}

int main() {

  node *a = new node; // Create nodepointer a that points to the node
  node *b = new node; // Create nodepointer b that points to the node
  node *c = new node; // Create nodepointer c that points to the node

  a->data = 2; // Assign value to the node pointed to by pointer a
  a->next = b; // Assign pointer to next node

  b->data = 4; // Assign value to the node pointed to by pointer b
  b->next = c; // Assign pointer to next node

  c->data = 6;    // Assign value to the node pointed to by pointer c
  c->next = NULL; // Assign nullptr to end linked list

  node *p = a; // Nodepointer p is now the same as the a-pointer

  f(p, 5);

  while (p != NULL) {
    std::cout << p->data << std::endl;
    p = p->next;
  }
}
