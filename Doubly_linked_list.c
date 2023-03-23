#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node *NODE;
NODE getnode(){
    NODE p=(NODE)malloc(sizeof(struct node));
    return p;
}
void freenode(NODE p){
    free(p);
}
NODE insertFront(NODE p,int ele){
    NODE q=getnode();
    q->data=ele;
    q->left=NULL;
    q->right=NULL;
    if(p==NULL){
        return q;
    }
    q->right=p;
    p->left=q;
    return q;
}
NODE deletePos(NODE p,int pos){
    NODE s=p;
    if(p==NULL){
        printf("deletion not possible");
    }
    if(pos==1){
        p=p->right;
        freenode(s);
        return p;
    }
    for(int i=1;i<pos;i++){
        s=s->right;
        if(s==NULL){
            printf("position greater deletion not possible");
            return p;
        }
    }
    if(s->right==NULL){
        s->left->right=NULL;
        freenode(s);
        return p;
    }
    NODE temp=s->left;
    temp->right=s->right;
    temp->right->left=temp;
    return p;
}
void display(NODE p){
    NODE q=p;
    if(p==NULL){
        printf("empty list");
    }
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->right;
    }
    printf("\n");
}
void reverselist(NODE p){
    NODE q=p;
    while(q->right!=NULL){
        q=q->right;
    }
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->left;
    }
    printf("\n");
}
void main(){
    NODE p=NULL;
    int choice,ele,pos;
    while(1){
        printf("\n1.Insert at front\n2.Delete at pos\n3.display\n4.reverse order\n5.exit\n");
        printf("\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element\n");
            scanf("%d",&ele);
            p=insertFront(p,ele);
            break;
            case 2:
            printf("\nenter the position to be deleted\n");
            scanf("%d",&pos);
            p=deletePos(p,pos);
            break;
            case 3:
            display(p);
            break;
            case 4:
            reverselist(p);
            break;
            default:
            printf("wrong choice\n");
            break;
        }
    }
}