/* 
 * CSC A48 - Assignment 3 - Ingredient networks
 * 
 * In this assignment, you will practice and strengthen your
 * understanding of graph and recursion. The application 
 * you're working on is a simple network for studying
 * how food ingredients interact. 
 * 
 * This kind of network is the basic model that very
 * powerful systems such as IMB's Watson use as the 
 * basis for creating new combinations of ingredients
 * that are likely to go well together, but haven't been
 * used in previously printed recipes.
 * 
 * Your work here has several components:
 * 
 * - Understanding how the graph is represented by an
 *   adjacency matrix.
 * - Using the adjacency matrix to figure out, given
 *   an input ingredient, what other ingredients it is
 *   related to directly
 * - Using the adjacency matrix to determine, given
 *   a specific ingredient, which others are related
 *   to it directly *and* indirectly by a distance 
 *   of k hops along the graph (k>=1).
 * - Get lits of ingredients that are related, but
 *   not including ingredients from a separate
 *   list of ingredients
 * - *crunchy* Using the adjacency matrix that, given
 *   a recipe (which a list of ingredients) and 
 *   a target ingredient (part of the recipe) to
 *   replace, finds the best replacement from the
 *   remaining ingredients in the graph and updates
 *   the recipe.
 * 
 * This file contains the functions that set up
 * the adjacency matrix and the list of ingredients
 * for you. We provide you with 2 graphs, a 
 * small one with 10 ingredients (and an adjacency
 * matrix of size 10x10), and a full one with 
 * 400 ingredients (adjacency matrix is 400x400).
 * 
 * Use the 10x10 while implementing and testing your
 * solution, and only move to the full-size one once
 * you're confident your code works well.
 * 
 * Select which matrix to use by uncommenting the
 * respective #define statement below.
 * 
 * Sections where you have to implement code are
 * clearly marked
 * ********
 * TO DO:
 * ********
 * 
 * (c) F. Estrada, March 2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024
#ifndef __testing
#define MAT_SIZE 10	// Use the small graph
//#define MAT_SIZE 400	// Use full-size graph
#endif

// The following are GLOBAL variables you can use
// anywhere in your code. They include the 
// adjacency matrix, as well as an array of strings
// to store the ingredient names.
double AdjMat[MAT_SIZE][MAT_SIZE];
char ingredients[MAT_SIZE][MAX_STR_LEN];

// Bare-bones implementation of a linked-list of
// integers, you can use it to return the ingredient
// lists requested from functions you have to
// implement. DO NOT CHANGE THE IMPLEMENTATION
// OF THE LINKED LISTS.

typedef struct intNode_struct
{
    int  x;
    struct intNode_struct *next;
} intNode;

intNode *insertInt(intNode *h, int x)
{
  // Inserts the int 'x' into the linked list 
  // whose head is at the address in 'h'
  
  intNode *newNode;
  
  newNode=(intNode *)calloc(1,sizeof(intNode));
  newNode->x=x;
  newNode->next=NULL;
  
  if (h!=NULL)
    newNode->next=h;
  
  return newNode;
}

int searchInt(intNode *h, int x)
{
  // Search the linked list for the value 'x', if
  // found, it returns 1, else it returns 0
  while (h!=NULL)
  {
    if (h->x==x) return 1;
    h=h->next;
  }
  return 0;
}

intNode *deleteList(intNode *h)
{
  // Delete list and free memory
  intNode *q;
  if (h==NULL) return NULL;
  
  while (h!=NULL)
  {
     q=h->next;
     free(h);
     h=q;
  }
  
  return NULL;
}

// Read the adjacency matrix from file, and read the ingredient
// names
void load_ingredients(void)
{
  // Loads the adjacency matrix and ingredients list from file,
  // N must be either 10 (small graph), or 400 (full-size).
  
  FILE *f;
  int n=MAT_SIZE;
  
  if (n==10) f=fopen("AdjMat_small.dat","rb");
  else f=fopen("AdjMat_full.dat","rb");
  if (f==NULL)
  {
    printf("Can not open file with adjacency matrix. Please make sure it's in this directory\n");
    return;
  }
  fread(&AdjMat[0][0],n*n*sizeof(double),1,f);
  fclose(f);

  /*
  for (int i=0; i<MAT_SIZE; i++)
  {
    for (int j=0; j<MAT_SIZE; j++)
      printf("%2.2lf, ",AdjMat[i][j]);
    printf("\n");
  }
  */
  
  if (n==10) f=fopen("Ingredient_names_small.txt","r");
  else f=fopen("Ingredient_names_full.txt","r");
  if (f==NULL)
  {
    printf("Can not open file with ingredient names. Please make sure it's in this directory\n");
    return;
  }
  printf("Reading ingredient names. Available ingredient are:\n");
  for (int i=0; i<n; i++)
  {
    fgets(&ingredients[i][0],MAX_STR_LEN,f);
    for (int j=0; j<strlen(ingredients[i]); j++)
      if (ingredients[i][j]==10||ingredients[i][j]==13) ingredients[i][j]=0;
    printf("%s\n",ingredients[i]);
  }
  fclose(f);
}

/***************************************************************
 * The part of the assignment you need to implement starts below
 ***************************************************************/
 
 intNode *remove_Int(intNode *head, int value)
 {
	 /*HELPER FUNCTION
	  *This function traverses the list pointed to by head and  
	  *removes the node with the value in it, if it exists
	  */
	  
	  intNode *p = NULL;
      intNode *q = NULL;
	  
	  if (head == NULL){return NULL;}

     if (head->x == value)
     {
         p = head->next;
         free(head);
         return p;
     }

     p = head;

     while (p != NULL)
     {
         q = p->next;

         if (q != NULL && q->x == value)
         {
             p->next = q->next;
             free(q);
             break;
         }

         p = q;
     }    

     return head;
 }
 
 intNode *clean_up(intNode *master_h, intNode *delete_h)
 {
	 /*HELPER FUNCTION
	  *This function traverses the list pointed to by delete_h
	  *and removes each value from the the list pointed to by master_h
	  *if its present
	  */
	  
	  while (delete_h != NULL)
	  {
		  master_h = remove_Int(master_h, delete_h->x);
		  delete_h = delete_h->next;
	  }
	  
	  return master_h;
 }
 
 void initialise1(int arr[MAT_SIZE])
 {
	 /*HELPER FUNCTION
	  *This function initialises the array passed to it to -1
	  */
	 for (int i = 0; i < MAT_SIZE; i++)
	 {
		 arr[i] = -1;
	 }
 }
 
 
 int not_in(int arr[10], int query)
 {
	 /*HELPER FUNCTION
	  *This function returns 1 if the query is NOT in the array arr
	  *0 otherwise
	  */
	  
	  for (int i = 0; i < 10; i++)
	  {
		  if (arr[i] == query){return 0;}
	  }
	  
	  return 1;
 }
 
 int max(int arr[MAT_SIZE])
 {
	 /*HELPER FUNCTION
	  *This function goes over the array arr and returns the index i
	  * with the highest value arr[i]
	  *if more than one indexes have the same highest value 
	  *(i.e. arr[i] == arr[j]) it returns the one that was encountered 
	  * first (i.e. returns i if i < j
	  */
	  
	  int max_ind = 0;
	  
	  for (int i = 0; i < MAT_SIZE; i++)
	  {
		  if (arr[i] > arr[max_ind]){max_ind = i;}
	  }
	  
	  return max_ind;
 }
 
 int find_index(char arr[10][MAX_STR_LEN], char query[MAX_STR_LEN])
 {
	 /*HELPER FUNCTION
	  *This function returns the index at which query is in arr
	  *returns -1 if it is not found
	  */
	  
	  for (int i = 0; i < 10; i++)
	  {
		  if (strcmp(arr[i], query) == 0){return i;}
	  }
	  
	  return -1;
 } 
 
 /*
 int find_Len(char arr[10][MAX_STR_LEN])
 {
	  *HELPER FUNCTION
	  *This function takes in an array of size ten and returns the number
	  *of entries in the array
	  *i.e. it returns an int <= 10
	  *
	  
	  int i = 0;
	  while (strcmp(arr[i], '\0') != 0 && i < 10)
	  {
		  i++;
	  }
	  
	  return i;
 }
 */

void print_ingredients(intNode *h)
{
    /*
     * This function prints out all the ingredients corresponding
     * to the ingredient indexes stored in the linked list
     * whose head is 'h'.
     */
    
    /*****
     * TO Do:
     * Complete this function
     *****/
	 while (h != NULL)
	 {
		 printf("%s\n",ingredients[h->x]);
		 h = h->next;
	 }
}

int ingredient_index(char source_ingredient[MAX_STR_LEN])
{
    /*
     * This function looks into the array with ingredient
     * names for one that matches the requested 
     * 'source_ingredient'. If a match is found, it
     * returns the index at which the matching ingredient
     * name was found.
     * 
     * If the 'source_ingredient' is *not* in the ingredients
     * array, the function returns -1
     */
    
    /******
     * TO Do:
     * Implement this function
     *****/
	 
	 for (int i = 0; i < MAT_SIZE; i++)
	 {
		 if (strcmp(ingredients[i], source_ingredient) == 0){return i;}
	 }
     return -1;
}

 void initialise2(char ingredients[10][MAX_STR_LEN], int indexes[10])
 {
	 /*HELPER FUNCTION
	  *This function places the index of the ingredient in
	  *ingredient[i] in indexes[i], -1 if it is not a valid
	  *ingredient
	  */
	  
	  for (int i = 0; i < 10; i++)
	  {
		  indexes[i] = ingredient_index(ingredients[i]);
	  }
 }


void related_ingredients(char source_ingredient[MAX_STR_LEN])
{
    /*
     * This function prints out all the ingredients related
     * to the source ingredient. 
     * 
     * One per line, with no additional characters or symbols.
     *
     * Format of the adjacency matrix:
     * 
     * AdjMat[i][j] = 0 if two ingredients i and j are not directly linked
     *                (no edge in the graph between them, this means
     *                 they never appeared together in one recipe)
     * AdjMat[i][j] > 0 if two ingredients i and j are neighbours (they
     * 			appeared together in at least a recipe). The
     * 			actual value indicates how many times these two
     * 			ingredients appeared together in a recipe
     * 
     * Make sure you understand what this is telling you about the
     * ingredients in your graph. You'll need it later
     */
    
    /**********
     * TO DO:
     * Implement this function
     * ********/
	 
	 intNode *h = NULL;
	 int index = ingredient_index(source_ingredient);
	 
	 if (index != -1)
	 {
		 for (int i = 0; i < MAT_SIZE; i++)
		 {
			 if (AdjMat[index][i] != 0)
			 {
				 h = insertInt(h, i);
			 }
		 }
	 }
	 
	 print_ingredients(h);

}

/* 
intNode *merge_list(intNode *master_list, intNode *merger_list)
{
	 *HELPER FUNCTION
	 *This function takes two lists and adds all the non-duplicate
	 *items in the merger_list to the master_list
	 *
	 int searcher;
	 
	 while (merger_list != NULL)
	 {
		 searcher = searchInt(master_list, merger_list->x);
		 
		 if (searcher == 0)
		 {
			 master_list = insertInt(master_list, merger_list->x);
		 }
	 }
	 
	 return master_list;
} */

 
intNode *related_k_dist(intNode *h, char source_ingredient[MAX_STR_LEN], int k, int dist)
{
    /*
     * This function determines the ingredients related to the
     * specified source ingredient by a distance of at most k.
     * k >= 1
     * 
     * For instance, if k=2, the list should contain all the
     * ingredients who are neighbours of source_ingredient[]
     * as well as the ingredients that are neighbours of
     * the neighbours (distance=2).
     * 
     * If k=3, then we want source_ingredients' neighbours, its
     * neighbours' neighbours, and its neighbours' neighbours'
     * neighbours. And so on.
     * 
     * Obviously, you'll have to employ recursion carefully.
     * 
     * Ingredients are returned as *indexes*, so, for instance,
     * if we find a related ingredient 'chicken' is stored at
     * index 7 in ingredients[][], then we store 7 in the
     * linked list of related ingredients.
     * 
     * The returned list MUST CONTAIN NO DUPLICATES.
     * 
     * And be smart about it, or you'll end up in an infinite
     * recursion! So think carefully about the base case(s)
     * and about what the recursive case must do.
     *
     * Example call:
     * 
     * Our test code may call your function in this way:
     * 
     * intNode *head=NULL;
     * head=related_k_dist(head,"rice",2,0);
     * 
     * After that call, 'head' must point to a linked list with
     * all the ingredients related to 'ride' up to a distance of
     * 2 away.
     * 
     * It's up to *you* to figure out what the 'dist' parameter
     * is for!
     * 
     */
    
    /*******
     * TO DO:
     * Complete this function
     *******/
	 
	 /* 
	 if (k < dist){return NULL;}
	 
	 int src_ing = ingredient_index(source_ingredient);
	 if (src_ing == -1){return NULL;}

	 intNode *head1;
	 intNode *head2;
	 intNode *arr[MAT_SIZE];
	 for (int i = 0; i < MAT_SIZE; i++){arr[i] = NULL;}
	 int arr_index1 = 0;
	 int arr_index2 = 0;
	 
	 for (int j = 0; j < MAT_SIZE; j++){if (AdjMat[src_ing][j] != 0){head1 = insertInt(head1, j);}}
	 
	 head2 = head1;
	 
	 while (head1 != NULL)
	 {
		 arr[arr_index1] = related_k_dist(NULL, ingredients[head1->x], k, dist + 1);
		 arr_index1++;
		 head1 = head1->next;
	 }
	 
	 while (arr_index2 < arr_index1)
	 {
		 head2 = merge_list(head2, arr[arr_index1]);
		 arr_index2++;
	 }

    return head2;
	 */
	
     if (k < dist){return h;}                                              //have gone past the intended distance... do nothing
	
	 int src_ing = ingredient_index(source_ingredient);                    //index of the source ingredient
	 if (src_ing == -1){return h;}                                         //if ingredient does not exist, do nothing 
	 
	 int searcher;
	 
	 //searcher = searchInt(h, src_ing);
	 //if (searcher == 0 && k > 0){h = insertInt(h, src_ing);}             //adds the source ingredient to the list if not already present if there will be atleast one recursion
	
	 for (int i = 0; i < MAT_SIZE; i++)                                    //going through all ingredients X available...
	 {
		 if (AdjMat[src_ing][i] != 0)                                      //...if an ingredient is related to the source...
		 {
		     searcher = searchInt(h, i); 
			 if (searcher == 0){h = insertInt(h, i);}                      //...and not already in the list, add it to the list...
			 
			 h = related_k_dist(h, ingredients[i], k, dist + 1);           //...and call the function on it
		 }
	 }
	
	 //if (dist == 0){h = remove_Int(h, src_ing);}
	
	 return h; 	                                                           //return the list
}

intNode *related_with_restrictions(char source_ingredient[MAX_STR_LEN], char avoid[MAX_STR_LEN], int k_source, int k_avoid)
{
    /*
     * This function returns a linked list that contains the indexes of
     * all ingredients related to source_ingredient[] with a distance
     * of at most k_source.
     * 
     * BUT, the list *must not contain* any ingredients related to avoid[]
     * (including avoid[] itself) by a distance of up to k_avoid.
     * 
     * Example:
     * 
     * intNode *head=NULL;
     * head=related_with_avoidance("rice", "nuts", 2, 0);
     * 
     * Should return a list of ingredients related to 'rice' by a distance 
     * of up to 2, NOT INCLUDING 'nuts'.
     * 
     * intNode *head=NULL;
     * head=related_with_avoidance("rice", "chicken", 2, 1);
     * 
     * Should return a list of ingredients related to 'rice' by a distance
     * of up to 2, NOT INCLUDING 'nuts' and any ingredients related
     * to 'nuts' with a distance of up to 1.
     * 
     */
    
    /****
     * TO DO:
     * Implement this function
     *****/
	 
	 intNode *src_head = NULL;                                                  //list head for the ingredients related to source_ingredient upto k_source distance
	 intNode *avd_head = NULL;                                                  //list head for the ingredients related to avoid upto k_avoid distance
	 int avd_index = ingredient_index(avoid);                                   //index of avoid
	 
	 src_head = related_k_dist(src_head, source_ingredient, k_source, 0);       //src_head initialised
	 avd_head = related_k_dist(avd_head, avoid, k_avoid, 0);                    //avd_head initialsed
	 avd_head = insertInt(avd_head, avd_index);                                 //avd_head did not have avoid itself... added
	 
	 src_head = clean_up(src_head, avd_head);                                   //all ingredients in the avd_head list removed from the src_head list
	 deleteList(avd_head);                                                      //avd_head list is now useless... discarded
	 
    return src_head;                                                            //required list returned
}

void substitute_ingredient(char recipe[10][MAX_STR_LEN], char to_change[MAX_STR_LEN])
{
  /*
   * *CRUNCHY!*
   * 
   * This function takes a recipe (which is an array of ingredients with up to 10
   * ingredients), and replaces the one in 'to_change' by *the most compatible
   * ingredient from the graph*
   * 
   * By most compatible, we mean the ingredient that appears most often with 
   * the remaining ingredients in the recipe.
   * 
   * The definition above may seem fuzzy, but it's not if you consider that the
   * weights in the adjacency matrix are meaningful.
   * 
   * As you see, nothing is returned - the result of this function is that the
   * ingredient 'to_change' is replaced in the recipe by the most compatible
   * ingredient given the graph that is *not already in the recipe*.
   * 
   * Assume that the input recipe is such that *all ingredients are in the
   * array of ingredients* (i.e. you don't have to worry about ingredients
   * that don't exists).
   * 
   * However, the recipe *may have less than 10 ingredients*, in which case
   * unused ingredients will be set to empty strings ("")
   */
  
   /*******
    * TO DO:
    * Complete this function!
    ******/
	/*
	int temp;
	int change_ind = ingredient_index(to_change);	
	int num_of_ing = find_Len(recipe) - 1;
	int ind_of_ing[num_of_ing];
	for (int i = 0; i < num_of_ing; i++)
	{
		temp = ingredient_index(recipe[i]);
		if (temp != change_ind){ind_of_ing[i] = temp;}
	}
	*/
	
	int all_ing[MAT_SIZE];                                             	//to hold the weightages of all the ingredients w.r.t the recipe ingredients
	initialise1(all_ing);                                               //all weightages initialised to -1
	
	int rec_ing[10];                                                    //to hold all the indexes of the recipe ingredients in AdjMat
	initialise2(recipe, rec_ing);                                       //all indexes initialised
	
	int change_ind1 = ingredient_index(to_change);                      //index of the ingredient to be changed in AdjMat
	int change_ind2 = find_index(recipe, to_change);                    //index of the ingredient to be changed in recipe
	
	int notIn;
	
	for (int i = 0; i < 10; i++)                                        //for each ingredients X in the recipe...
	{
		if (rec_ing[i] != -1 && rec_ing[i] != change_ind1)              //...given that its not the ingredient we want to change...
		{
			for (int j = 0; j < MAT_SIZE; j++)                          //...go over all the ingredients Y available...
			{
				notIn = not_in(rec_ing, j);
                if (notIn == 1)                                         //...and given that Y is not already in the recipe...
                {
					all_ing[j] += AdjMat[rec_ing[i]][j];                //...record its weightage w.r.t X
					//printf("%d %d %d %d %s %s\n", i, j, rec_ing[i], (int)AdjMat[rec_ing[i]][j], ingredients[rec_ing[i]], ingredients[j]);
				}				
			}
		}
	}
	
	/* for (int x = 0; x < 10; x++)
	{
		printf("%d\n", (int) rec_ing[x]);
	} */
	
	int max_ing = max(all_ing);                                         //gets the index of the ingredient with the highest weightage
	strcpy(recipe[change_ind2], ingredients[max_ing]);                  //ingredient substituted	
}

/*
void print()
{
	for (int i = 0; i < MAT_SIZE; i++)
	{
		printf("%s ", ingredients[i]);
		for (int j = 0; j < MAT_SIZE; j++)
		{
			printf("%d ", (int) AdjMat[i][j]);
		}
		printf("\n");
	}
}
*/


