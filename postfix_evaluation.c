#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 20
struct stack{
    char ele[MAX];
    int top;
};
int isFull(int top){
    if(top==MAX-1){
        return 0;
    }
    return 1;
}
int isEmpty(int top){
    if(top==-1)
    return 0;
    return 1;
}
void push(struct stack *s,int c){
    if(isFull(s->top)==1){
        s->top++;
        s->ele[s->top]=c;
    }
    else
    printf("stack overflow");
}
int pop(struct stack *s){
    if(isEmpty(s->top)==1){
        return s->ele[s->top--];
    }
    else
    printf("stack underflow");
    return -1000;
}
int postfix_evaluation(char postfix[20]){
    int i=0,a,b,c;
    char ch;
    struct stack st;
    st.top=-1;
    ch=postfix[i++];
    while (ch!='\0')
    {
        /* code */
        if (isdigit(ch))
        {
            /* code */
            push(&st,ch-'0');
        }
        else{
            a=pop(&st);
            b=pop(&st);
            switch (ch)
            {
            case '+':c=b+a;
                break;
            case '-':c=b-a;
            break;
            case '*':c=b*a;
            break;
            case '/':c=b/a;
            break;
            case '$':c=pow(b,a);
            break;
            default:printf("wrong choice");
                break;
            }
            push(&st,c);
        }
        ch=postfix[i++];
    }
    return pop(&st);
}
void main(){
    int num;
    char postfix[20];
    printf("enter expression\n");
    scanf("%s",postfix);
    num=postfix_evaluation(postfix);
    printf("answer is %d",num);
}