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
void push(struct stack *s,char c){
    if(isFull(s->top)==1){
        s->top++;
        s->ele[s->top]=c;
    }
    else
    printf("stack overflow");
}
char pop(struct stack *s){
    if(isEmpty(s->top)==1){
        return s->ele[s->top--];
    }
    else
    printf("stack underflow");
}
int prec(char ch){
    switch (ch )
    {
    case '#':return 0;
        break;
        case '(':
        return 1;
        break;
        case '+':
        case '-':return 2;
        break;
        case '*':
        case '/':return 3;
        break;
        case '$':
        case '^':
        return 4;
        break;

      
    
    default:printf("invalid choice");
        break;
    }
}
void infix_to_postfix(char inf[20],char postfix[20]){
    char symb,s;
    int i=0,j=0;
    struct stack st;
    st.top=-1;
    push(&st,'#');
    symb=inf[i++];
    while (symb!='\0')
    {
        /* code */
        if (symb=='(')
        {
            /* code */
            push(&st,symb);
        }
        else if(isalnum(symb)){
            postfix[j++]=symb;
        }
        else if(symb==')'){
            s=pop(&st);
            while (s!='(')
            {
                /* code */
                postfix[j++]=s;
                s=pop(&st);
            }
            
        }
        else
        {
            while (prec(symb)<=prec(st.ele[st.top]))
            {
                /* code */
                postfix[j++]=pop(&st);
            }
            push(&st,symb);
            
        }
        symb=inf[i++];
    }
    s=pop(&st);
    while (s!='#')
    {
        /* code */
        postfix[j++]=s;
        s=pop(&st);   
    }
    postfix[j]='\0';
    printf("postfix expression is\n");
    for (int k = 0; k < j; k++)
    {
        
        printf("%c",postfix[k]);
    } 
}
void main(){
    char infix[MAX],postfix[MAX];
    printf("enter infix expression\n");
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
}