#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack{
    int top;
    int ele[20];
};
int isFull(int top){
    if(top==MAX-1){
        return 0;
    }else{
    return 1;
    }
}
int isEmpty(int top){
    if(top==-1){
        return 0;
    }
    else{
        return 1;
    }
}
void push(struct stack *s,int id){
    if(isFull(s->top)==1){
        s->top++;
        s->ele[s->top]=id;
    }
    else{
        printf("stack overflow");
    }
}
int pop(struct stack *s){
    if(isEmpty(s->top)==1){
        return s->ele[s->top--];
    }
    else{
        printf("stack underflow");
        return -1000;
    }
}
void display(struct stack s){
    if(isEmpty(s.top)==0){
        printf("stack is empty");
    }else{
    printf("the elements of the stack are\n");
    for(int i=0;i<=s.top;i++){
        printf("%d\t",s.ele[i]);
        }
    }
}
void main(){
    struct stack st;
    st.top=-1;
    int id;
    int choice;
    while(1){
        printf("\n1.insert the id\n2.delete the topmost book\n3.display the id's\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nenter the id to be pushed\n");
            scanf("%d",&id);
            push(&st,id);
            break;
            case 2:
            int n=pop(&st);
            printf("\nthe id deleted is %d",n);
            break;
            case 3:
            display(st);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("wrong choice");
            
        }
    }
}