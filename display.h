#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define KRED   "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define  KGRN   "\x1B[32m"

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

void printTable(int p,int q)
{
    printf("\n                               ---------------------------------");
    printf("\n                                | Player1      |  Computer     |");
    printf("\n                                |--------------|---------------|");
    printf("\n                                |              |               |");
    printf("\n                                |      %d       |      %d        |", p, q);
    printf("\n                                |              |               |");
    printf("\n                                --------------------------------");
    printf("\n_____________________________________NEXT ROUND__________________________________________");
    printf("\n\n");
}
void printTable_2(int p)

{   printf("%s",KMAG);
    printf("  \n                                     THE ROUND RESULT IS :            \n");
    printf("%s",KNRM);
    printf("\n\n                                    ___________________");
    printf("\n                                     | Player points   |");
    printf("\n                                     |-----------------|");
    printf("\n                                     |                 |");
    printf("\n                                     |     %d/5         |", p);
    printf("\n                                     |_________________|\n\n");
    printf("\n_____________________________________NEXT ROUND__________________________________________");
}

void displayMenu()
{
    printf("\n <1>  POWER");
    printf("\n <2>  ENERGY");
    printf("\n <3>  HEAL");
    printf("\n <4>  KARMA");

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
 delay(3);
     printf("\n\n\n\n\n\n\n\n\t\t\t\t        *****          ****          ******       ******         \n");
     delay(1);
     printf(" \t\t\t\t       *              *    *         *     *      *     *         \n");
     delay(1);
     printf(" \t\t\t\t      *              *      *        *     *      *      *         \n");
     delay(1);
     printf(" \t\t\t\t     *              *        *       *****        *      *         \n");
     delay(1);
     printf(" \t\t\t\t    *              *          *      *     *      *      *         \n");
     delay(1);
     printf(" \t\t\t\t    *             *            *     *     *      *     *         \n");
     delay(1);
     printf(" \t\t\t\t    *            *              *    *     *      ******           \n");
     delay(1);
     printf(" \t\t\t\t    *            ****************             \n");
     delay(1);
     printf(" \t\t\t\t    *            *              *     *****       *******    **       *       ****         \n");
     delay(1);
     printf(" \t\t\t\t    *            *              *    *     *         *       * *      *     *      *         \n");
     delay(1);
     printf(" \t\t\t\t    *            *              *    *               *       *  *     *     *      *         \n");
     delay(1);
     printf(" \t\t\t\t     *           *              *     ****           *       *   *    *     *      *         \n");
     delay(1);
     printf(" \t\t\t\t      *          *              *          *         *       *    *   *     *      *          \n");
     delay(1);
     printf(" \t\t\t\t       *         *              *    *     *         *       *     *  *     *      *         \n");
     delay(1);
     printf(" \t\t\t\t        ******   *              *     *****       *******    *      ***       ****         \n\n\n\n");
     delay(2);
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

void card_games()
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

#endif // DISPLAY_H_INCLUDED
