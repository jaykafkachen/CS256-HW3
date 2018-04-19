#include <stdio.h>
#include "geometry.h"
#include "population.h"
#include "tictactoe.h"
#include "reverse.h"

int main()
{
  geometrymenu();
  printf("\n\n");
  
  popSize();
  printf("\n\n");
  
  game();
  printf("\n\n");
  
  int arr[] = {4,7,1,2,8,0};
  printf("Testing reverse() with array = {4,7,1,2,8,0}\nreversing...\n");
  int *rev = reverse(arr, 6);
  printf("Reversed: ");
  arrayPrint(rev, 6);
  return 0;
}
