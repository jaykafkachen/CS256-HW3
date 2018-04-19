#include <stdio.h> 
#include <string.h>
#include <math.h>
#define PI 3.14159

//Geometry calculator
  void menu();
  void circle();
  void rectangle();
  void triangle();
  double positive(char input[50]);

  double positive(char input[50]) //parses string input and determines whether it is a positive/negative value. returns the value if it is positive, -1 if not 
  {
    double num = -1.0;
    sscanf(input, "%lf", &num);
    if (num<0)
      return -1;
    else
      return num;
  }

  void circle()
  {
    char radius[50];
    double rad;
    do
    {
      printf("\nArea of a circle:\nRadius = ");
      fgets(radius, sizeof(radius), stdin);
      rad = positive(radius);
      if(rad<0)
        printf("Radius less than 0! Please try again.\n\n");
    } while(rad<0);
    printf("Calculated area = %f", pow(rad,2)*PI);
  }
  
  void rectangle()
  {
    char length[50];
    double len;
    do
    {
      printf("\nArea of a rectangle:\nLength = ");
      fgets(length, sizeof(length), stdin);
      len = positive(length);
      if(len<0)
        printf("Length less than 0! Please try again.\n\n");
    } while(len<0);
    
    char width[50];
    double wid;
    do
    {
      printf("Width = ");
      fgets(width, sizeof(width), stdin);
      wid = positive(width);
      if(wid<0)
        printf("Width less than 0! Please try again.\n\n");
    } while(wid<0);
    printf("Calculated area = %f", len*wid);
  }
  
  void triangle()
  {
    char base[50];
    double bs;
    do
    {
      printf("\nArea of a triangle:\nBase = ");
      fgets(base, sizeof(base), stdin);
      bs = positive(base);
      if(bs<0)
        printf("Base less than 0! Please try again.\n\n");
    } while(bs<0);
    
    char height[50];
    double ht;
    do
    {
      printf("Height = ");
      fgets(height, sizeof(height), stdin);
      ht = positive(height);
      if(ht<0)
        printf("Height less than 0! Please try again.\n\n");
    } while(ht<0);
    printf("Calculated area = %f", bs*ht*0.5);
  }

void geometrymenu()
{
  char input[50] = "";
  char c;
  do
  {
    printf("Geometry calculator:\n1 - Calculate circle area\n2 - Calculate rectangle area\n3 - Calculate triangle area\n4 - Quit\n--> ");
    fgets(input, sizeof(input), stdin);
    if(strlen(input)==2)
      c = input[0];
    if((c!='1' && c!='2' && c!='3' && c!='4') || strlen(input)!=2)
      printf("Invalid input, try again\n\n");
  } while((c!='1' && c!='2' && c!='3' && c!='4'));
  switch(c)
  {
    case '1':
      circle();
      break;
    case '2':
      rectangle();
      break;
    case '3':
      triangle();
      break;
    case '4':
      printf("\nEnding program...");
      break;
  }
}

