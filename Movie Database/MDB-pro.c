/*
 *  CSC A48 - Winter 2019 - Assignment 1 starter
 * 
 *  (c) 2019 Marzieh Ahmadzadeh and Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout, and given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. At any point you can bring 
 * questions to your TAs or instructors during office hours. But please
 * remember:
 * 
 * - You should not post any assignment code on Piazza
 * - You should not share any part of your solution in any form
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Kazim, Asad Ali
 * Student Number: 1004714632
 * UTORid: kazimasa
 * Your instructor's name is: Paco Estrada
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Asad Ali Kazim
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/***************************************************************************/

typedef struct ScoreNode_struct
{
  int score;
  struct ScoreNode_struct *next;
}ScoreNode;

typedef struct MovieReview_struct
{
  char movie_title[MAX_STR_LEN];
  char movie_studio[MAX_STR_LEN];
  int year;
  float BO_total;
  ScoreNode *scores_head;
} MovieReview;

typedef struct ReviewNode_struct
{
  MovieReview review;
  struct ReviewNode_struct *next;
} ReviewNode;

ScoreNode *newScoreNode()
{
  ScoreNode *new_scores = NULL;

  new_scores = (ScoreNode *)calloc(1, sizeof(ScoreNode));

  if (new_scores != NULL)
  {
    new_scores->score = -1;
    new_scores->next = NULL;
  }
  else
  {
    printf("Sorry, could not initialise score list. Please try again\n");
  }

  return new_scores;
}

ScoreNode *insertScore(ScoreNode *head, int score)
{
  ScoreNode *latest_score = NULL;

  latest_score = newScoreNode();
  
  if (latest_score != NULL)
  {
    latest_score->score = score;
    latest_score->next = head;
    head = latest_score;
  }
  else
  {
    printf("Sorry, could not insert new score. Please try again\n");
  }

  return head;
}

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates a new, empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to empty values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *new_review = NULL;

    new_review = (ReviewNode *)calloc(1, sizeof(ReviewNode));

    if (new_review != NULL)
    {
      strcpy(new_review->review.movie_title, "");
      strcpy(new_review->review.movie_studio, "");
      new_review->review.year = -1;
      new_review->review.BO_total = -1;
      new_review->review.scores_head = newScoreNode();

      new_review->next = NULL;
    }

    return new_review;	// <--- This should change when after you implement your solution
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * In this case, the movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns a pointer to the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
      if (strcmp(p->review.movie_title, title) == 0 && strcmp(p->review.movie_studio, studio) == 0 && p->review.year == year)
      {
        return p;
      }
      p = p->next;
    }
         
    return p;	// <--- This should change when after you implement your solution
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *at the head* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = NULL;
    p = findMovieReview(title, studio, year, head);

    if ( p == NULL)
    {
      ReviewNode *new_review = newMovieReviewNode();
      if (new_review != NULL)
      {
        strcpy(new_review->review.movie_title, title);
        strcpy(new_review->review.movie_studio, studio);
        new_review->review.year = year;
        new_review->review.BO_total = BO_total;
        new_review->review.scores_head->score = score;

        new_review->next = head;

        head = new_review;
      }
    }
    else
    {
      p->review.scores_head = insertScore(p->review.scores_head, score);
    }
    return head;	// <--- This should change when after you implement your solution
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the length of the current linked list. This requires
   * list traversal.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    int count = 0;

    ReviewNode *p = head;

    while (p != NULL)
    {
      count++;
      p = p->next;
    }
    
    return count;	// <--- This should change when after you implement your solution
}

void printReviewScores(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
  ReviewNode *p = NULL;
  p = findMovieReview(title, studio, year, head);

  if (p != NULL)
  {
    ScoreNode *q = NULL;
    q = p->review.scores_head;

    while (q != NULL)
    {
      printf("%d\n", q->score);
      q = q->next;
    }
  }
  else
  {
    printf("Sorry, that movie does not exist at this point\n");
  }
}

float getAverageScore(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
  float avg = -1;
  float count = 0;
  float total = 0;

  ReviewNode *p = NULL;
  p = findMovieReview(title, studio, year, head);

  if (p != NULL)
  {
    ScoreNode *q = NULL;
    q = p->review.scores_head;

    while (q != NULL)
    {
      count++;
      total += q->score;
	  q = q->next;
    }

    avg = total/count;
  }

  return avg;
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the linked list. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = NULL;
    ReviewNode *q = NULL;

    if (strcmp(head->review.movie_title, title) == 0 && strcmp(head->review.movie_studio, studio) == 0 && head->review.year == year)
    {
      p = head->next;
      free(head);
      return p;
    }

    p = head;

    while (p != NULL)
    {
      q = p->next;

      if (q != NULL && strcmp(q->review.movie_title, title) == 0 && strcmp(q->review.movie_studio, studio) == 0 && q->review.year == year)
      {
         p->next = q->next;
         free(q);
         break;
      }

      p = q;
    }    

    return head;	// <--- This should change when after you implement your solution
}

void printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the linked list, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"
     * 
     * See the Assignment handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;
    p = head;

    while (p != NULL)
    {
      printf("%s\n%s\n%d\n%f\n*******************\n", p->review.movie_title, p->review.movie_studio, p->review.year, p->review.BO_total);

      p = p->next;
    }
}

void queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/ 
    ReviewNode *p = NULL;
    p = head;

    while (p != NULL)
    {
      if (strcmp(p->review.movie_studio, studio) == 0)
      {
        printf("%s\n%s\n%d\n%f\n*******************\n", p->review.movie_title, p->review.movie_studio, p->review.year,p->review.BO_total);
      }
      p = p->next;
    } 
}

void queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    ReviewNode *p = NULL;
    p = head;
    float avg;

    while (p != NULL)
    {
      avg = getAverageScore(p->review.movie_title, p->review.movie_studio, p->review.year, head);
      
      if (avg >= min_score && avg != -1)
      {
        printf("%s\n%s\n%d\n%f\n%f\n*******************\n", p->review.movie_title, p->review.movie_studio, p->review.year,p->review.BO_total, avg);
      }
      p = p->next;
    } 
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the linked list of movie reviews, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    
    ReviewNode *p = NULL;
    ReviewNode *q = NULL;

    p = head;

    while (p != NULL)
    {
      q = p->next;
      free(p);
      p = q;
    }

    return p;	// <--- This should change when after you implement your solution
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    int count = countReviews(head);   // length of the list... will come in handy trust me
    int i = 1;                        // this too lol

    ReviewNode *p = NULL;       //node currently being sorted
    ReviewNode *q = NULL;       //next node to be sorted
    ReviewNode *r = NULL;       //to be used for list traversal
    ReviewNode *s = NULL;       //to be used for list traversal... extra help :)
    
    //if only zero or one entries int the list
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    
    //tracking the second and third entries (third may not exist)
    p = head->next;
    q = p->next;

    //sorting the second entry  
    if (strcmp(head->review.movie_title, p->review.movie_title) > 0)
    {
      p->next = head;
      head->next = q;
      head = p;
    }
    
    //moving to the third entry (may not exist)
    p = q;
    
    //continue till the end of the entire list is reached
    while (p != NULL)
    {
      //tracking the next entry in list to be sorted 
      q = p->next;

      //list traversal pointers initialised
      r = head;
      s = head->next;

      //comparing with the current head of the sorted portion of the list
      if (strcmp(head->review.movie_title, p->review.movie_title) > 0)
      {
        p->next = head;
        head = p;
      }
      //moving on until current entry is sorted or the end of the sorted list is reached
      else while (s != p)
      {
        //checking whether the current entry under inspection is greater
        if (strcmp(s->review.movie_title, p->review.movie_title) > 0)
        {
          //wedging it in before the first entry greater
          r->next = p;
          p->next = s;
          break;
        }
        //moving the list traversal pointers forward
        r = s;
        s = r->next;       
      }
      //setting the next entry to be sorted
      p = q;
    }

    //all this has made us lose the termination point of our list!
    //have to manually insert NULL as *next at the last entry
    
    //start at the head...
    p = head;

    //...go to the end...
    while (i != count)
    {
      p = p->next;
      i++;
    }

    //...and terminate the list
    p->next = NULL;

    return head;	// <--- This should change when after you implement your solution
}