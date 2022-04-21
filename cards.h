#ifndef TRIAL_H_INCLUDED
#define TRIAL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

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


void pop(card **head)
{
    card *tmp=*head;
    (*head)=(*head)->next;

    free(tmp);
}

void deleteNode(card **head_ref, int key)
{
    struct card *temp = *head_ref, *prev;

    if (temp != NULL && temp->power == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->power != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;


    prev->next = temp->next;

    free(temp);
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



#endif // TRIAL_H_INCLUDED
