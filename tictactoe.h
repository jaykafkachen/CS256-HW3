#include <stdio.h> 

char board[][3] = {{'*','*','*'},
                  {'*','*','*'},
                  {'*','*','*'}};
int turn = 1; //1 or 2

void display();
void move();
void game();
int checkwin();

void display()
{
  printf("\n  1 2 3");
  for(int i=0;i<3;i++)
  {
    printf("\n%d ", i+1);
    for(int j=0;j<3;j++)
    {
      printf("%c ", board[i][j]);
    }
  }
  printf("\n");
}

void move()
{
  printf("\nPlayer %d's turn\n", turn);
  char mark  = (turn==1) ? 'x' : 'o';
  int valid = 0;
  do{
    printf("row: ");
    int row = getchar()-'1';
    getchar();
    printf("column: ");
    int col = getchar()-'1';
    getchar();
    if(row<=3 && col<=3 && board[row][col]=='*')
    {
      board[row][col] = mark;
      valid = 1;
    }
    else
    {
      printf("\nInvalid input.\n"); 
    }
  } while(valid==0);
}

void game()
{
  int win = 0;
  int turns = 9;
  while(turns>0 && win==0)
  {
    display();
    move();
    win = checkwin();
    turns--;
    if(win==1)
      break;
    else
      turn = (turn==1) ? 2 : 1;
  }
  printf("\nFinal score: ");
  display();
  if(win==1)
    printf("\nPlayer %d wins!\n\nEnding program...", turn);
  else
    printf("\nNo one won!\n\nEnding program...");
}

int checkwin()
{
  for(int i=0;i<3;i++)
  {
    if(board[i][0]!='*' && board[i][0]==board[i][1] && board[i][1]==board[i][2])
      return 1;
  }
  for(int j=0;j<3;j++)
  {
    if(board[0][j]!='*' && board[0][j]==board[1][j] && board[1][j]==board[2][j])
      return 1;
  }
  if(board[0][0]!='*' && board[0][0]==board[1][1] && board[1][1]==board[2][2])
    return 1;
  if(board[2][0]!='*' && board[2][0]==board[1][1] && board[1][1]==board[0][2])
    return 1;
  return 0;
}
