// Big number calculating lib.

unsigned __int128 *newValue(unsigned __int128 x) {
  unsigned __int128 *value;
  value = (unsigned __int128 *)malloc(sizeof(unsigned __int128) * (BNLENGTH+1));
  value[0] = (x>0);
  value[1] = x;
  //printf("%d, %d\n", (value[0])&(0xFFFFFFFF), (x>0));
  for (unsigned __int128 i=2; i<=BNLENGTH; i++) {
    value[i] = 0;
  }
  return (unsigned __int128 *)value;
}

void printValueHex(unsigned __int128 *A, int enterOrNot) {
  unsigned __int128 i=A[0];
  while (i) {
    printf("%08x", (unsigned int)(A[i]>>96)&(0xFFFFFFFF));
    printf("%08x", (unsigned int)(A[i]>>64)&(0xFFFFFFFF));
    printf("%08x", (unsigned int)(A[i]>>32)&(0xFFFFFFFF));
    printf("%08x", (unsigned int)(A[i])&(0xFFFFFFFF));
    i--;
  }
  if (enterOrNot) {
    printf("\n");
  }
}

void getValueLength(unsigned __int128 *A) {
  unsigned __int128 i=BNLENGTH;
  while ((i)&&(!A[i])) {
    i--;
  }
  A[0] = (unsigned __int128)i;
}

void moveValue(unsigned __int128 *D, unsigned __int128 *S) {
  unsigned __int128 i=(D[0]>S[0]?D[0]:S[0]);
  while (i) {
    D[i] = S[i];
    i--;
  }
  D[0] = S[0];
}

void lastProcess_Add(unsigned __int128 *C, char *Mark, int counter, unsigned __int128 maxDepth) {
  if (counter>maxDepth) {
    return;
  }
  if (((unsigned __int128)Mark[counter-1] > (~C[counter]))&&(counter<BNLENGTH)) {
    Mark[counter]++;
  }
  C[counter] += Mark[counter-1];
  Mark[counter-1] = 0;
  lastProcess_Add(C, Mark, counter+1, maxDepth);
}

void lastProcess_Sub(unsigned __int128 *C, char *Mark, int counter, unsigned __int128 maxDepth) {
  if (counter>maxDepth) {
    return;
  }
  if ((C[counter] < (unsigned __int128)Mark[counter-1])&&(counter<BNLENGTH)) {
    Mark[counter]++;
  }
  C[counter] -= Mark[counter-1];
  Mark[counter-1] = 0;
  lastProcess_Sub(C, Mark, counter+1, maxDepth);
}

void addValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B) {
  // C=A+B;
  char *Mark;
  unsigned __int128 Leng=0;
  Mark = (char *)malloc(sizeof(char)*((A[0]>B[0]?A[0]:B[0])+1));//*BNLENGTH);//
  for (int i=0; i<(A[0]>B[0]?A[0]:B[0])+1; i++) {
    Mark[i] = 0;
  }
  for (unsigned __int128 i=1; i<=(A[0]>B[0]?A[0]:B[0])+1; i++) { // You could do parrllel job with OMP here.
    // A+B>MAX ==> A>MAX-B
    if (!Leng)
    if (A[i] > (~B[i])) {
      if (i<BNLENGTH) {
	Mark[i] = 1;
      }
    }
    C[i] = A[i] + B[i]; 
  }
  lastProcess_Add(C, Mark, 1, (A[0]>B[0]?A[0]:B[0])+1);
  getValueLength(C);
  //C[0] = (A[0]>B[0]?A[0]:B[0])+1;
  free(Mark);
}

void subValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B) {
  // C=A+B;
  char *Mark;
  Mark = (char *)malloc(sizeof(char)*((A[0]>B[0]?A[0]:B[0])+1));//*BNLENGTH);//
  for (int i=0; i<(A[0]>B[0]?A[0]:B[0])+1; i++) {
    Mark[i] = 0;
  }
  for (unsigned __int128 i=1; i<=(A[0]>B[0]?A[0]:B[0])+1; i++) { // You could do parrllel job with OMP here.
    // A+B>MAX ==> A>MAX-B
    if (A[i] < B[i]) {
      if (i<BNLENGTH) {
	Mark[i] = 1;
      }
    }
    C[i] = A[i] - B[i]; 
  }
  lastProcess_Sub(C, Mark, 1, (A[0]>B[0]?A[0]:B[0])+1);
  getValueLength(C);
  //C[0] = (A[0]>B[0]?A[0]:B[0])+1;
  free(Mark);
}
