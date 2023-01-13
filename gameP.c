#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define KRED   "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define  KGRN   "\x1B[32m"

 typedef struct card
{
   int energy,heal,karma,power;
   struct card *next;
}card;

 card *createCards()
{
    card *ptr = (card*)malloc(sizeof(card));

    ptr->energy = 500+rand()%400;
    ptr->heal   = 100+rand()%200;
    ptr->karma  = 50+rand()%50;
    ptr->power  = 1000+rand()%501;

    return ptr;
}

 void createStack(card **head, int no_cards)
{
    if(*head==NULL)
        *head=createCards();

    (*head)->next=NULL;

    int i=0;

    while(i<no_cards-1)
    {
        card *tmp=createCards();
        tmp->next=*head;
        *head=tmp;

        i++;
    }
}

 void insert_List(card **head)
{
    for(int i=0;i<5;i++)
   {
     card *tmp = createCards();
     tmp->next = *head;
     *head = tmp;
   }
}

 card *player1;
 card *Computer;

 int p1_roundScore;
 int comp_roundScore;

 void pop(card **head)
{
    card *tmp=*head;
    (*head)=(*head)->next;

    free(tmp);
}

 void del_beg(card **h)
{
        card *tmp=*h;
        *h=(*h)->next;
        free(tmp);
}


 void del_search_key(card **h,int key)
{
    card *crt=*h;
	if((*h)->power==key)
		del_beg(h);
	else
	{
		while(crt->next->power != key)
			crt = crt->next;
		card *tmp = crt->next;
		crt->next =tmp->next;
		free(tmp);
	}
}


 void power_show(card *P)
{
   card *cur = P;
   while(cur!=NULL)
  {
    printf("\n             %d",cur->power);
    cur = cur->next;
  }
}

  void displayCard(card *pik)
{
      printf("\n                    _____________________________________ ");
      printf("\n                   |                                     |");
      printf("\n                   |   POWER :   %d                    |", pik->power);
      printf("\n                   |                                     |");
      printf("\n                   |                                     |");
      printf("\n                   |   ENERGY:   %d                     |", pik->energy);
      printf("\n                   |                                     |");
      printf("\n                   |                                     |");
      printf("\n                   |   HEAL  :   %d                     |", pik->heal);
      printf("\n                   |                                     |");
      printf("\n                   |                                     |");
      printf("\n                   |   KARMA :    %d                     |", pik->karma);
      printf("\n                   |_____________________________________|");

}

 void Display_list(card *head)
{
  card *cur = head;

  while(cur!=NULL)
 {
   displayCard(cur);
   printf("\n");
   cur = cur->next;
 }
}

  void displayCard_2( card *a, card*b)
 {
        printf("\n");
        printf("\n              -----------------------------          ----------------------------- ");
        printf("\n              |                           |          |                           |");
        printf("\n              |   POWER :   %d          |          |   POWER :   %d          |",a->power,b->power);
        printf("\n              |                           |          |                           |");
        printf("\n              |                           |          |                           |");
        printf("\n              |   ENERGY:   %d           |          |   ENERGY:   %d           |", a->energy,b->energy);
        printf("\n              |                           |          |                           |");
        printf("\n              |                           |          |                           |");
        printf("\n              |   HEAL  :   %d           |          |   HEAL  :   %d           |", a->heal,b->heal);
        printf("\n              |                           |          |                           |");
        printf("\n              |                           |          |                           |");
        printf("\n              |   KARMA :    %d           |          |   KARMA :    %d           |", a->karma,b->karma);
        printf("\n              |                           |          |                           |");
        printf("\n              -----------------------------          -----------------------------");
    }


   void displayCard_3( card *Card, card*card_2,card*card_3)
 {
        printf("\n");
        printf("%s",KCYN);
 		printf("                          Card A                                Card B                                    Card C\n");
 		printf("%s",KNRM);
        printf("\n              -----------------------------          -----------------------------            ----------------------------- ");
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |   POWER :   %d          |          |   POWER :   %d          |            |   POWER :   %d          |",Card->power,card_2->power,card_3->power);
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |   ENERGY:   %d           |          |   ENERGY:   %d           |            |   ENERGY:   %d           |", Card->energy,card_2->energy,card_3->energy);
        printf("\n              |                           |          |                           |            |                           | ");
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |   HEAL  :   %d           |          |   HEAL  :   %d           |            |   HEAL  :   %d           |", Card->heal,card_2->heal,card_3->heal);
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              |   KARMA :    %d           |          |   KARMA :    %d           |            |   KARMA :    %d           |", Card->karma,card_2->karma,card_3->karma);
        printf("\n              |                           |          |                           |            |                           |");
        printf("\n              -----------------------------          -----------------------------            -----------------------------");
        printf("\n");
}

   void printTable(int p,int q)
{
    printf("\n\n                       ______________________________");
    printf("\n                      | Player1      |  Computer     |");
    printf("\n                      |--------------|---------------|");
    printf("\n                      |              |               |");
    printf("\n                      |      %d       |      %d        |", p,q);
    printf("\n                      |______________|_______________|\n");
    printf("\n\n_____________________________________NEXT ROUND__________________________________________");
    printf("\n\n");
}

   void printTable_2(int p)
{
    printf("%s",KMAG);
    printf("  \n                                     THE ROUND RESULT IS :            \n");
    printf("%s",KNRM);
    printf("\n\n                                     __________________");
    printf("\n                                     | Player points   |");
    printf("\n                                     |-----------------|");
    printf("\n                                     |                 |");
    printf("\n                                     |     %d/5         |", p);
    printf("\n                                     |_________________|\n\n");
}

 void You_win()
{
      printf("\n");
      printf("\n                 *     *  **********  *        *     *       *  *  *      * ");
      printf("\n                  *   *   *	   *  *        *     *       *  *  * *    * ");
      printf("\n                   * *    *	   *  *        *     *       *  *  *  *   * ");
      printf("\n                    *     *	   *  *        *     *	 *   *  *  *   *  * ");
      printf("\n                    *     *	   *  *	       *     *	* *  *  *  *    * * ");
      printf("\n		    *     *	   *  *	       *     * *   * *  *  *      * ");
      printf("\n		    *     **********  **********     *       *  *  *      * \n");
}

 void You_lost()
{
      printf("\n");
      printf("\n                 *     *  **********  *        *     *         *********  *******  *********  ");
      printf("\n                  *   *   *	   *  *        *     *         *       *  *            *      ");
      printf("\n                   * *    *	   *  *        *     *         *       *  *            *      ");
      printf("\n                    *     *	   *  *        *     *	       *       *  *******      *      ");
      printf("\n                    *     *	   *  *	       *     *	       *       *        *      *      ");
      printf("\n		    *     *	   *  *	       *     *         *       *        *      *      ");
      printf("\n		    *     **********  **********     * ******  *********  *******      *    \n");
}

 void CARDS_GAME()
{
 printf("\n\n\n");
 printf("\n       *********  *******  ******* ********  ********    *********  *******  **    ** ********   ");
 printf("\n       *         *       * *     * **      * *           *         *       * * *  * * *          ");
 printf("\n       *         *       * *     * **      * *           *         *       * *  **  * *          ");
 printf("\n       *         ********* ******* **      * ********    *    **** ********* *      * ********   ");
 printf("\n       *         *       * **      **      *        *    *    *  * *       * *      * *          ");
 printf("\n       *         *       * *  *    **      *        *    *    *  * *       * *      * *          ");
 printf("\n       ********* *       * *   *   ********  ********    ******  * *       * *      * ********  \n\n ");
}

  void displayMenu()
{
    printf("\n <1>  POWER");
    printf("\n <2>  ENERGY");
    printf("\n <3>  HEAL");
    printf("\n <4>  KARMA");

}

 void game_inst()
{
   printf("\n                                 GAME INSTRUCTIONS\n");
   printf("\n                   1. You Will Play This Game As PLAYER Against The Computer.");
   printf("\n                   2. Both The Players Will Be Given 5 Cards To Play.      ");
   printf("\n                   3. After Every Round, Each Player's Card Would Be Removed.  ");
   printf("\n                   4. After 5th Round The Final Score Will Be Displayed.     ");
   printf("\n                   5. Player With Higher Score Will Win.      ");
   printf("\n                   6. You Have To Choose Any 1 Property of Card To Proceed.");
   printf("\n                   7. A Point Will Be Increased If The Vaue Of Chosen Property Of Card");
   printf("\n                      Is Greater Than Opponent's Card.");
   printf("\n                   8. You Need To Input 1/2/3/4 Against The Input Coulum.\n\n");
   printf("\n                                     PROPERTIES ");
   printf("\n                      1. POWER ");
   printf("\n                      2. ENERGY ");
   printf("\n                      3. HEAL ");
   printf("\n                      4. KARMA");
}

 void game_inst_2()
{
   printf("\n                                 GAME INSTRUCTIONS\n");
   printf("\n                   1. You Will Play This Game As PLAYER Against The Computer.");
   printf("\n                   2. Both The Players Will Have 11 Rounds To Play.      ");
   printf("\n                   3. After Every Round, Each Player's Card Would Be Removed.  ");
   printf("\n                   4. After 11 th Round The Final Score Will Be Displayed.     ");
   printf("\n                   5. Player With Higher Score Will Win.  ");
   printf("\n                   6. You Have To Choose Any 1 Property of Card To Proceed.");
   printf("\n                   7. A Point Will Be Increased If The Sum Of The Value Of Chosen Property Of Card");
   printf("\n                      By Player And Other Propert By Computer Is Greater Than Opponent's Card.");
   printf("\n                   8. Suppose You Picked HEAL Property And Comp Chose POWER Property Then The SUM(power + heal)");
   printf("\n                      Will Be The Criteria For Winning .");
   printf("\n                   8. You Need To Input 1/2/3/4 Against The Input Coulum.\n\n");
   printf("\n                                     PROPERTIES ");
   printf("\n                      1. POWER ");
   printf("\n                      2. ENERGY ");
   printf("\n                      3. HEAL ");
   printf("\n                      4. KARMA");
}


 void game_inst_3()
{
   printf("\n                                 GAME INSTRUCTIONS\n");
   printf("\n                   1. You Will Play This Game As PLAYER .");
   printf("\n                   2. Enter The Number Of Rounds You Want To Play . ");
   printf("\n                   3. Each Round Contains Five Question .");
   printf("\n                   4. A Set Of Five Questions Will Appear On Screen One By One .");
   printf("\n                   5. You Will Be Given 4 Options For Every Question.");
   printf("\n                   6. After Completing One Round The score Will Be Shown .     ");
   printf("\n                   7. Now You Will Be Proceeded To The Next Round If Chosen .");

}

 void game_inst_4()
{
   printf("\n                                 GAME INSTRUCTIONS\n");
   printf("\n                   1. You Will Play This Game As PLAYER .");
   printf("\n                   2. There Are 5 Rounds  To Play . ");
   printf("\n                   3. Each Round Is Performed Automatically .");
   printf("\n                   4. This Is A System Performed Game .");
   printf("\n                   5. Each Round Calculates Average Of Attributes Of Card .");
   printf("\n                   6. The Player With Higher Average Wins .     ");
   printf("\n                   7. Press Enter Twice After Each Round .");

}


 void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

 void myflush ( FILE *in )
{
    int ch;

    do
        ch = fgetc ( in );
    while ( ch != EOF && ch != '\n' );

    clearerr ( in );
}

  void mypause ( void )
{
    printf("%s",KYEL);
    printf("\n\n                    PRESS [ENTER] TO CONTINUE...");
    printf("%s",KNRM);
    fflush ( stdout );
    getchar();
}

 void clrscr(void)
{
    system("clear");
}


 void play_prateek(card *a,card *b)  // GAME 1
{
   int choice;
   int skr_a = 0;
   int skr_b = 0;

   game_inst();

    myflush ( stdin );
    mypause();
    clrscr();

    while(a && b)
   {
     printf("%s",KCYN);
     printf("\n                               PLAYER's CARD");
     printf("%s",KNRM);
     displayCard(a);

     printf("\n\n      ENTER THE PROPERTY YOU WANT TO PLAY WITH (1/2/3/4) : ");
     scanf("%d",&choice);

     printf("%s",KCYN);
     printf("\n                   PLAYER's CARD          v/s           COMPUTER's CARD");
     printf("%s",KNRM);
     displayCard_2(a,b);

      switch(choice)
     {
       case 1 : if(a->power > b->power)
                skr_a++;
                else if(a->power < b->power)
                skr_b++;break;

       case 2 : if(a->energy > b->energy)
                skr_a++;
                else if(a->energy < b->energy)
                skr_b++;break;

       case 3 : if(a->heal > b->heal)
                skr_a++;
                else if(a->heal < b->heal)
                skr_b++;break;

       case 4 : if(a->karma > b->karma)
                skr_a++;
                else if(a->karma < b->karma)
                skr_b++;break;
     }

      printTable(skr_a,skr_b);

      a = a->next;
      b = b->next;

      myflush ( stdin );
      mypause();
      clrscr();

   }
      if(skr_a > skr_b)
     {
       printf("\n                        HERE IS THE FINAL SCORE ");
       printTable(skr_a,skr_b);
       You_win();
     }

      else
     {
      printf("\n                        HERE IS THE FINAL SCORE ");
      printTable(skr_a,skr_b);
      You_lost();
     }

      mypause();
      clrscr();
}

 int p1_currScore=0;
 int comp_currScore=0;

  void gameplay_mayank(card **p1, card **comp, int n)    // GAME 2
{
    p1_currScore=0;
    comp_currScore=0;

    int choice1, choice2;

    clrscr();

   printf("%s",KCYN);
     printf("\n                         PLAYER's CARD");
     printf("%s",KNRM);
    displayCard(*p1);

    if(n%2==0)
    {
        printf("\n           Player1, you get the first pick \n");

        do{
        printf("\n           Player1, choose the property to play with (e.g- 3 for HEAL): ");
        displayMenu();
        printf("\n           ----> ");

        scanf("%d", &choice1);

        if(choice1<1 || choice1>4)
            printf("\n           Please enter a legal value (between 1-4)");
        }while(choice1<1 || choice1>4);

        if(choice1==1)
            printf("\n           player1 has selected to play with POWER");

        if(choice1==2)
            printf("\n           player1 has selected to play with ENERGY");

        if(choice1==3)
            printf("\n           player1 has selected to play with HEAL");

        if(choice1==4)
            printf("\n           player1 has selected to play with KARMA");


    }

    else
    {
        printf("\n           Computer gets the first pick \n");
        choice1=1+(rand()%4);

        if(choice1==1)
            printf("\n           Comp has selected to play with POWER\n");

        if(choice1==2)
            printf("\n           Comp has selected to play with ENERGY\n");

        if(choice1==3)
            printf("\n           Comp has selected to play with HEAL\n");

        if(choice1==4)
            printf("\n           Comp has selected to play with KARMA\n");


    }



    switch(choice1)
    {
        case 1:
        {
                p1_currScore+=((*p1)->power);
                comp_currScore+=((*comp)->power);
                break;

        }


        case 2:
        {
                p1_currScore+=((*p1)->energy);
                comp_currScore+=((*comp)->energy);
                break;
        }


        case 3:
        {
                p1_currScore+=((*p1)->heal);
                comp_currScore+=((*comp)->heal);
                break;
        }


        case 4:
        {

                p1_currScore+=((*p1)->karma);
                comp_currScore+=((*comp)->karma);
                break;
        }
    }

    printf("\n           The current round-scores are as follows: \n");
    printf("%s",KMAG);
    printf("\n           Player1        : %d ", p1_currScore);
    printf("\n           Computer ji    : %d", comp_currScore);
    printf("%s",KNRM);

    if(n%2==0)
        printf("\n           Now computer has a chance to pick from the remaining three options");

    else
        printf("\n           Now player1 has a chance to pick from the remaining three options");

    n=n+1;


    if(n%2==0)
    {
        printf("\n           Player1, you get the second pick (don't choose the same option as computer did) \n");

        do{
        printf("\n           Player1, choose the property to play with (e.g- 3 for HEAL): ");
        displayMenu();
        printf("\n----> ");

        scanf("%d", &choice2);

        if(choice2<1 || choice2>4)

            printf("\n           Please enter a legal value (between 1-4)");

        if(choice1==choice2)

            printf("\n           Player1, please pick a different option");

        }while(choice2<1 || choice2>4||choice2==choice1);

        if(choice2==1)
            printf("\n           player1 has selected to play with POWER");

        if(choice2==2)
            printf("\n           player1 has selected to play with ENERGY");

        if(choice2==3)
            printf("\n           player1 has selected to play with HEAL");

        if(choice2==4)
            printf("\n           player1 has selected to play with KARMA");


    }

    else
    {
        printf("\n           Now, its computer's turn to pick ");
        do
        {
        choice2=1+(rand()%4);
        }while(choice2==choice1);

        if(choice2==1)
            printf("\n           Comp has selected to play with POWER");

        if(choice2==2)
            printf("\n           Comp has selected to play with ENERGY");

        if(choice2==3)
            printf("\n           Comp has selected to play with HEAL");

        if(choice2==4)
            printf("\n           Comp has selected to play with KARMA");


    }

    delay(6);

    switch(choice2)
    {
        case 1:
        {
                p1_currScore+=((*p1)->power);
                comp_currScore+=((*comp)->power);
                break;
        }


        case 2:
        {
                p1_currScore+=((*p1)->energy);
                comp_currScore+=((*comp)->energy);
                break;
        }


        case 3:
        {
                p1_currScore+=((*p1)->heal);
                comp_currScore+=((*comp)->heal);
                break;
        }


        case 4:
        {
                p1_currScore+=((*p1)->karma);
                comp_currScore+=((*comp)->karma);
                break;
        }
    }

     printf("\n\n This was the card you were playing against");

     printf("%s",KCYN);
     printf("\n                   PLAYER's CARD          v/s           COMPUTER's CARD");
     printf("%s",KNRM);
     displayCard_2(*p1,*comp);

    printf("\n           The current round-scores are as follows: \n");
    printf("%s",KMAG);
    printf("\n           Player1        : %d ", p1_currScore);
    printf("\n           Computer ji    : %d", comp_currScore);
    printf("%s",KNRM);

    if(p1_currScore>comp_currScore)
    {
        printf("\n\n           player1 gets the point \n");
        p1_roundScore+=1;
        comp_roundScore+=0;
    }

    else if(p1_currScore<comp_currScore)
    {
        printf("\n\n           Computer gets the point \n");
        p1_roundScore+=0;
        comp_roundScore+=1;
    }

    else if(p1_currScore==comp_currScore)
    {
        printf("\n           No one gets any point \n");
        p1_roundScore+=0;
        comp_roundScore+=0;
    }

    delay(1);

    pop(p1);
    pop(comp);

    printTable(p1_roundScore,comp_roundScore);
       myflush ( stdin );
      mypause();
      clrscr();
}

  card *card_a;
  card *card_b;
  card *card_c;

 void playgame_satyaki(card**a, card**b, card**c)  //Game 3
{
	int p1_skr=0;
	printf("\n Player, here are your cards to play with: \n");
	displayCard_3(*a,*b,*c);
	for(int i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
			{
				int choice,opt;
				printf("\n Q1. The sum of Power of which two cards is the highest?\n");
				printf("\n <1> A and B\t<2> A and C");
				printf("\n <3> B and C\t<4> None\n");
				printf("\nEnter your choice: ");
				scanf("%d",&choice);
				printf("\n");
				if(choice>4)
				{
					printf("There is no such option\n");
					break;
				}

				int max=(*a)->power+(*b)->power;
				if((*a)->power+(*c)->power>max && (*a)->power+(*c)->power>(*b)->power+(*c)->power)
				{
					max=(*a)->power+(*c)->power;
					opt=2;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else if((*b)->power+(*c)->power>max && (*b)->power+(*c)->power>(*a)->power+(*c)->power)
				{
					max=(*b)->power+(*c)->power;
					opt=3;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else
				{
					opt=1;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				delay(3);
				break;
			}
			case 1:
			{
				printf("\n");
				int choice,sum;
				printf(" Q2. When the Karma of the three cards are added, what is the resultant karma?\n");
				printf("\nEnter your answer: ");
			    scanf("%d",&choice);
			    printf("\n");
				sum=(*a)->karma+(*b)->karma+(*c)->karma;
				if(choice==sum)
				{
					printf("Your answer is correct\n");
					p1_skr++;
				}
				else
					printf("Your answer is incorrect\n");
				delay(3);
				break;
			}
			case 2:
			{
				int choice,opt;
				printf("\n Q3. The sum of Energy of which two cards is the lowest?\n");
				printf("\n <1> A and B\t<2> A and C");
				printf("\n <3> B and C\t<4> None\n");
				printf("\nEnter your choice: ");
				scanf("%d",&choice);
				printf("\n");
				if(choice>4)
				{
					printf("There is no such option\n");
					break;
				}

				int min=(*a)->energy+(*b)->energy;
				if((*a)->energy+(*c)->energy<min && (*a)->energy+(*c)->energy<(*b)->energy+(*c)->energy)
				{
					min=(*a)->energy+(*c)->energy;
					opt=2;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else if((*b)->energy+(*c)->energy<min && (*b)->energy+(*c)->energy<(*a)->energy+(*c)->energy)
				{
					min=(*b)->energy+(*c)->energy;
					opt=3;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else
				{
					opt=1;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				delay(3);
				break;
			}
			case 3:
			{
				int ans;
				printf("\n Q4. What is the value of the square of last digit of Heal attribute of card C?\n(eg: square of 9 in case 129)\n");
				printf("\nEnter your answer: ");
				scanf("%d",&ans);
				printf("\n");
				int s = (*c)->heal % 10;
				int sq = s * s;
				if(ans == sq)
				{
					printf("Your answer is correct\n");
					p1_skr++;
				}
				else
					printf("Your answer is incorrect\n");
				delay(3);
				break;
			}
			case 4:
			{
				printf("\n Q5. The karma of which card is closest to 50\n(eg: 52 is closer to 50 than 46)?\n");
				printf("\n <1> A\t<2> B");
				printf("\n <3> C\t<4> None\n");
				int s1,s2,s3;
				if((*a)->karma > 50)
					s1 = (*a)->karma - 50;
				else if((*a)->karma < 50)
					s1 = 50 - (*a)->karma;
				if((*b)->karma > 50)
					s2= (*b)->karma - 50;
				else if((*b)->karma < 50)
					s2= 50 - (*b)->karma;
				if((*c)->karma > 50)
					s3= (*c)->karma - 50;
				else if((*c)->karma < 50)
					s3= 50 - (*c)->karma;
				int opt;
				int choice;
				printf("\nEnter your choice : ");
				scanf("%d",&choice);
				printf("\n");
				if(choice>4)
				{
					printf("There is no such option\n");
					break;
				}
				if(s1<s2 && s1<s3)
				{
					opt=1;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else if(s2<s1 && s2<s3)
				{
					opt=2;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else if(s3<s1 && s3<s2)
				{
					opt=3;
					if(choice==opt)
					{
						printf("Your answer is correct\n");
						p1_skr++;
					}
					else
						printf("Your answer is incorrect\n");
				}
				else if(s1==s2 || s1==s3 || s2==s3)
					printf("Your answer is correct\n");
				break;
			}
		}
	}
	myflush ( stdin );
    mypause();
    clrscr();

    if(p1_skr>=4)
    	printf("\n                                       You scored well in this round                          \n");
    else
    	printf("\n                                       You can score better                           \n");
	pop(a);
	pop(b);
	pop(c);
	printTable_2(p1_skr);
        mypause();
        clrscr();
}


  void best_card_adhyan(card *a, card *b)   //GAME 4
{
	int a_stat = 0, b_stat = 0, a_score = 0, b_score = 0,i=0;
	while(i<5)
    {
	a_stat = (a->power + a->energy + a->heal + a->karma)/4;
    b_stat = (b->power + b->energy + b->heal + b->karma)/4;
	printf("\n\n\t\t\t             *BEST CARD MODE*\n\n");
	 printf("%s",KCYN);
     printf("\n                   PLAYER's CARD          v/s           COMPUTER's CARD");
     printf("%s",KNRM);
    displayCard_2(a,b);
    delay(3);
    printf("%s",KMAG);
    printf("\n\nFollowing is the average of attributes of each cards :\n ");
    printf("%s",KNRM);

    printf("\n                            -------------------------------------");
    printf("\n                            | Player1 STATS     | Computer STATS|");
    printf("\n                            |-------------------|---------------|");
    printf("\n                            |                   |               |");
    printf("\n                            |      %d          |     %d       |",a_stat,b_stat);
    printf("\n                            |                   |               |");
    printf("\n                            ------------------------------------");
    delay(3);
    if(a_stat > b_stat)
    	{a_score++;
    	 printf("\n\n\n                                          **YOU WON**\n");}
    else if(b_stat > a_stat)
        {b_score++;
         printf("\n\n\n                                            **YOU LOST**\n");}

    else if (b_stat == a_stat)
    {
    	a_score++;
    	b_score++;
    	printf("\nOOPS ! YOU SCORE TIED \n");
    }
    printTable(a_score, b_score);
        a = a->next;
        b = b->next;
        i++;

       mypause();
       clrscr();
      }

      if(a_score>b_score)
     {
        You_win();
        mypause();
        clrscr();
     }

      else
     {
       You_lost();
       mypause();
       clrscr();
     }
}



  int main() //MAIN funtion
{

   int n = 0;

   while(n!=6)
  {
     int ch = 0;
     int key;
               createStack(&player1, 11);
               createStack(&Computer, 11);

   clrscr();

   CARDS_GAME();
   printf("\n\n\n\n   	             1.PLAY WITH RANDOM CARDS");
   printf("\n                     2.GAME - EQUAL HANDS SUM ");
   printf("\n                     3.BRAIN GAME WITH CARDS");
   printf("\n                     4.LUCK OF AVERAGE");
   printf("\n                     5.ADMIN MODE");
   printf("\n                     6.EXIT");



   printf("\n\n                     Enter Your Choice :");

   scanf(" %d",&n);

   clrscr();

    switch(n)
   {
     case 1 : printf("\n");
              printf("%s",KRED);
              printf("\n                              ***PLAY WITH RANDOM CARDS***\n");
              printf("%s",KNRM);
              card *Z = NULL;
              insert_List(&Z);

              card *X = NULL;
              insert_List(&X);

              play_prateek(Z,X);break;


	case 2 :  printf("\n");
              printf("%s",KRED);
              printf("\n                              ***GAME - EQUAL HANDS SUM***\n");
              printf("%s",KNRM);
              game_inst_2();
              myflush(stdin);
              mypause();

              int i=0;

              while(i<11)
              {
                      gameplay_mayank(&player1, &Computer, i);
                        i++;
              }

                        if(p1_roundScore>comp_roundScore)
                       {    You_win();
                           mypause();
                           clrscr();
                       }

                       else if(p1_roundScore==comp_roundScore)
                       {
			   printf("Score Tied!!!");
                           myflush(stdin);
              		   mypause();
                           clrscr();
                       }

                        else
                       {
			      You_lost();
 		             mypause();
                             clrscr();
                       }
                  break;

    case 3 :   printf("\n");
               printf("%s",KRED);
              printf("\n                              ***BRAIN GAME WITH CARDS***\n");
              printf("%s",KNRM);
               int j;
               game_inst_3();

               myflush ( stdin );
               mypause();
                printf("%s",KMAG);
                printf(" \n\n\n\nEnter the number of rounds you want to play : \n");
               printf("%s",KNRM);
               scanf("%d",&j);
               clrscr();
               createStack(&card_a, j);
               createStack(&card_b, j);
               createStack(&card_c, j);
               int k=0;
               while(k<j)
                 {
   		            playgame_satyaki(&card_a, &card_b, &card_c);
                   k++;
                  }

                 break;

    case 4 :  printf("\n");
              printf("%s",KRED);
              printf("\n                              ***LUCK OF AVERAGE***\n");
              printf("%s",KNRM);
              game_inst_4();
              myflush(stdin);
              mypause();
              clrscr();

              card *P = NULL;
              insert_List(&P);
              card *Q = NULL;
              insert_List(&Q);
              best_card_adhyan(P, Q);
              break;



   case 5 :   printf("\n");
              card *M = NULL;
              insert_List(&M);
              while(ch!=3)
             {
              clrscr();
              printf("\n\n\n");
              printf("%s",KRED);
              printf("\n                                   ***ADMIN MODE***\n");
              printf("%s",KNRM);
               printf("\n\n\n\n                   1.DISPLAY ");
               printf("\n                   2.DELETE  ");
               printf("\n                   3.EXIT  ");
               printf("\n\n                  Enter Your Choice : ");
               scanf("%d",&ch);

               clrscr();

                 switch(ch)
                {
                   case 1 : Display_list(M);
                            myflush(stdin);
                            mypause();
                            break;

                   case 2 : printf("\n\n                    Here are the powers of 5 cards which you can delete");
                            power_show(M);
                            printf("\n\n                     Write the power of the card to be deleted :");
                            scanf("%d",&key);
                            printf("\n\n                     GO TO DISPLAY OPTION AGAIN TO SEE IF THE CARD IS DELETED");
                            del_search_key(&M,key);
                            myflush(stdin);
                            mypause();
                            break;

                }

              }break;


     case 6 : exit(0);
   }

  }
}

