#include<stdio.h>
#include<stdlib.h>

int id = 2;

void printImgArray(int array[10][10])
{
 // Print out the contents of the array, it can be
 // used with the original array, or with the labeled
 // output after calling cell_count().
  
 printf("------ Image Contents -------\n");
 for (int i=0; i<10; i++)
 {
   for (int j=0; j<10; j++)
     printf("%02d, ",array[i][j]);
   printf("\n");
 }
 printf("-----------------------------\n");
}

void check_adjacent(int image[10][10], int row, int col)
{
  if (row > 0 && col > 0) // checking top left
  {
    if (image[row - 1][col - 1] == 1)
    {
      image[row - 1][col - 1] = id;
      check_adjacent(image, row - 1, col - 1);
    }
  }

  if (row > 0)            // checking top center
  {
    if (image[row - 1][col] == 1)
    {
      image[row - 1][col] = id;
      check_adjacent(image, row - 1, col);
    }
  }

  if (row > 0 && col < 9) //checking top right
  {
    if (image[row - 1][col + 1] == 1)
    {
      image[row - 1][col + 1] = id;
      check_adjacent(image, row - 1, col + 1);
    }
  }

  if (col > 0)           // checking left
  {
    if (image[row][col - 1] == 1)
    {
      image[row][col - 1] = id;
      check_adjacent(image, row, col - 1);
    }
  }

  if (col < 9)            // checking right
  {
    if (image[row][col + 1] == 1)
    {
      image[row][col + 1] =id;
      check_adjacent(image, row, col + 1);
    }
  }

  if (row < 9 && col > 0) // checking bottom left
  {
    if (image[row + 1][col - 1] == 1)
    {
      image[row + 1][col - 1] = id;
      check_adjacent(image, row + 1, col - 1);
    }
  }

  if (row < 9)            // checking bottom center
  {
    if (image[row + 1][col] == 1)
    {
      image[row + 1][col] = id;
      check_adjacent(image, row + 1, col);
    }
  }

  if (row < 9 && col < 9) //checking bottom right
  {
    if (image[row + 1][col + 1] == 1)
    {
      image[row + 1][col + 1] = id;
      check_adjacent(image, row + 1, col + 1);
    }
  }
}

int cell_count(int image[10][10])
{
 // This function takes as input a binary array
 // (one which contains only ones and zeros)
 // representing a micrograph of blood cells.
 // The function must count the cells in the
 // array, and label them: the entries in the array
 // corresponding to each cell will have a 
 // unique, different number, order does not
 // matter.
 //
 // Cells are represented by groups of 1's 
 // that are connected vertically, horizontally,
 // or diagonally.
 //
 // Input arrays will be 10x10, and guaranteed to
 // be binary.
 //
 // Examples:
 //
 // Input:		Labels:
 //			
 // 0011010011		0022030044
 // 0010010011		0020030044
 // 0000000111		0000000444
 // 1110000011		5550000044
 // 1100011000		5500066000
 // 0000111001		0000666007
 // 0100011011		0800066077
 // 0100000001		0800000007
 // 1100110000		8800990000
 // 0100010000          0800090000
 //
 // And there are 8 cells in this image.
 //
 // Note: Labels start at 2, the upper limit is the
 // maximum number of cells you can pack in an image
 // of 10x10.
 // * As noted before - the order of labels does
 //   not matter *
  
 // TO DO: Complete this function!
  
 // REMOVE any print statements you use for testing
 // BEFORE submitting! nothing should be printed here.

 for (int row = 0; row < 10; row++)
 {
   for (int col = 0; col < 10; col++)
   {
     if (image[row][col] == 1)
     {
       image[row][col] = id;
       check_adjacent(image, row, col);
       id++;
     }
   }
 }

 return id - 2;	// <--- obviously it should not return zero
}

#ifndef __testing
int main()
{
  // DO not change anything in main(), it will confuse the
  // auto-checker.  
  int count;
  int cellImg[10][10]={{0,0,1,1,0,0,1,0,0,1},\
		       {1,0,1,1,0,0,1,1,0,1},\
		       {1,0,0,1,1,0,1,1,0,1},\
		       {1,1,0,0,0,0,0,0,0,0},\
		       {1,0,0,1,1,1,0,0,1,0},\
		       {0,0,0,0,1,0,0,1,1,0},\
		       {0,0,1,0,0,1,0,1,0,0},\
		       {0,0,1,1,0,0,1,0,0,0},\
		       {0,0,1,0,0,0,0,0,1,1},
		       {0,1,1,0,0,0,1,1,1,1}};
		       
  printImgArray(cellImg);
  count=cell_count(cellImg);
  printImgArray(cellImg);
  printf("Total number of cells in the image: %d\n",count);
  
  return 0;
}
#endif