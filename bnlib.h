#include <bnlib.c>

#define LENGTH 4096

unsigned __int128 MAX_128 = ~0;

unsigned __int128 *newValue(unsigned __int128 x);
void printValueHex(unsigned __int128 *A, int enterOrNot);
void moveValue(unsigned __int128 *D, unsigned __int128 *S);
void lastProcess_Add(unsigned __int128 *C, char *Mark, int counter, unsigned __int128 maxDepth);
void lastProcess_Sub(unsigned __int128 *C, char *Mark, int counter, unsigned __int128 maxDepth);
void getValueLength(unsigned __int128 *A);

void addValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B);
void subValue(unsigned __int128 *C, unsigned __int128 *A, unsigned __int128 *B);
 
