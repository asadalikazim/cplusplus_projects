#include<stdio.h>
#include<stdlib.h>

int find_sum(int square[6][6])
{
  //returns the sum each row, column and diagonal need to sum to

  //checks columns and rows
  for (int i =0; i < 6; i++)
  {
    if (square[i][0] != -1 && square[i][1] != -1 && square[i][2] != -1 && square[i][3] != -1 && square[i][4] != -1 && square[i][5] != -1)
    {
      return (square[i][0] + square[i][1] + square[i][2] + square[i][3] + square[i][4] + square[i][5]);
    }
    if (square[0][i] != -1 && square[1][i] != -1 && square[2][i] != -1 && square[3][i] != -1 && square[4][i] != -1 && square[5][i] != -1)
    {
      return (square[0][i] + square[1][i] + square[2][i] + square[3][i] + square[4][i] + square[5][i]);
    }
  }

  //checks minor diagonal
  if (square[0][5] != -1 && square[1][4] != -1 && square[2][3] != -1 && square[3][2] != -1 && square[4][1] != -1 && square[5][0] != -1)
  {
    return (square[0][5] + square[1][4] + square[2][3] + square[3][2] + square[4][1] + square[5][0]);
  }

  //returns major diagonal as last resort
  return (square[0][0] + square[1][1] + square[2][2] + square[3][3] + square[4][4] + square[5][5]);
}

int find_unknowns(int square [6][6])
{
  //returns the number of unknowns in the magic square
  int unknowns = 0;

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (square[i][j] == -1)
      {
        unknowns++;
      }
    }
  }

  return unknowns;
}

void solve_cols(int square[6][6], int *p, int sum)
{
  //*tries* to solve a column if there is only one unkown in it
  for (int i = 0; i < 6; i++)
  {
    if (square[i][0] == -1 && square[i][1] != -1 && square[i][2] != -1 && square[i][3] != -1
    && square[i][4] != -1 && square[i][5] != -1)
    {
      square[i][0] = sum - (square[i][1] + square[i][2] + square[i][3] + square[i][4] + square[i][5]);
      *p = *p + 1;
    }
    else if (square[i][0] != -1 && square[i][1] == -1 && square[i][2] != -1 && square[i][3] != -1
    && square[i][4] != -1 && square[i][5] != -1)
    {
      square[i][1] = sum - (square[i][0] + square[i][2] + square[i][3] + square[i][4] + square[i][5]);
      *p = *p + 1;
    }
    else if (square[i][0] != -1 && square[i][1] != -1 && square[i][2] == -1 && square[i][3] != -1
    && square[i][4] != -1 && square[i][5] != -1)
    {
      square[i][2] = sum - (square[i][0] + square[i][1] + square[i][3] + square[i][4] + square[i][5]);
      *p = *p + 1;
    }
    else if (square[i][0] != -1 && square[i][1] != -1 && square[i][2] != -1 && square[i][3] == -1
    && square[i][4] != -1 && square[i][5] != -1)
    {
      square[i][3] = sum - (square[i][0] + square[i][1] + square[i][2] + square[i][4] + square[i][5]);
      *p = *p + 1;
    }
    else if (square[i][0] != -1 && square[i][1] != -1 && square[i][2] != -1 && square[i][3] != -1
    && square[i][4] == -1 && square[i][5] != -1)
    {
      square[i][4] = sum - (square[i][0] + square[i][1] + square[i][2] + square[i][3] + square[i][5]);
      *p = *p + 1;
    }
    else if (square[i][0] != -1 && square[i][1] != -1 && square[i][2] != -1 && square[i][3] != -1
    && square[i][4] != -1 && square[i][5] == -1)
    {
      square[i][5] = sum - (square[i][0] + square[i][1] + square[i][2] + square[i][3] + square[i][4]);
      *p = *p + 1;
    }
  }
}

void solve_rows(int square[6][6], int *p, int sum)
{
  //*tries* to solve a row if there is only one unknown in it
  for (int i = 0; i < 6; i++)
  {
    if (square[0][i] == -1 && square[1][i] != -1 && square[2][i] != -1 && square[3][i] != -1
    && square[4][i] != -1 && square[5][i] != -1)
    {
      square[0][i] = sum - (square[1][i] + square[2][i] + square[3][i] + square[4][i] + square[5][i]);
      *p = *p + 1;
    }
    else if (square[0][i] != -1 && square[1][i] == -1 && square[2][i] != -1 && square[3][i] != -1
    && square[4][i] != -1 && square[5][i] != -1)
    {
      square[1][i] = sum - (square[0][i] + square[2][i] + square[3][i] + square[4][i] + square[5][i]);
      *p = *p + 1;
    }
    else if (square[0][i] != -1 && square[1][i] != -1 && square[2][i] == -1 && square[3][i] != -1
    && square[4][i] != -1 && square[5][i] != -1)
    {
      square[2][i] = sum - (square[0][i] + square[1][i] + square[3][i] + square[4][i] + square[5][i]);
      *p = *p + 1;
    }
    else if (square[0][i] != -1 && square[1][i] != -1 && square[2][i] != -1 && square[3][i] == -1
    && square[4][i] != -1 && square[5][i] != -1)
    {
      square[3][i] = sum - (square[0][i] + square[1][i] + square[2][i] + square[4][i] + square[5][i]);
      *p = *p + 1;
    }
    else if (square[0][i] != -1 && square[1][i] != -1 && square[2][i] != -1 && square[3][i] != -1
    && square[4][i] == -1 && square[5][i] != -1)
    {
      square[4][i] = sum - (square[0][i] + square[1][i] + square[2][i] + square[3][i] + square[5][i]);
      *p = *p + 1;
    }
    else if (square[0][i] != -1 && square[1][i] != -1 && square[2][i] != -1 && square[3][i] != -1
    && square[4][i] != -1 && square[5][i] == -1)
    {
      square[5][i] = sum - (square[0][i] + square[1][i] + square[2][i] + square[3][i] + square[4][i]);
      *p = *p + 1;
    }
  }
}

void solve_dias(int square[6][6], int *p, int sum)
{
  //*tries* to solve a diagonal if there is only one unkown in it


  // checking major diagonal
  if (square[0][0] == -1 && square[1][1] != -1 && square[2][2] != -1 && square[3][3] != -1
    && square[4][4] != -1 && square[5][5] != -1)
    {
      square[0][0] = sum - (square[1][1] + square[2][2] + square[3][3] + square[4][4] + square[5][5]);
      *p = *p + 1;
    }
  else if (square[0][0] != -1 && square[1][1] == -1 && square[2][2] != -1 && square[3][3] != -1
    && square[4][4] != -1 && square[5][5] != -1)
    {
      square[1][1] = sum - (square[0][0] + square[2][2] + square[3][3] + square[4][4] + square[5][5]);
      *p = *p + 1;
    }
  else if (square[0][0] != -1 && square[1][1] != -1 && square[2][2] == -1 && square[3][3] != -1
    && square[4][4] != -1 && square[5][5] != -1)
    {
      square[2][2] = sum - (square[0][0] + square[1][1] + square[3][3] + square[4][4] + square[5][5]);
      *p = *p + 1;
    }
  else if (square[0][0] != -1 && square[1][1] != -1 && square[2][2] != -1 && square[3][3] == -1
    && square[4][4] != -1 && square[5][5] != -1)
    {
      square[3][3] = sum - (square[0][0] + square[1][1] + square[2][2] + square[4][4] + square[5][5]);
      *p = *p + 1;
    }
  else if (square[0][0] != -1 && square[1][1] != -1 && square[2][2] != -1 && square[3][3] != -1
    && square[4][4] == -1 && square[5][5] != -1)
    {
      square[4][4] = sum - (square[0][0] + square[1][1] + square[2][2] + square[3][3] + square[5][5]);
      *p = *p + 1;
    }
  else if (square[0][0] != -1 && square[1][1] != -1 && square[2][2] != -1 && square[3][3] != -1
    && square[4][4] != -1 && square[5][5] == -1)
    {
      square[5][5] = sum - (square[0][0] + square[1][1] + square[2][2] + square[3][3] + square[4][4]);
      *p = *p + 1;
    }

  //checking minor diagonal
  if (square[0][5] == -1 && square[1][4] != -1 && square[2][3] != -1 && square[3][2] != -1
    && square[4][1] != -1 && square[5][0] != -1)
    {
      square[0][5] = sum - (square[1][4] + square[2][3] + square[3][2] + square[4][1] + square[5][0]);
      *p = *p + 1;
    }
  else if (square[0][5] != -1 && square[1][4] == -1 && square[2][3] != -1 && square[3][2] != -1
    && square[4][1] != -1 && square[5][0] != -1)
    {
      square[1][4] = sum - (square[0][5] + square[2][3] + square[3][2] + square[4][1] + square[5][0]);
      *p = *p + 1;
    }
  else if (square[0][5] != -1 && square[1][4] != -1 && square[2][3] == -1 && square[3][2] != -1
    && square[4][1] != -1 && square[5][0] != -1)
    {
      square[2][3] = sum - (square[0][5] + square[1][4] + square[3][2] + square[4][1] + square[5][0]);
      *p = *p + 1;
    }
  else if (square[0][5] != -1 && square[1][4] != -1 && square[2][3] != -1 && square[3][2] == -1
    && square[4][1] != -1 && square[5][0] != -1)
    {
      square[3][2] = sum - (square[0][5] + square[1][4] + square[2][3] + square[4][1] + square[5][0]);
      *p = *p + 1;
    }
  else if (square[0][5] != -1 && square[1][4] != -1 && square[2][3] != -1 && square[3][2] != -1
    && square[4][1] == -1 && square[5][0] != -1)
    {
      square[4][1] = sum - (square[0][5] + square[1][4] + square[2][3] + square[3][2] + square[5][0]);
      *p = *p + 1;
    }
  else if (square[0][5] != -1 && square[1][4] != -1 && square[2][3] != -1 && square[3][2] != -1
    && square[4][1] != -1 && square[5][0] == -1)
    {
      square[5][0] = sum - (square[0][5] + square[1][4] + square[2][3] + square[3][2] + square[4][1]);
      *p = *p + 1;
    }
}

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////
  int sum = find_sum(square);
  int unknowns = find_unknowns(square);
  int solved = 0;
  
  while (solved < unknowns)
  {
    //*tries* to solve a column
    solve_cols(square, &solved, sum);

    //*tries* to solve a row
    solve_rows(square, &solved, sum);

    //*tries* to solve diagonal
    solve_dias(square, &solved, sum);
  }
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
