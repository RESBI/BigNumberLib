#include <stdio.h>
#include <stdlib.h>
#include "./bnlib.h"

int main() {
  unsigned __int128 *A = newValue(1);
  unsigned __int128 *B = newValue(1);
  unsigned __int128 *C = newValue(1);
  //printf("%d, %d, %d\n", A[0]&(0xFFFFFFFF), B[0]&(0xFFFFFFFF), C[0]&(0xFFFFFFFF));
  while (1) {
    printValueHex(A, 1);
    addValue(C, A, B);
    //printValueHex(C, 1);
    moveValue(A, B);
    moveValue(B, C);
  }
  free(A);
  free(B);
  free(C);
  return 0;
}
