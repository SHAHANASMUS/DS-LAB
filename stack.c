#include<stdio.h>
#include<stdlib.h>
void push(),pop(),display(),peek();
int stack[20],i,n,choice,item,top=-1;
int main()
{
printf("Enter the size of the stack");
scanf("%d",&n);
printf("\n1.push\n2.pop\n3.display\n4.peek\n5.exit");
do{
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
  case 1:push();
      break;
  case 2:pop();
      break;
  case 3:display();
      break;
  case 4:peek();
      break;
  case 5:exit(1);
  }
  }while(choice!=5);
  return 0;
 }
 void push()
 {
  if(top!=n-1){
    printf("Enter the element to be pushed:");
    scanf("%d", &item);
    top=top+1;
    stack[top]=item;
    printf("Inserted successfully\n");
 }
 else{
     printf("Can't insert,stack is full!!\n");
     }
 }
 void pop()
 {
 if(top==-1){
   printf("Can't delete data,stack is empty!");
   }
   else{
   item=stack[top];
   printf("\n Deleted element:%d",item);
   top=top-1;
   }
 }
 void peek()
 {
 if(top==-1){
    printf("No element in stack");
    }
    else{
        printf("The topmost element is:\t%d\n",stack[top]);
        }
      }
 void display()
 {
 int i=0;
 if(top==-1){
   printf("Stack is empty\n");}
   
   else{
     printf("Stack elements are:");
     for(i=top;i>=0;i--){
       printf("%d\t", stack[i]);
     }
    }
  }   
    
                    



