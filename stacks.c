
#include<stdio.h>
#define size[10]
void push(int);
void pop();
void display();


int stack[size],top=-1;
int main(){


  int value,choice;
  while(3){
    printf("enter your choice")
    printf("1.push,2.pop,3.display")
    scanf("%d",&choice)
    switch(choice){
    case1:printf("enter the value");
          scanf("%d",&value);
          push(value)
          break;
    case2:
        pop();
        break;
    case3:
        display();
        break;
    case3:
        printf("exiting....");
        return 0
    default:
        printf("invalid choice...")
    }
        }
  }


   void push(int value){
    if (top==size-1)
        printf("stack overflow")
   }
   else{
    top++;
    stack[top]=value;
    printf("value is pushed to stack\n")
   }

void pop();
{

    if(top==-1){
        printf("stack underflow")

    }
    else{
        printf("poped from stack\n")
        top--;
    }
    }
    void display(){
    if (top==-1)
        printf("stuck is empty")
    }
    else{
        printf("stack  elements are:\n")
        for (i=top,i>=0,i--){
            printf("%d",stack[i])
        }
    }


