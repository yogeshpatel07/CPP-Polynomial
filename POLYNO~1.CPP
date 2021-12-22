#include <iostream>

using namespace std;
struct node
{
    float cof;
    int xp;
    int yp;
    struct node *link;
};

class Polynom
{
public:
    struct node *start;
    Polynom()
    {
        start=nullptr;
    }
    void createPoly(struct node*);
    static void showPoly(struct node*);
    void addPoly(Polynom, Polynom);
    void subsPoly(Polynom, Polynom);
    void multiPoly(Polynom, Polynom);
    void dividePoly(Polynom, Polynom);
    static struct node * evaluatePoly(struct node *);
    static struct node * deletePoly(struct node*);
    static struct node * copyPoly(Polynom);


};

int main()
{
    Polynom p1,p2,p3;
    int c;
    char ch='y';
    do
    {
        cout<<"\nEnter 1st Polynomial details\n";
        p1.createPoly(p1.start);
        cout<<"\nEnter 2nd Polynomial details\n";
        p2.createPoly(p2.start);

        cout<<"\nPoly 1st is :";
        Polynom::showPoly(p1.start);
        cout<<"\n\nPoly 2nd is :";
        Polynom::showPoly(p2.start);

        cout<<"\n\nWhat do you want \n1) Add Polynomial\n2) Subtract Polynomial";
        cout<<"\n3) Multiply Polynomial\n4) Divide Polynomial\nEnter your choice : ";
        cin>>c;
        switch(c)
        {
            case 1:
                p3.addPoly(p1,p2);

                cout<<"\nPoly 1st is :";
                Polynom::showPoly(p1.start);
                cout<<"\n\nPoly 2nd is :";
                Polynom::showPoly(p2.start);

                cout<<"\n\nAddition of Polynomials is : \n";
                Polynom::showPoly(p3.start);
                break;
            case 2:
                p3.subsPoly(p1,p2);

                cout<<"\nPoly 1st is :";
                Polynom::showPoly(p1.start);
                cout<<"\n\nPoly 2nd is :";
                Polynom::showPoly(p2.start);

                cout<<"\n\nSubtraction of Polynomials is : \n";
                Polynom::showPoly(p3.start);
                break;
            case 3:
                p3.multiPoly(p1,p2);

                cout<<"\nPoly 1st is :";
                Polynom::showPoly(p1.start);
                cout<<"\n\nPoly 2nd is :";
                Polynom::showPoly(p2.start);

                cout<<"\n\nMultiplication of Polynomials is : \n";
                Polynom::showPoly(p3.start);
                break;
            case 4:
                p3.dividePoly(p1, p2);

                cout<<"\nPoly 1st is :";
                Polynom::showPoly(p1.start);
                cout<<"\n\nPoly 2nd is :";
                Polynom::showPoly(p2.start);

                cout<<"\n\nDivision of Polynomials is : \n";
                Polynom::showPoly(p3.start);
                break;

            default:
                cout<<"\nWrong choice ";
                break;
        }

        cout<<"\n\nDO YOU WANT TO EXIT(Y/N)? : ";
        cin>>ch;

    }while(ch=='N' || ch=='n');

    return 0;

}


void Polynom::multiPoly(Polynom p1, Polynom p2)
{
    struct node *s1,*s2,*s3,*temp=nullptr;
    struct node *pre1,*temp1,*temp2,*temp3;
    s1=p1.start;
    s2=p2.start;
    if(this->start!=nullptr)
    {
        deletePoly(this->start);
    }
    s3=this->start;
    if(s1==nullptr)
    {
        if(s2==nullptr)
        {
            this->start=temp;
        }
        else
        {
            cout<<"\nPolynomial 1 is nullptr \nCan not multiply with nullptr Polynomial ";
            this->start=temp;
        }
    }
    else
    {
        if(s2==nullptr)
        {
            cout<<"\nPolynomial 2 is nullptr \nCan not multiply with nullptr Polynomial ";
            this->start=temp;
        }
        else
        {
            temp1=s1;
            while(temp1!=nullptr)
            {
                temp2=s2;
                while(temp2!=nullptr)
                {
                    temp3=(struct node*)malloc(sizeof(struct node));
                    if(temp3==nullptr)
                    {
                        cout<<"\nNot memory available ";
                        exit(0);
                    }
                    else
                    {
                        if(s3==nullptr)
                        {
                            temp3->cof=(temp1->cof)*(temp2->cof);
                            temp3->xp=(temp1->xp)+(temp2->xp);
                            temp3->yp=(temp1->yp)+(temp2->yp);
                            temp3->link=nullptr;
                            s3=temp3;
                        }
                        else
                        {
                            pre1=s3;
                            while(pre1->link!=nullptr)
                            {
                                pre1=pre1->link;
                            }
                            temp3->cof=(temp1->cof)*(temp2->cof);
                            temp3->xp=(temp1->xp)+(temp2->xp);
                            temp3->yp=(temp1->yp)+(temp2->yp);
                            temp3->link=nullptr;
                            pre1->link=temp3;
                        }
                    }
                    temp2=temp2->link;
                }
                temp1=temp1->link;
            }
            temp= evaluatePoly(s3);
            this->start=temp;
        }
    }
}

void Polynom::subsPoly(Polynom p1, Polynom p2)
{
    struct node *s1,*s2,*s3,*temp=nullptr;
    struct node *pre1,*temp1,*pre;
    s1=p1.start;
    s2=p2.start;
    if(this->start!=nullptr)
    {
        deletePoly(this->start);
    }
    if(s1==nullptr)
    {
        if(s2==nullptr)
        {

            this->start=temp;
        }
        else
        {
            // copy s2 to s3;
            temp=copyPoly(p2);
            pre=temp;
            while(pre!=nullptr)
            {
                pre->cof=pre->cof*(-1);
                pre=pre->link;
            }
            this->start=temp;
        }
    }
    else
    {
        if(s2==nullptr)
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
            while(pre!=nullptr)
            {
                pre->cof=pre->cof*(-1);
                pre=pre->link;
            }
            while(temp->link!=nullptr)
            {
                temp=temp->link;
            }
            temp->link=pre1;
            s3= evaluatePoly(temp1);
            this->start=s3;
        }
    }
}

void Polynom::addPoly(Polynom p1, Polynom p2)
{
    struct node *s1,*s2,*s3,*temp=nullptr;
    struct node *pre1,*temp1;
    s1=p1.start;
    s2=p2.start;
    if(this->start!=nullptr)
    {
        deletePoly(this->start);
    }
    if(s1==nullptr)
    {
        if(s2==nullptr)
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
        if(s2==nullptr)
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
            while(temp->link!=nullptr)
            {
                temp=temp->link;
            }
            temp->link=pre1;
            s3= evaluatePoly(temp1);
            this->start=s3;
        }
    }
}

void Polynom::dividePoly(Polynom p1, Polynom p2)
{
    struct node *s1,*s2,*s3,*temp=nullptr;
    struct node *pre1,*temp1,*temp2,*temp3;
    s1=p1.start;
    s2=p2.start;
    if(this->start!=nullptr)
    {
        deletePoly(this->start);
    }
    s3=this->start;
    if(s1==nullptr)
    {
        if(s2==nullptr)
        {
            this->start=temp;
        }
        else
        {
            cout<<"\nPolynomial 1 is nullptr \nCan not divide with nullptr Polynomial ";
            this->start=temp;
        }
    }
    else
    {
        if(s2==nullptr)
        {
            cout<<"\nPolynomial 2 is nullptr \nCan not divide with nullptr Polynomial ";
            this->start=temp;
        }
        else
        {
            float qp;
            temp1=s1;
            s2=copyPoly(p2);
            temp2=s2;
            while(s2!=nullptr)
            {
                //	s2->cof=1/(s2->cof);
                s2->xp=(-1)*s2->xp;
                s2->yp=(-1)*s2->yp;
                s2=s2->link;
            }
            s2=temp2;
            while(temp1!=nullptr)
            {
                temp2=s2;
                while(temp2!=nullptr)
                {
                    temp3=(struct node*)malloc(sizeof(struct node));
                    if(temp3==nullptr)
                    {
                        cout<<"\nNot memory available ";
                        exit(0);
                    }
                    else
                    {
                        if(s3==nullptr)
                        {
                            qp=(temp1->cof)/(temp2->cof);
                            temp3->cof=qp;
                            temp3->xp=(temp1->xp)+(temp2->xp);
                            temp3->yp=(temp1->yp)+(temp2->yp);
                            temp3->link=nullptr;
                            s3=temp3;
                        }
                        else
                        {
                            pre1=s3;
                            while(pre1->link!=nullptr)
                            {
                                pre1=pre1->link;
                            }
                            qp=(float)(temp1->cof)/(temp2->cof);
                            temp3->cof=qp;
                            temp3->xp=(temp1->xp)+(temp2->xp);
                            temp3->yp=(temp1->yp)+(temp2->yp);
                            temp3->link=nullptr;
                            pre1->link=temp3;
                        }
                    }
                    temp2=temp2->link;
                }
                temp1=temp1->link;
            }
            temp= evaluatePoly(s3);
            this->start=temp;
        }
    }
}

void Polynom::createPoly(struct node *st)
{
    int n,i;
    float tt;
    // to delete all term if object has any term

    if(st != nullptr)
    {
        st=deletePoly(st);
    }
    cout<<"\nEnter how many term are in Polynomial : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==nullptr)
        {
            cout<<"\nOut of memory";
            return;
        }
        cout<<"\nEnter the "<<i+1<<" term details\n";
        if(st == nullptr)
        {
            cout<<"Enter the coefficient of term with sing : ";
            cin>>tt;
            temp->cof=tt;
            cout<<"Enter the power of X in term : ";
            cin>>temp->xp;
            cout<<"Enter the power of Y in term : ";
            cin>>temp->yp;
            temp->link=nullptr;
            st=temp;
            this->start=temp;
        }
        else
        {
            struct node *pre=st;
            while(pre->link!=nullptr)
            {
                pre=pre->link;
            }
            cout<<"Enter the coefficient of term with sing : ";
            cin>>tt;
            temp->cof=tt;
            cout<<"Enter the power of X in term : ";
            cin>>temp->xp;
            cout<<"Enter the power of Y in term : ";
            cin>>temp->yp;
            temp->link=nullptr;
            pre->link=temp;
        }

    }
    // to evaluate new created polynomial

    if(st != nullptr)
    {
        this->start= evaluatePoly(st);
    }
}

void Polynom::showPoly(struct node *start)
{
    node *temp=start;
    if(start==nullptr)
    {
        cout<<"\nNo terms in Polynomial ";
    }
    else
    {
        //printf("\nPolynomial is : ");
        do
        {
            if(temp->cof>0)
            {
                cout<<" +";
            }
            cout<<temp->cof;
            if(temp->xp==1)
            {
                cout<<" x";
            }
            else if(temp->xp==0)
            {

            }
            else
            {
                cout<<" x^"<<temp->xp;
            }
            if(temp->yp==1)
            {
                cout<<" y";
            }
            else if(temp->yp==0)
            {

            }
            else
            {
               cout<<" y^"<<temp->yp;
            }
            temp=temp->link;
        }while(temp!=nullptr);
    }
}

struct node* Polynom::evaluatePoly(struct node * start )
{
    struct node *temp,*cur,*pre;
    temp=start;
    cur=start;
    pre=start;

    //to add and delete same terms
    //ex. 7xy+8xy will become 15xy

    while(temp!=nullptr)
    {
        cur=start;
        while(cur->link!=temp->link)
        {
            pre=cur;
            cur=cur->link;
        }
        while(cur!=nullptr)
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
    while(cur!=nullptr)
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

struct node * Polynom::copyPoly(Polynom pp)
{
    // to create a new copy of given polynomial object

    struct node *temp,*start,*restart,*pre;
    start=pp.start;
    while(start!=nullptr)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==nullptr)
        {
            cout<<"\n\nCan not copy because no memory ";
            exit(0);
        }
        else
        {
            if(start==pp.start)
            {
                temp->cof=start->cof;
                temp->xp=start->xp;
                temp->yp=start->yp;
                temp->link=nullptr;
                restart=temp;
                start=start->link;
            }
            else
            {
                pre=restart;
                while(pre->link!=nullptr)
                {
                    pre=pre->link;
                }
                temp->cof=start->cof;
                temp->xp=start->xp;
                temp->yp=start->yp;
                temp->link=nullptr;
                pre->link=temp;
                start=start->link;
            }
        }
    }
    return restart;
}

struct node * Polynom::deletePoly(struct node *start)
{
    // to delete the given polynomial

    struct node *next,*temp;
    temp=start;
    while(temp!=nullptr)
    {
        next=temp->link;
        free(temp);
        temp=next;
    }
    start=nullptr;
    return start;
}
