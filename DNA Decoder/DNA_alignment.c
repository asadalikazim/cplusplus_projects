/*
 * CSC A48 - Exercise 10 - DNA alignment
 * 
 * In the previous exercise you learned a bit about DNA transcription
 * and the process by which all the cells in your body (and any other
 * DNA based lifeforms!) transform a sequence of genetic material into
 * proteins.
 * 
 * In this assignment, you'll explore a very important problem in
 * bio-informatics:
 * 
 * Sequence-alignment.
 * 
 * Given two input sequences of *aminoacids*, e.g.
 * 
 * 1)    ADPIPDTTKARNTTPKFVDG
 * 2)    AAADPIAADKARNTDD
 * 
 * Determine the *best alignment* between the two chains - i.e. the
 * position where sewuence 2) has the most aminoacids in agreement
 * with sequence 1)
 * 
 * For example, two possible alignments of the sequences above:
 * 
 *   ADPIPDTTKARNTTPKFVDG
 * AAADPIAADKARNTDD             - 4 aminoacids agree (ADPI)
 * 
 * pos = -2    (sequence 2 starts at -2 spots from sequence 1)
 * 
 * (Note that two aminoacids in sequence 2) are not matched to
 *  anything in 1), this is perfectly ok)
 * 
 *   ADPIPDTTKARNTTPKFVDG
 *  AAADPIAADKARNTDD             - 6 aminoacids agree (A.......KARNT..)
 * 
 * pos = -1    (sequence 2 starts at -1 spots from seq. 1)
 * 
 * All possible alignments where at least 1 aminoacid from chain 2)
 * alings with an aminoacid from 1) must be checked, and the position
 * of the best matching alignment is returned.
 * 
 * (c) F. Estrada, March 2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

void sequence_alignment(char sequence1[MAX_STR_LEN], char sequence2[MAX_STR_LEN], int *pos, int *matches)
{
   /*
    * This function determines the best alignment between sequence 1 and 
    * sequence 2 by checking for all possible positions of sequence 2 (including
    * positions where only *part* of the sequences overlap) and counting how
    * many amino-acids match. 
    *
    * The function updates the position 'pos' at which sequence2 must be
    * placed relative to the start of sequence 1 to obtain the best alignment,
    * and it updates 'matches' with the number of matching aminoacids at that
    * position.
    *
    * If there are teo or more positions with the same number of matches, the 
    * function returns the first one (the one most to the left).
    */

    /*****
     * TO DO:
     * Complete this function
     *****/
	 
	 int len1 = strlen(sequence1);
	 int len2 = strlen(sequence2);
	 
	 int max_match = 0, max_pos, matching, cur_pos;
     
	 int seq1_index = 0;	 
	 int seq2_index = len2 - 1;
	 
	 while (seq2_index >= 0)
	 {
		 int j = seq1_index;
		 int k = seq2_index;
		 
		 matching = 0;
		 cur_pos = -seq2_index;
		 
		 while (j < len1 && k < len2)
		 {
			 if (sequence1[j] == sequence2[k]){matching++;}
			 
			 j++; k++;
		 }
		 
		 if (matching > max_match){max_match = matching; max_pos = cur_pos;}
		 
		 seq2_index--;
	 }

	 seq1_index = 1;	 
	 seq2_index = 0;
	 
	 while (seq1_index < len1)
	 {
		 int j = seq1_index;
		 int k = seq2_index;
		 
		 matching = 0;
		 cur_pos = seq1_index;
		 
		 while (j < len1 && k < len2)
		 {
			 if (sequence1[j] == sequence2[k]){matching++;}
			 
			 j++; k++;
		 }
		 
		 if (matching > max_match){max_match = matching; max_pos = cur_pos;}
		 
		 seq1_index++;
	 }
	 
	 if (max_match > 0){*matches = max_match; *pos = max_pos;}
     else {*matches = 0; *pos = 0;}

}

#ifndef __testing

int main()
{
   /*
    * Exercise 10 - sequence alignment
    */
   
   char sequence1[MAX_STR_LEN]="CMYVWKGLTKELFVLPTRFTLKHHRFRELETAYNFELNMMHHKRPRVAVEKRPSCVHWFTLILNLYKKNLHRDAQSGMINMAWVKVLTAIYPMQSWLKYC";
   char sequence2[MAX_STR_LEN]="LETAYTFELNMAHHKRPRDAVEKRPCCVHW";
   char sequence3[MAX_STR_LEN]="ATTPDATPCMYVDKGLPK";
   int pos2,pos3;
   int match2, match3;
   
   sequence_alignment(sequence1, sequence2, &pos2, &match2);
   sequence_alignment(sequence1, sequence3, &pos3, &match3);
    
   printf("Sequence 2 has best alignment with sequence 1 at position %d, with %d matches\n",pos2,match2);
   printf("Sequence 3 has best alignment with sequence 1 at position %d, with %d matches\n",pos3,match3);
   
}

#endif