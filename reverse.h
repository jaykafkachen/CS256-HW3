#include <stdio.h>

/*Write a function that accepts an int  array and the array’s size as arguments. The function should create a copy of the array, except that the element values should be reversed in the copy. The function should return a pointer to the new array. Demonstrate the function in a complete program. */
int* reverse(int arr[], int size)
{
  int copy[size];
  int *copyptr = copy;
  int *arrptr = arr;
  int *endptr = &arr[size-1];
  for(int i=size-1;i>=0;i--)
  {
    *copyptr = *(arrptr+i);
    printf("%d ",*copyptr);
    copyptr++;
  }
  return copyptr;
}
}
