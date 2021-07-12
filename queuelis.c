#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int info;
	struct NODE *next;
}node;
void insert(node** ,node ** ,int);
void del(node **f ,node **r);
void disp(node*);

void main()
{
	node *front=NULL,*rear=NULL;
	int item,n;
	int ch;
	while(1)
	{
		printf("\n1.insert ");
		printf("\n2.display");
	  	printf("\n3.del");
		printf("\n4.Exit");
		printf("\nEnter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter item to insert:");
					 scanf("%d",&item);
					 insert(&front,&rear,item);
					 break;
			case 2:disp(front);break;
		 	case 3:del(&front,&rear);
					 break;  
			case 4:
					printf("program end---THANK U");
					exit(0);
			default:printf("Wrong choice");
		} //end of switch
	} //end of while
} //end of program
void disp(node *front)
{
	node *p;
	if(front==NULL)
		printf("Queue is empty.");
	else
	{
	for( p=front;p!=NULL;p=p->next)
		if(p->next!=NULL)
			printf("%d->",p->info);
		else
			printf("%d",p->info);
	}
}
void del(node **f,node**r)
{
	node *p;
	if(*f==NULL)
		printf("Queue is empty");
	else
	{
		if(*f==*r)//for single item
		{
			free(*f);
			*f=*r=NULL;
		}
		else
		{
			p=*f;
			*f=(*f)->next; //front=front->next
			free(p);
		}
	}
}
void insert(node**f,node**r,int item)
{
	node *curr;
	curr=(node*)malloc(sizeof(node));
	curr->info=item;
	curr->next=NULL;
	if(*f==NULL)
	{
		*f=*r=curr;
	}
	else
	{
		(*r)->next=curr;
		*r=curr;
	}
}
