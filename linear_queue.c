#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 4
struct l_queue
{
    /* data */
    long ele[MAX];
    int rear;
    int front;
};
int isFull(int rear){
    if(rear==MAX-1){
        return 0;
    }
    return 1;
}
int isEmpty(int front,int rear){
    if (front>rear)
    {
        /* code */
        return 0;
    }
    return 1;    
}
void insert_lqueue(struct l_queue *lq,long n){
    if (isFull(lq->rear)==1)
    {
        /* code */
        lq->rear++;
        lq->ele[lq->rear]=n;
        return;
    }
    printf("queue is full");
}
long delete_lqueue(struct l_queue *lq){
    if (isEmpty(lq->front,lq->rear)==1)
    {
        /* code */
        long n=lq->ele[lq->front];
        lq->front++;
        return n;
    }
    printf("queue is empty");
    return -100000;
}
void displayq(struct l_queue lq){
    if(isEmpty(lq.front,lq.rear)==0){
        printf("no elements\n");
        exit(0);
    }
    printf("\nelements of the queue are\n");
    for (int i =lq.front; i <=lq.rear; i++)
    {
        /* code */
        printf("%ld\n",lq.ele[i]);
    }
    printf("\n");
    
}
void main(){
    struct l_queue lq;
    lq.rear=-1;
    lq.front=0;
    int ch;
    long ph;
    while (1)
    {
        /* code */
        printf("\n1.To insert a new phone number\n2.To delete a phone number\n3.Display\n4.Exit");
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the phone number\n");
            scanf("%ld",&ph);
            insert_lqueue(&lq,ph);
            break;
        case 2:
        long num=delete_lqueue(&lq);
        printf("deleted number is %ld",num);
        break;
        case 3:displayq(lq);
        break;
        case 4:exit(0);
        default:printf("wrong choice");
            break;
        }
    }
    
}
