#include <stdio.h> 

double greater(char input[], int condition) //parses string input and determines whether it is greater/equal than a value. returns the value if it is, -1 if not 
  {
    double num = -1;
    sscanf(input, "%lf", &num);
    if (num<=condition)
      return -1;
    else
      return num;
  }

double validate(char msg[], char error[], int condition)
{
  double value;
  char input[50];
  do
  {
    printf("%s", msg); //display message for input
    fgets(input, sizeof(input), stdin);
    value = greater(input, condition);
    if(value<condition)
      printf("\n%s", error);
  } while(value<condition);
  return value;
}

void popSize()
{
  printf("Population size:\n\n");
  double start = validate("Starting size (>2): ", "Invalid, enter a number > 2.\n", 2);
  double birth = .01*validate("Birth rate (%): ", "Invalid, enter a percentage > 0.\n", 0);
  double death = .01*validate("Death rate (%): ", "Invalid, enter a percentage > 0.\n", 0);
  double years = validate("Number of years (>1): ", "Invalid, enter a number > 1.\n", 1);
  int yr = 0;
  double newpop = start;
  printf("\nPopulation growth:");
  while(yr<years)
  {
    printf("\nYear %d: ", ++yr);
    newpop *= (1 + (birth-death));
    printf("%d people", (int)newpop);
  }
  printf("\n\nEnding program...");
}
