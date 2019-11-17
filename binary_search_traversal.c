#include<stdio.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
};
struct node *start=NULL;
struct node *temp=NULL;
struct node *t1,*t2;
void delete1(struct node *q);
void search1(struct node *q, int data);
void insert();
void delete();
int smallest(struct node *q);
int largest(struct node *q);
struct node *read();
void search(struct node *q);
void inorder(struct node *start);
void preorder(struct node *start);
void postorder(struct node *start);
int flag=1;
struct node *read()
{
	int item;
	printf("Enter the data\n");
	scanf("%d", &item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->rlink=temp->llink=NULL;
	struct node *details=temp;
	return details;
}
void insert()
{
	read();
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		search(start);
	}
}
void search(struct node *q)
{

	if((temp->data > q->data)&&(q->rlink!=NULL))
	{
		search(q->rlink);
	}
	else if((temp->data < q->data)&&(temp->llink!=NULL))
	{
		search(q->llink);
	}
	else if((temp->data>q->data)&&(q->rlink==NULL))
	{
		q->rlink=temp;
	}
	else if((temp->data<q->data)&&(q->llink==NULL))
	{
		q->llink=temp;
	}
}
void inorder(struct node *start)
{
	if(start==NULL)
		return;
	inorder(start->llink);
	printf("%d\t", start->data);
	inorder(start->rlink);
}
void preorder(struct node *start)
{
	if(start==NULL)
		return;
	printf("%d\t", start->data);
	preorder(start->llink);
	preorder(start->rlink);
}
void postorder(struct node *start)
{
	if(start==NULL)
		return;
	postorder(start->llink);
	postorder(start->rlink);
	printf("%d\t", start->data);
}
void delete()
{
	int item;
	if (start == NULL)
 	{
		printf("No elements in a tree to delete");
		return;
	}
	printf("Enter the data to be deleted : ");
	scanf("%d", &item);
	t1 = start;
	t2 = start;
	search1(start, item);
}
void search1(struct node *q, int item)
{
	if ((item>q->data))
	{
		t1 = q;
        	search1(q->rlink, item);
	}
	else if ((item < q->data))
	{
		t1 = q;
		search1(q->llink, item);
	}
	else if ((item==q->data))
	{
	delete1(q);
	}

}
/* To delete a node */

void delete1(struct node *q)
{
	int k;
/* To delete leaf node */
	if ((q->llink == NULL) && (q->rlink == NULL))
	{
	 	if (t1->llink == q)
		{
			t1->llink = NULL;
		}
		else
		{
			t1->rlink = NULL;
		}
	q = NULL;
	free(q);
	return;
	}
/*  one left hand child */
	 else if ((q->rlink == NULL))
	{
		if (t1 == q)
		{
			start = q->llink;
			t1 = start;
		}
		else if (t1->llink == q)
		{
			t1->llink = q->llink;
		}
		else
		{
			t1->rlink = q->llink;
		}
	q= NULL;
	free(q);
	return;
	}
/*  right hand child */

    	else if (q->llink == NULL)
	{
		if (t1 == q)
		{
			 start= q->rlink;
			 t1 = start;
		}
		 else if (t1->rlink == q)
		{
			t1->rlink = q->rlink;
		}
        	else
		{
            		t1->llink= q->rlink;
		}
        q== NULL;
	free(q);
	return;
}
/*  two child */

    	else if ((q->llink != NULL) && (q->rlink != NULL))
	{
		t2 = start;
		if (q->rlink != NULL)
		{
			k = smallest(q->rlink);
			flag = 1;
		}
		 else
		{
			 k =largest(q->llink);
			 flag = 2;
		}
	search1(start, k);
	q->data = k;
	}
}
/*  smallest element in the right sub tree */

int smallest(struct node *q)
{
	t2 = q;
	if (q->llink != NULL)
	{
		t2 = q;
		return(smallest(q->llink));
	}
	else
	{
		return (q->data);
	}
}
/* largest element in the left sub tree */

int largest(struct node *q)
{
	if (q->rlink != NULL)
	{
		 t2 = q;
		return(largest(q->rlink));
	}
	else
	{
        	return(q->data);
	}
}
void main()
{
	int ch,ch1;
	do
	{
		printf("\n1.INSERTION\n2.TRAVERSAL\n3.DELETION\n4.EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:insert();
				break;
			case 2:  printf("\n1.PREORDER\t2.INORDER\t3.POSTORDER\n");
			scanf("%d", &ch1);
			switch(ch1)
			{
				case 1: preorder(start);
					break;
				case 2: inorder(start);
					break;
				case 3: postorder(start);
					break;
			}
			break;
			case 3:delete();
			break;
			case 4:exit(0);
		}
	}while(ch!=4);
}

