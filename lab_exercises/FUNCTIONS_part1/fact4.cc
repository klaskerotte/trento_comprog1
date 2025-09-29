#include "fact4.h"

long long fact(int n) {
  long long fact_var = 1;
  for (int i=1; i<=n; i++)
    fact_var *= i;
  return fact_var;
}
