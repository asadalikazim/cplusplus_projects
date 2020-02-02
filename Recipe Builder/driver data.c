/*
    * Just a quick demo of how to set up the graph and call
    * the functions you are supposed to implement
    */
   
   
   intNode *head=NULL;
   char recipe[10][MAX_STR_LEN]={"fresh breadcrumbs",
				 "artichoke hearts",
				 "quinoa",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};
   
   // Load the ingredients graph - you control which size
   // you want by commenting/uncommenting the corresponding
   // #define at the top of 'ingredient_graph.c'
   load_ingredients();
   printf("------- The available ingredients should appear above this line -------\n");
   // Call related ingredients
   printf("\n ****** Related ingredients for quinoa:\n");
   related_ingredients("quinoa");  // Make sure this
				   // ingredient exists
   
   printf("\n ****** Related to 'quinoa' k-dist, k=0\n");
   head=related_k_dist(head,"quinoa",0,0);
   print_ingredients(head);
   head=deleteList(head);
 
   printf("\n ****** Related to 'quinoa' k-dist, k=1\n");
   head=related_k_dist(head,"quinoa",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=0, k_dest=0;\n");
   head=related_with_restrictions("quinoa","artichoke hearts",0,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=0;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,2);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** substituting ingredient 'quinoa' in recipe\n");
   substitute_ingredient(recipe,"quinoa");
   for (int i=0; i<10; i++)
     if (strlen(recipe[i])>0) printf("%s\n",recipe[i]);
   

   /* The OUTPUT of my solution to this assignment for the sample calls above is:

 ****** Related ingredients for quinoa:
artichoke hearts
sunflower seeds

 ****** Related to 'quinoa' k-dist, k=0
sunflower seeds
artichoke hearts

 ****** Related to 'quinoa' k-dist, k=1
gruyere cheese
turkey
medium shrimp
quinoa
soymilk
sunflower seeds
artichoke hearts

 ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=0, k_dest=0;
sunflower seeds

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=0;
artichoke hearts
sunflower seeds
soymilk
quinoa
medium shrimp
turkey
gruyere cheese

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2;
sunflower seeds
soymilk

 ****** substituting ingredient 'quinoa' in recipe
fresh breadcrumbs
artichoke hearts
gruyere cheese

   You can use that as a reference, but BEWARE the fact that though I am confident my
   solution is correct *I have not had the time to thoroughly test it*
   (you should know by now what that means)
   
   */
          
   // Insert ALL of your tests below this line, make sure you test your 
   // code thoroughly.
   // Verify your code's work by checking *on paper* for lists of
   // ingredients your tests ask for!
   // Time to practice those testing skills!
   