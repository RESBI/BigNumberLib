# User guide

## unsigned __int128 *newValue(unsigned __int128 x);
### new a value,
### E.G.:
#### unsigned __int128 *A = newValue(12345);

## void printValueHex(unsigned __int128 *A, int enterOrNot);
### print a value,
### E.G.:
#### printValueHex(A, 1);

## void moveValue(unsigned __int128 *D, unsigned __int128 *S);
### like D = S,
### E.G.:
#### moveValue(A, B); // A = B

## void addValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B);
### C = A + B
### E.G.:
#### addValue(C, A, B);

## void subValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B);
### C = A - B
### E.G.:
#### subValue(C, A, B);