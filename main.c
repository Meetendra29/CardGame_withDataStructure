#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"instructions.h"
#include"cards.h"
#include"display.h"
#include"gameplays.h"
#define KRED   "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define  KGRN   "\x1B[32m"


 card *player1;
 card *Computer;

 void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

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
    system("cls");
}


  int main() //MAIN function
{

   int n = 0;
   CARDS_GAME();
   while(n!=6)
  {
     int ch = 0;
     int key;
               createStack(&player1, 11);
               createStack(&Computer, 11);

   clrscr();

   card_games();
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
