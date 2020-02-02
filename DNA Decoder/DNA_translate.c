// CSC A48 - Exercise 9 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2019

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_len(char input_string[1024])
{
  int i = 0;

  while (input_string[i] != '\0' && i < 1024)
  {
    i++;
  }

  return i;
}

void make_short_str(char first, char second, char third, char short_str[4])
{
  short_str[0] = first;
  short_str[1] = second;
  short_str[2] = third;
}

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
	
    int i = 0, j = 0;
    int k = str_len(inputDNA);
	
    char short_str[4];
    short_str[3] = '\0';

    while (i < k)
    {
      make_short_str(inputDNA[i], inputDNA[i+1], inputDNA[i+2], short_str);

      if (strcmp(short_str, "ATT") == 0 || strcmp(short_str, "ATC") == 0 || strcmp(short_str, "ATA") == 0){outputAminoAcids[j] = 'I';}
      else if (strcmp(short_str, "CTT") == 0 || strcmp(short_str, "CTC") == 0 || strcmp(short_str, "CTA") == 0 || strcmp(short_str, "CTG") == 0 ||\
               strcmp(short_str, "TTA") == 0 || strcmp(short_str, "TTG") == 0){outputAminoAcids[j] = 'L';}
      else if (strcmp(short_str, "GTT") == 0 || strcmp(short_str, "GTC") == 0 ||\
               strcmp(short_str, "GTA") == 0 || strcmp(short_str, "GTG") == 0){outputAminoAcids[j] = 'V';}
      else if (strcmp(short_str, "TTT") == 0 || strcmp(short_str, "TTC") == 0){outputAminoAcids[j] = 'F';}
      else if (strcmp(short_str, "ATG") == 0){outputAminoAcids[j] = 'M';}
      else if (strcmp(short_str, "TGT") == 0 || strcmp(short_str, "TGC") == 0){outputAminoAcids[j] = 'C';}
      else if (strcmp(short_str, "GCT") == 0 || strcmp(short_str, "GCC") == 0 ||\
               strcmp(short_str, "GCA") == 0 || strcmp(short_str, "GCG") == 0){outputAminoAcids[j] = 'A';}
      else if (strcmp(short_str, "GGT") == 0 || strcmp(short_str, "GGC") == 0 ||\
               strcmp(short_str, "GGA") == 0 || strcmp(short_str, "GGG") == 0){outputAminoAcids[j] = 'G';}
      else if (strcmp(short_str, "CCT") == 0 || strcmp(short_str, "CCC") == 0 ||\
               strcmp(short_str, "CCA") == 0 || strcmp(short_str, "CCG") == 0){outputAminoAcids[j] = 'P';}
      else if (strcmp(short_str, "ACT") == 0 || strcmp(short_str, "ACC") == 0 ||\
               strcmp(short_str, "ACA") == 0 || strcmp(short_str, "ACG") == 0){outputAminoAcids[j] = 'T';}
      else if (strcmp(short_str, "TCT") == 0 || strcmp(short_str, "TCC") == 0 || strcmp(short_str, "TCA") == 0 || strcmp(short_str, "TCG") == 0 ||\
               strcmp(short_str, "AGT") == 0 || strcmp(short_str, "AGC") == 0){outputAminoAcids[j] = 'S';}
      else if (strcmp(short_str, "TAT") == 0 || strcmp(short_str, "TAC") == 0){outputAminoAcids[j] = 'Y';}
      else if (strcmp(short_str, "TGG") == 0)                                 {outputAminoAcids[j] = 'W';}
      else if (strcmp(short_str, "CAA") == 0 || strcmp(short_str, "CAG") == 0){outputAminoAcids[j] = 'Q';}
      else if (strcmp(short_str, "AAT") == 0 || strcmp(short_str, "AAC") == 0){outputAminoAcids[j] = 'N';}
      else if (strcmp(short_str, "CAT") == 0 || strcmp(short_str, "CAC") == 0){outputAminoAcids[j] = 'H';}
      else if (strcmp(short_str, "GAA") == 0 || strcmp(short_str, "GAG") == 0){outputAminoAcids[j] = 'E';}
      else if (strcmp(short_str, "GAT") == 0 || strcmp(short_str, "GAC") == 0){outputAminoAcids[j] = 'D';}
      else if (strcmp(short_str, "AAA") == 0 || strcmp(short_str, "AAG") == 0){outputAminoAcids[j] = 'K';}
      else                                                                    {outputAminoAcids[j] = 'R';}
			   
      j++;
      i += 3;
    }

    outputAminoAcids[j] = '\0';    
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function

    int len1 = str_len(inputDNA1);
    int len2 = str_len(inputDNA2);

    if (len1 == len2)
    {
      int Ia = 0, Ib = 0, La = 0, Lb = 0, Va = 0, Vb = 0, Fa = 0, Fb = 0, Ma = 0, Mb = 0,\
       Ca = 0, Cb = 0, Aa = 0, Ab = 0, Ga = 0, Gb = 0, Pa = 0, Pb = 0, Ta = 0, Tb = 0,\
        Sa = 0, Sb = 0, Ya = 0, Yb = 0, Wa = 0, Wb = 0, Qa = 0, Qb = 0, Na = 0, Nb = 0,\
         Ha = 0, Hb = 0, Ea = 0, Eb = 0, Da = 0, Db = 0, Ka = 0, Kb = 0, Ra = 0, Rb = 0;

      char inputDNA1s[1024];
      char inputDNA2s[1024];

      DNA_sequencing(inputDNA1, inputDNA1s);
      DNA_sequencing(inputDNA2, inputDNA2s);

      int len = str_len(inputDNA1s);

      for (int i = 0; i < len; i++)
      {
        if (inputDNA1s[i] == 'I'){Ia++;}
        else if (inputDNA1s[i] == 'L'){La++;}
        else if (inputDNA1s[i] == 'V'){Va++;}
        else if (inputDNA1s[i] == 'F'){Fa++;}
        else if (inputDNA1s[i] == 'M'){Ma++;}
        else if (inputDNA1s[i] == 'C'){Ca++;}
        else if (inputDNA1s[i] == 'A'){Aa++;}
        else if (inputDNA1s[i] == 'G'){Ga++;}
        else if (inputDNA1s[i] == 'P'){Pa++;}
        else if (inputDNA1s[i] == 'T'){Ta++;}
        else if (inputDNA1s[i] == 'S'){Sa++;}
        else if (inputDNA1s[i] == 'Y'){Ya++;}
        else if (inputDNA1s[i] == 'W'){Wa++;}
        else if (inputDNA1s[i] == 'Q'){Qa++;}
        else if (inputDNA1s[i] == 'N'){Na++;}
        else if (inputDNA1s[i] == 'H'){Ha++;}
        else if (inputDNA1s[i] == 'E'){Ea++;}
        else if (inputDNA1s[i] == 'D'){Da++;}
        else if (inputDNA1s[i] == 'K'){Ka++;}
        else if (inputDNA1s[i] == 'R'){Ra++;}
        
        if (inputDNA2s[i] == 'I'){Ib++;}
        else if (inputDNA2s[i] == 'L'){Lb++;}
        else if (inputDNA2s[i] == 'V'){Vb++;}
        else if (inputDNA2s[i] == 'F'){Fb++;}
        else if (inputDNA2s[i] == 'M'){Mb++;}
        else if (inputDNA2s[i] == 'C'){Cb++;}
        else if (inputDNA2s[i] == 'A'){Ab++;}
        else if (inputDNA2s[i] == 'G'){Gb++;}
        else if (inputDNA2s[i] == 'P'){Pb++;}
        else if (inputDNA2s[i] == 'T'){Tb++;}
        else if (inputDNA2s[i] == 'S'){Sb++;}
        else if (inputDNA2s[i] == 'Y'){Yb++;}
        else if (inputDNA2s[i] == 'W'){Wb++;}
        else if (inputDNA2s[i] == 'Q'){Qb++;}
        else if (inputDNA2s[i] == 'N'){Nb++;}
        else if (inputDNA2s[i] == 'H'){Hb++;}
        else if (inputDNA2s[i] == 'E'){Eb++;}
        else if (inputDNA2s[i] == 'D'){Db++;}
        else if (inputDNA2s[i] == 'K'){Kb++;}
        else if (inputDNA2s[i] == 'R'){Rb++;}
      }

      if (Ia == Ib && La == Lb && Va == Vb && Fa == Fb && Ma == Mb\
       && Ca == Cb && Aa == Ab && Ga == Gb && Pa == Pb && Ta == Tb\
        && Sa == Sb && Ya == Yb && Wa == Wb && Qa == Qb && Na == Nb\
         && Ha == Hb && Ea == Eb && Da == Db && Ka == Kb && Ra == Rb){return 1;}
    }

    return 0;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
  char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
