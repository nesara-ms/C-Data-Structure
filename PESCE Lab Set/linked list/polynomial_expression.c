#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int cf;
    int px;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    return x;
}
NODE insert_rear(int px,int cf,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    cur = head->link;
    while(cur->link!=NULL) 
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("List is empty\n");
        exit(0);
    }
    temp=head->link;
    while(temp!=head)
    {
        printf("+%d",temp->cf);
        if(temp->px!=0)
            printf("x^%d",temp->px);
            temp=temp->link;
    }
}
NODE read_poly(NODE head)
{
    int n,i,px,cf;
    printf("Enter the number of terms in the polynomial\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the coefficient of x\n");
        scanf("%d",&cf);
        printf("Enter the power of x\n");
        scanf("%d",&px);
        head=insert_rear(px,cf,head);
    }
    return head;
}
float evaluate(NODE head)
{
    int x;
    float sum=0;
    NODE P;
    printf("Enter the value of x\n");
    scanf("%d",&x);
    P=head->link;
    while(P!=NULL)
    {
        sum+=P->cf*pow(x,P->px);
        P=P->link;
    }
    return sum;
}
void main()
{
    NODE head;
    float res;
    head=getnode();
    head->link=head;
    printf("Enter the polynomial\n");
    head=read_poly(head);
    res=evaluate(head);
    printf("The given polynomial is\n");
    display(head);
    printf("The result of the polynomial is %f\n",res);
}
  