// CSC A48 - Exercise 8 - Caesar Cipher Breaker
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// (c) F. Estrada, Mar. 2019.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Do not include any extra libraries!

#define MAX_STR_LEN 2048

int str_len(unsigned char string[MAX_STR_LEN])
{
  //returns the length of the string

  int i = 0;

  while (string[i] != '\0')
  {
    i++;
  }

  return i;
}

int find_substring(unsigned char source_string[MAX_STR_LEN], unsigned char query[MAX_STR_LEN])
{
   // This function determines whether a query string is present anywhere within
   // the source_string. If the query string is found, it returns 1, otherwise it
   // returns 0

   // TO DO: Implement this function!
   
   int query_len = str_len(query);

   //special case: empty query

   if (query_len == 0)
   {
     return 1;
   }

   int j, k;
   int source_len = str_len(source_string);

   //loops through the source...
   for (j = 0; j < source_len; j++)
   {
     //... finds the beginning of the query...
     if (source_string[j] == query[0])
     {
       k = 0;
       
       //... matches the rest of the query...

       while (k < query_len && source_string[j + k] == query[k])
       {
         k++;
       }

       //... checks whether the entire query was found and returns 1 if so
       
       if (k == query_len)
       {
         return 1;
       }
     }
   }
   
   return 0;
}

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], int displacement)
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the specified displacement.
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'. 
 // 
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, and verify it works in 
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
 
 // TO DO: Implement this function
 
 int i = 0, j;
 char problem_char;

 if (displacement < 0)
 {
   j = -displacement;
   problem_char = (char)j;
 }
 else
 {
   j = 256 - displacement;
   problem_char = (char)j;
 }
 
 
 while (plaintext[i] != '\0' && i < MAX_STR_LEN)
 {
   if (plaintext[i] != problem_char)
   {
     j = (int)plaintext[i] + displacement;
     if (j > 255){j -= 256;}
     else if (j < 0){j += 256;}

     plaintext[i] = (char)j;
   }
   i++;
 }
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], int displacement)
{

  int i = 0, j;
  char problem_char;

  if (displacement < 0)
  {
    j = -displacement;
    problem_char = (char)j;
  }
  else
  {
    j = 256 - displacement;
   problem_char = (char)j;
  }
 
 
  while (cryptotext[i] != '\0' && i < MAX_STR_LEN)
  {
    if (cryptotext[i] != problem_char)
    {
      j = (int)cryptotext[i] - displacement;
      if (j > 255){j -= 256;}
      else if (j < 0){j += 256;}
	  
      cryptotext[i] = (char)j;    
    }
    i++;
  }   
}


void caesar_break(unsigned char message[5][MAX_STR_LEN])
{
  /*
   * This function takes in a message (of 5 lines of text, no more no less)
   * that has been encoded using a correct implementation of the caesar
   * cipher from Exercise 7. 
   * The function must decode the message and restore the original text.
   * 
   * You do not know the displacement used to encode the message
   * But you do know it's from Marzieh and Paco, so it probably says
   * something about A48
   * 
   * The goal of this exercise is to get you to think hard, about the
   * problem, about what needs to be done to solve it, and about
   * different ways you could try to do this. So, if it seems 
   * challenging - that's exactly how it should feel :). You're exercising
   * and this is a tough uphill.
   * 
   * To help you a bit:
   * - You can re-use code from previous exercises you've solved
   *   (at the very least, you will need a caesar_decipher() function
   *    at some point, but maybe code from other exercises could help?)
   * - You don't have to worry about complexity (but it shouldn't take
   *   mode than a few seconds to run your code)
   * 
   * You can solve this if you sit down and consider the problem, think
   * about how caesar cipher works, and what you need to do to break it,
   * as well as how to figure out you broke it.
   * 
   * It's problem solving, so please don't ask on Piazza for someone to
   * confirm things for you. It's your task, see to it, make reasonable
   * assumptions, and see my Piazza post on problem solving if you
   * need a reminder of what should be in your mind as you work on this.
   */
  
  /*** TO DO:
   * Implement this function to decode secret messages!
   */  

  
  //MOST MAJOR ASSUMPTION: message contains the following words (at least one)

  unsigned char possible_words[100][25] = {"A48", "Computer", "Science", "Assignment", "Exercise",\
  "Crunchy", "Mushy", "COMPUTER", "SCIENCE", "ASSIGNMENT",\
  "EXERCISE", "CRUNCHY", "MUSHY", "computer", "science",\
  "assignment", "exercise", "crunchy", "mushy", "Paco",\
  "Estrada", "Marzieh", "BST", "linked", "list",\
  "weekly", "Weekly", "WEEKLY", "QUIZ", "Quiz",\
  "quiz", "question", "QUESTION", "Question", "exam",\
  "final", "mid", "FINAL", "Final", "MID",\
  "Mid", "EXAM", "Exam"};
  
  int broken = 0;

  for (int displacement = -255; displacement < 256; displacement++)
  {
    caesar_decipher(message[0], displacement);
    caesar_decipher(message[1], displacement);
    caesar_decipher(message[2], displacement);
    caesar_decipher(message[3], displacement);
    caesar_decipher(message[4], displacement);
       
    for (int i = 0; i < 43; i++)
    {
      broken = find_substring(message[0], possible_words[i]);
      if (broken == 1)
      {
        break;
      }

      broken = find_substring(message[1], possible_words[i]);
      if (broken == 1)
      {
        break;
      }

      broken = find_substring(message[2], possible_words[i]);
      if (broken == 1)
      {
        break;
      }

      broken = find_substring(message[3], possible_words[i]);
      if (broken == 1)
      {
        break;
      }

      broken = find_substring(message[4], possible_words[i]);
      if (broken == 1)
      {
        break;
      }
    }

    if (broken == 1)
    {
      break;
    }
	else
	{
      caesar_cipher(message[0], displacement);
      caesar_cipher(message[1], displacement);
      caesar_cipher(message[2], displacement);
      caesar_cipher(message[3], displacement);
      caesar_cipher(message[4], displacement);
	}
	
  }
}

#ifndef __testing

int main()
{
    unsigned char the_message[5][MAX_STR_LEN]={"Wklv#zhhn#lq#D7;#zh#fryhu#EVW#lpsohphqwdwlrq",
					       "Gr#qrw#irujhw#wr#frpsohwh#|rxu#zhhno|#h{huflvh",
					       "Wkh#txl}#zloo#eh#rq#frpsxwdwlrqdo#frpsoh{lw|",
					       "Vr#gr#qrw#irujhw#Elj#R",
					       "Dqg#vwduw#hduo|#rq#|rxu#dvvljqphqw#5"};
					       
    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s\n",the_message[i]);

    caesar_break(the_message);
    
    printf("\n**** Decoded text lines (should show the original message!):\n\n");
    for (int i=0; i<5; i++)
        printf("%s\n",the_message[i]);
    
    return 0;    
}

#endif