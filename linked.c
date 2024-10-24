#include <stdio.h>
#include <stdlib.h>
void display(),in_e(),in_bw(),del_b(),del_e(),del_bw(),menu();
int in_b();
int y,n;
char i;
struct node *create();
struct node{
int data;
struct node *link;
};
typedef struct node node1;
node1 *start=NULL;
int main() {
printf("Singly linked list\n");
printf("MENU\n");
menu();
}
void menu()
{
int x;
printf("\n1.Display\n2.Insertion at begnning\n3.Insertion at end\n4.Insertion in between\n5.Deletion at begnning\n6.Deletion at end\n7.Deletion in between\n8.Exit\n");
printf("\nEnter your choice:");
scanf("%d",&x);
switch(x)
{
case 1:display();
break;
case 2:in_b();
break;
case 3:in_e();
break;
case 4:in_bw();
break;
case 5:del_b();
break;
case 6:del_e();
break;
case 7:del_bw();
break;
case 8:exit(0);
}
}
struct node *create()
{
node1 *nptr=((node1*)malloc(sizeof(node1)));
if(nptr==NULL)
{
printf("Memory Overflow");
return 0;
}
else
return nptr;
}
void display()
{
node1 *ptr=start;
if(ptr==NULL){
printf("\nNo elements to display\n");
}
else{
printf("\nElements in the linked list are:\n");
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->link;
}
}
menu();
}
int in_b()
{
int val;
node1 *nptr;
printf("\nEnter the element to be inserted:");
scanf("%d",&val);
nptr=create();
nptr->data=val;
if(start==NULL)
{
start=nptr;
nptr->link=NULL;
}
else{
nptr->link=start;
start=nptr;
}
printf("Element inserted\n");
menu();
}
void in_e()
{
node1 *nptr=create(),*temp;
int val;
printf("\nEnter the element to be inserted:");
scanf("%d",&val);
nptr->data=val;
nptr->link=NULL;
temp=start;
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=nptr;
printf("Element inserted\n");
menu();
}
void in_bw()
{
node1 *temp,*nptr=create();
int val,pos,i;
printf("\nEnter the element:\nEnter the position to be inserted:");
scanf("%d %d",&val,&pos);
nptr->data=val;
nptr->link=NULL;
temp=start;
if(pos==1)
{
nptr->link=start;
start=nptr;
}
else{
for(i=1;i<pos-1;i++)
{
temp=temp->link;
}
}
nptr->link=temp->link;
temp->link=nptr;
printf("Element inserted\n");
menu();
}
void del_b()
{
node1 *temp;
if(start==NULL)
{
printf("\nList is empty!");
}
else{
temp=start;
start=start->link;
free(temp);
printf("\nElement deleted\n");
}
menu();
}
void del_e()
{
node1 *temp,*prev;
temp=start;
if(start==NULL)
{
printf("List is empty!");
}
while(temp->link!=NULL)
{
prev=temp;
temp=temp->link;
}
prev->link=NULL;
free(temp);
printf("\nElement deleted\n");
menu();
}
void del_bw()
{
node1 *temp,*pre;
int pos,i;
printf("Enter the position:");
scanf("%d",&pos);
temp=start;
if(start==NULL)
{
printf("List is empty!");
}
if(pos==1)
{
start=start->link;
}
else{
for (i=1;i<=pos;i++){
pre=temp;
temp=temp->link;
pre->link=temp->link;
}
}
printf("\nElement deleted\n");
menu();
}
