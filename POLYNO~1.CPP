#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct node
{
	float cof;
	int xp;
	int yp;
	struct node *link;
};
class polynom
{
	public:
	struct node *start;
	polynom()
	{
		start=NULL;
	}
	void createPoly(struct node*);
	void showPoly(struct node*);
	void addPoly(polynom,polynom);
	void subsPoly(polynom,polynom);
	void multiPoly(polynom,polynom);
	void devidePoly(polynom,polynom);
	struct node * evalutePoly(struct node *);
	struct node * deletePoly(struct node*);
	struct node * copyPoly(polynom);


};
void main()
{
	polynom p1,p2,p3;
	clrscr();
	int c;
	char ch='y';
	do
	{
		printf("\nEnter 1st Polynomial details\n");
		p1.createPoly(p1.start);
		printf("\nEnter 2nd Polynomial details\n");
		p2.createPoly(p2.start);
		clrscr();
		
		printf("\nPoly 1st is :");
		p1.showPoly(p1.start);		
		printf("\n\nPoly 2nd is :");
		p2.showPoly(p2.start);
		
		printf("\n\nWhat do you want \n1) Add Polynomial\n2) Subtract Polynomial");
		printf("\n3) Multiply Polynomial\n4) Divide Polynomial\nEnter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				p3.addPoly(p1,p2);
				
				printf("\nPoly 1st is :");
				p1.showPoly(p1.start);		
				printf("\n\nPoly 2nd is :");
				p2.showPoly(p2.start);

				printf("\n\nAddition of Polynomials is : \n");
				p3.showPoly(p3.start);
				break;
			case 2:
				p3.subsPoly(p1,p2);

				printf("\nPoly 1st is :");
				p1.showPoly(p1.start);
				printf("\n\nPoly 2nd is :");
				p2.showPoly(p2.start);

				printf("\n\nSubtraction of Polynomials is : \n");
				p3.showPoly(p3.start);
				break;
			case 3:
				p3.multiPoly(p1,p2);

				printf("\nPoly 1st is :");
				p1.showPoly(p1.start);
				printf("\n\nPoly 2nd is :");
				p2.showPoly(p2.start);

				printf("\n\nMultypication of Polynomials is : \n");
				p3.showPoly(p3.start);
				break;
			case 4:
				p3.devidePoly(p1,p2);

				printf("\nPoly 1st is :");
				p1.showPoly(p1.start);
				printf("\n\nPoly 2nd is :");
				p2.showPoly(p2.start);

				printf("\n\nDevision of Polynomials is : \n");
				p3.showPoly(p3.start);
				break;

			default:
				printf("\nWrong choice ");
				getch();
				clrscr();
				break;
		}

		printf("\n\nDO YOU WANT TO EXIT(Y/N)? : ");
		ch=getch();
		clrscr();
	}while(ch=='N' || ch=='n');

}


void polynom::multiPoly(polynom p1,polynom p2)
{
	struct node *s1,*s2,*s3,*temp=NULL;
	struct node *pre1,*temp1,*pre2,*temp2,*pre3,*temp3;
	s1=p1.start;
	s2=p2.start;
	if(this->start!=NULL)
	{
		deletePoly(this->start);
	}
	s3=this->start;
	if(s1==NULL)
	{
		if(s2==NULL)
		{
			this->start=temp;
		}
		else
		{
			printf("\nPolynomial 1 is NULL \nCan not multiply with NULL Polynomial ");
			this->start=temp;
		}
	}
	else
	{
		if(s2==NULL)
		{
			printf("\nPolynomial 2 is NULL \nCan not multiply with NULL Polynomial ");
			this->start=temp;
		}
		else
		{
			temp1=s1;
			while(temp1!=NULL)
			{
				temp2=s2;
				while(temp2!=NULL)
				{
					temp3=(struct node*)malloc(sizeof(struct node));
					if(temp3==NULL)
					{
						printf("\nNot memory available ");
						getch();
						exit(0);
					}
					else
					{
						if(s3==NULL)
						{
							temp3->cof=(temp1->cof)*(temp2->cof);
							temp3->xp=(temp1->xp)+(temp2->xp);
							temp3->yp=(temp1->yp)+(temp2->yp);
							temp3->link=NULL;
							s3=temp3;
						}
						else
						{
							pre1=s3;
							while(pre1->link!=NULL)
							{
								pre1=pre1->link;
							}
							temp3->cof=(temp1->cof)*(temp2->cof);
							temp3->xp=(temp1->xp)+(temp2->xp);
							temp3->yp=(temp1->yp)+(temp2->yp);
							temp3->link=NULL;
							pre1->link=temp3;
						}
					}
					temp2=temp2->link;
				}
				temp1=temp1->link;
			}
			temp=evalutePoly(s3);
			this->start=temp;
		}
	}
}

void polynom::subsPoly(polynom p1,polynom p2)
{
	struct node *s1,*s2,*s3,*temp=NULL;
	struct node *pre1,*temp1,*pre;
	s1=p1.start;
	s2=p2.start;
	if(this->start!=NULL)
	{
		deletePoly(this->start);
	}
	if(s1==NULL)
	{
		if(s2==NULL)
		{

			this->start=temp;
		}
		else
		{
			// copy s2 to s3;
			temp=copyPoly(p2);
			pre=temp;
			while(pre!=NULL)
			{
				pre->cof=pre->cof*(-1);
				pre=pre->link;
			}
			this->start=temp;
		}
	}
	else
	{
		if(s2==NULL)
		{
			//copy s1 to s3;
			temp=copyPoly(p1);
			this->start=temp;
		}
		else
		{
			temp=copyPoly(p1);
			pre1=copyPoly(p2);
			temp1=temp;
			pre=pre1;
			while(pre!=NULL)
			{
				pre->cof=pre->cof*(-1);
				pre=pre->link;
			}
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=pre1;
			s3=evalutePoly(temp1);
			this->start=s3;
		}
	}
}

void polynom::addPoly(polynom p1,polynom p2)
{
	struct node *s1,*s2,*s3,*temp=NULL;
	struct node *pre1,*temp1;
	s1=p1.start;
	s2=p2.start;
	if(this->start!=NULL)
	{
		deletePoly(this->start);
	}
	if(s1==NULL)
	{
		if(s2==NULL)
		{

			this->start=temp;
		}
		else
		{
			// copy s2 to s3;
			temp=copyPoly(p2);
			this->start=temp;
		}
	}
	else
	{
		if(s2==NULL)
		{
			//copy s1 to s3;
			temp=copyPoly(p1);
			this->start=temp;
		}
		else
		{
			temp=copyPoly(p1);
			pre1=copyPoly(p2);
			temp1=temp;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=pre1;
			s3=evalutePoly(temp1);
			this->start=s3;
		}
	}
}

void polynom::devidePoly(polynom p1,polynom p2)
{
	struct node *s1,*s2,*s3,*temp=NULL;
	struct node *pre1,*temp1,*pre2,*temp2,*pre3,*temp3;
	s1=p1.start;
	s2=p2.start;
	if(this->start!=NULL)
	{
		deletePoly(this->start);
	}
	s3=this->start;
	if(s1==NULL)
	{
		if(s2==NULL)
		{
			this->start=temp;
		}
		else
		{
			printf("\nPolynomial 1 is NULL \nCan not divide with NULL Polynomial ");
			this->start=temp;
		}
	}
	else
	{
		if(s2==NULL)
		{
			printf("\nPolynomial 2 is NULL \nCan not divide with NULL Polynomial ");
			this->start=temp;
		}
		else
		{
			float qp;
			temp1=s1;
			s2=copyPoly(p2);
			temp2=s2;
			while(s2!=NULL)
			{
			       //	s2->cof=1/(s2->cof);
				s2->xp=(-1)*s2->xp;
				s2->yp=(-1)*s2->yp;
				s2=s2->link;
			}
			s2=temp2;
			while(temp1!=NULL)
			{
				temp2=s2;
				while(temp2!=NULL)
				{
					temp3=(struct node*)malloc(sizeof(struct node));
					if(temp3==NULL)
					{
						printf("\nNot memory available ");
						getch();
						exit(0);
					}
					else
					{
						if(s3==NULL)
						{
							qp=(temp1->cof)/(temp2->cof);
							temp3->cof=qp;
							temp3->xp=(temp1->xp)+(temp2->xp);
							temp3->yp=(temp1->yp)+(temp2->yp);
							temp3->link=NULL;
							s3=temp3;
						}
						else
						{
							pre1=s3;
							while(pre1->link!=NULL)
							{
								pre1=pre1->link;
							}
							qp=(float)(temp1->cof)/(temp2->cof);
							temp3->cof=qp;
							temp3->xp=(temp1->xp)+(temp2->xp);
							temp3->yp=(temp1->yp)+(temp2->yp);
							temp3->link=NULL;
							pre1->link=temp3;
						}
					}
					temp2=temp2->link;
				}
				temp1=temp1->link;
			}
			temp=evalutePoly(s3);
			this->start=temp;
		}
	}
}

void polynom::createPoly(struct node *start)
{
	int n,i;
	float tt;
	// to delete all term if object has any term

	if(start!=NULL)
	{
		start=deletePoly(start);
	}

	//to create new term

	printf("\nEnter how many term are in Polynomial : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\nOut of memory");
			getch();
			return;
		}
		printf("\nEnter the %d term details\n",i+1);
		if(start==NULL)
		{
			printf("Enter the coefficient of term with sing : ");
			scanf("%f",&tt);
			temp->cof=tt;
			printf("Enter the power of X in term : ");
			scanf("%d",&temp->xp);
			printf("Enter the power of Y in term : ");
			scanf("%d",&temp->yp);
			temp->link=NULL;
			start=temp;
			this->start=temp;
		}
		else
		{
			struct node *pre=start;
			while(pre->link!=NULL)
			{
				pre=pre->link;
			}
			printf("Enter the coefficient of term with sing : ");
			scanf("%f",&tt);
			temp->cof=tt;
			printf("Enter the power of X in term : ");
			scanf("%d",&temp->xp);
			printf("Enter the power of Y in term : ");
			scanf("%d",&temp->yp);
			temp->link=NULL;
			pre->link=temp;
		}

	}
	// to evaluate new created polynomial

	if(start!=NULL)
	{
		this->start=evalutePoly(start);
	}
}

void polynom::showPoly(struct node *start)
{
	node *temp=start;
	if(start==NULL)
	{
		printf("\nNo terms in Polynomial ");
	}
	else
	{
		//printf("\nPolynomial is : ");
		do
		{
			if(temp->cof>0)
			{
				printf(" +");
			}
			printf(" %.2f",temp->cof);
			if(temp->xp==1)
			{
				printf(" x");
			}
			else if(temp->xp==0)
			{

			}
			else
			{
				printf(" x^%d",temp->xp);
			}
			if(temp->yp==1)
			{
				printf(" y");
			}
			else if(temp->yp==0)
			{

			}
			else
			{
				printf(" y^%d",temp->yp);
			}
			temp=temp->link;
		}while(temp!=NULL);
	}
}

struct node* polynom::evalutePoly(struct node *start)
{
	struct node *temp,*cur,*pre;
	temp=start;
	cur=start;
	pre=start;

	//to add and delete same terms
	//ex. 7xy+8xy will become 15xy

	while(temp!=NULL)
	{
		cur=start;
		while(cur->link!=temp->link)
		{
			pre=cur;
			cur=cur->link;
		}
		while(cur!=NULL)
		{
			if(cur->xp==temp->xp && cur->yp==temp->yp && temp->link!=cur->link)
			{
				pre->link=cur->link;
				temp->cof=temp->cof+cur->cof;
				free(cur);
				cur=pre;
			}
			pre=cur;
			cur=cur->link;
		}
		temp=temp->link;
	}
	// to remove 0 elements
	//ex. 0 x^2 y^3 term will deleted
	cur=start;
	pre=start;
	while(cur!=NULL)
	{
		if(cur->cof==0)
		{
			if(cur==start)
			{
				pre=cur;
				start=cur->link;
				free(pre);
				pre=cur;
			}
			else
			{
				pre->link=cur->link;
				free(cur);
				cur=pre;
			}
		}
		pre=cur;
		cur=cur->link;
	}
	return start;
}

struct node * polynom::copyPoly(polynom pp)
{
	// to create a new copy of given polynomial object

	struct node *temp,*start,*rstart,*pre;
	start=pp.start;
	while(start!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\n\nCan not copy because no memory ");
			getch();
			exit(0);
		}
		else
		{
			if(start==pp.start)
			{
				temp->cof=start->cof;
				temp->xp=start->xp;
				temp->yp=start->yp;
				temp->link=NULL;
				rstart=temp;
				start=start->link;
			}
			else
			{
				pre=rstart;
				while(pre->link!=NULL)
				{
					pre=pre->link;
				}
				temp->cof=start->cof;
				temp->xp=start->xp;
				temp->yp=start->yp;
				temp->link=NULL;
				pre->link=temp;
				start=start->link;
			}
		}
	}
	return rstart;
}

struct node * polynom::deletePoly(struct node *start)
{
	// to delete the given polynomial

	struct node *next,*temp;
	temp=start;
	while(temp!=NULL)
	{
		next=temp->link;
		free(temp);
		temp=next;
	}
	start=NULL;
	return start;
}

