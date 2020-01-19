#include <stdio.h>
 
int main() {
  #pragma omp parallel
  {
    printf("https://helloacm.com\n");     
  }
  return 0;
}