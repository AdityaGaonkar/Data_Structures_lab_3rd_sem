#include<stdio.h>
#include<stdlib.h>
#define max 10

struct c_queue
{
    /* data */
    float ele[max];
    int front,rear,count;
};
int isFull(int count){
    if (count==max)
    {
        /* code */
        return 0;
    }
    return 1;
}
int isEmpty(int count){
    if (count==0)
    {
        /* code */
        return 0;
    }
    return 1;
}
void insertCQ(struct c_queue *cq,float ele){

    if(isFull(cq->count)==1){
        cq->rear++;
        cq->ele[cq->rear%max]=ele;
        cq->count++;
    }
    else{
        printf("Queue overflow");
    }
}
float deleteCQ(struct c_queue *cq){
    float n;
    if (isEmpty(cq->count)==1)
    {
        /* code */
        n=cq->ele[cq->front];
        cq->front=(cq->front+1)%max;
        cq->count--;
        return n;
    }
    return -1000;
}
void display(struct c_queue cq)
{
    int point=cq.front;
    if (cq.count==0)
        {
        /* code */
        printf("no elements");
        }
    
    for (int i = 0; i < cq.count; i++)
    {
        /* code */
        printf("%f\t",cq.ele[point]);
        point=(point+1)%max;
    }
     
    printf("\n");
}
void main(){
    struct c_queue cq;
    cq.front=0;
    cq.rear=-1;
    cq.count=0;
    int ch;
    float n;
    while (1)
    {
        /* code */
        printf("\n1.Insert the element\n2.Delete the element\n3.Display the elements\n4.Exit");
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        printf("enter the ele you want to insert ");
        scanf("%f",&n);
        insertCQ(&cq,n);
        break;
        case 2:
        n=deleteCQ(&cq);
        if (n<0)
        {
                /* code */
                printf("Queue is empty");
                break;
        }
        else{
                printf("deleted element is %f",n);
                break;
        }
        case 3: 
            printf("elements of the queue are\n");
            display(cq);
            break;
            case 4:exit(0);
        default:
        printf("wrong choice");
            break;
        }
    }
    
}



