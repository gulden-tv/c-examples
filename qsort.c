#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };
int SIZE = sizeof(values)/sizeof(values[0]);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   printf("Before sorting the array is: \n");
   for( n = 0 ; n < SIZE; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, SIZE, sizeof(int), cmpfunc);

   printf("\nAfter sorting the array is: \n");
   for( n = 0 ; n < SIZE; n++ ) {
      printf("%d ", values[n]);
   }
  
   return(0);
}
