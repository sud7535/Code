#include<stdio.h>
#include<stdlib.h>

struct term
{
	int e,c;
	struct term *next;
};

struct term *a=NULL,*b=NULL,*s=NULL;

struct term *createterm()
{
	struct term *add,object;
	add=(struct term *)malloc(sizeof(object));
	int v;
	printf("Enter exponent value :: ");
	scanf("%d",&v);
	add->e=v;
	printf("Enter coefficient value :: ");
	scanf("%d",&v);
	add->c=v;
	add->next=NULL;
	return add;
}

/*void addthem(struct term *at, struct term *bt)
{
	struct term *sumterm;
	sumterm=(struct term *)malloc(sizeof(struct term));
	if(at->e > bt->e)
	{
		sumterm->e = at->e ;
		sumterm->c = at->c ;
		at=at->next;
	}
	else if(at->e == bt->e)
	{
		sumterm->e = at->e ;
		sumterm->c = at->c + bt->c ;
		bt=bt->next;
		at=at->next;
	}
	else
	{
		sumterm->e = bt->e ;
		sumterm->c = bt->c ;
		bt=bt->next;
	}
	if(s==NULL)
		s=sumterm;
	else
	{
		struct term *st=s;
		while(st->next!=s)
			st=st->next;
		st->next=sumterm;
	}
	sumterm->next=s;
}*/

void sum(struct term *a, struct term *b)
{
	struct term *at=a, *bt=b;
	while(at==a || bt==b)
	{
		struct term *sumterm;
		sumterm=(struct term *)malloc(sizeof(struct term));
		if(at->e > bt->e)
		{
			sumterm->e = at->e ;
			sumterm->c = at->c ;
			at=at->next;
		}
		else if(at->e == bt->e)
		{
			sumterm->e = at->e ;
			sumterm->c = at->c + bt->c ;
			bt=bt->next;
			at=at->next;
		}
		else
		{
			sumterm->e = bt->e ;
			sumterm->c = bt->c ;
			bt=bt->next;
		}
		if(s==NULL)
			s=sumterm;
		else
		{
			struct term *st=s;
			while(st->next!=s)
				st=st->next;
			st->next=sumterm;
		}
		sumterm->next=s;
	}
	
	while(at!=a && bt!=b)
	{
		struct term *sumterm;
		sumterm=(struct term *)malloc(sizeof(struct term));
		if(at->e > bt->e)
		{
			sumterm->e = at->e ;
			sumterm->c = at->c ;
			at=at->next;
		}
		else if(at->e == bt->e)
		{
			sumterm->e = at->e ;
			sumterm->c = at->c + bt->c ;
			bt=bt->next;
			at=at->next;
		}
		else
		{
			sumterm->e = bt->e ;
			sumterm->c = bt->c ;
			bt=bt->next;
		}
		if(s==NULL)
			s=sumterm;
		else
		{
			struct term *st=s;
			while(st->next!=s)
				st=st->next;
			st->next=sumterm;
		}
		sumterm->next=s;
	}	
}

/*void attach(struct term *add, struct term *head)
{
	if(head==NULL)
		head=add;
	else
	{
		struct term *h=head;
		while(h->next!=head)
			h=h->next;
		h->next=add;
	}
	add->next=head;
}*/

void display(struct term *head)
{
	struct term *h=head;	
	printf("| %d * x ^ %d |",h->c,h->e);
	h=h->next;
	while(h!=head)
	{
		printf(" + | %d * x ^ %d |",h->c,h->e);
		h=h->next;
	}
	printf("\n");
	
}

int main()
{
	printf("We add 2 Polynomials. ");
	for(int i=1;i<=2;i++)
	{
		printf("For polynomial %d :: \n",i);
		printf("How many terms do oyu have ? ");
		int t;
		scanf("%d",&t);
		for(int j=1;j<=t;j++)
		{
			struct term *add=createterm();
			if(i==1)
			{
				if(a==NULL)
					a=add;
				else
				{
					struct term *at=a;
					while(at->next!=a)
						at=at->next;
					at->next=add;
				}
				add->next=a;
			}
			else 
			{
				if(b==NULL)
					b=add;
				else
				{
					struct term *bt=b;
					while(bt->next!=b)
						bt=bt->next;
					bt->next=add;
				}
				add->next=b;
			}
		
		}
	}
	printf("Polynomial 1 is :: \n");
	display(a);
	printf("Polynomial 2 is :: \n");
	display(b);
	sum(a,b);
	printf("Polynomial SUM is :: \n");
	display(s);
	return 0;

}
