#ifndef GAMEPLAYS_H_INCLUDED
#define GAMEPLAYS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"instructions.h"
#include"cards.h"
#include"display.h"
#define KRED   "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define  KGRN   "\x1B[32m"



int p1_roundScore=0;
int comp_roundScore=0;

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


card * card_a;
card * card_b;
card * card_c;


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



#endif // GAMEPLAYS_H_INCLUDED
