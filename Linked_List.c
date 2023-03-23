#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    struct node *next;
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
    if(p==NULL){
        return q;
    }
    q->next=p;
    return q;
}

NODE deleteFront(NODE p){
    NODE q=p;
    if (p==NULL)
    {
        printf("empty");
    }else{
    p=p->next;
    freenode(q);
    }
    return p;
}
NODE insertRear(NODE p,int ele){
    NODE q=getnode();
    q->data=ele;
    q->next=NULL;
    if(p==NULL){
        return q;
    }
    NODE s=p;
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=q;
    return p;
}
NODE deleteRear(NODE p){
    NODE s=p;
    NODE prev;
    if(p==NULL){
        printf("emoty list");
        return NULL;
    }
    while(s->next!=NULL){
        prev=s;
        s=s->next;
    }
    prev->next=s->next;
    freenode(s);
    return p;
}
NODE insertPos(NODE p,int ele,int pos){
    NODE q=getnode();
    q->data=ele;
    q->next=NULL;
    if(p==NULL){
        return q;
    }
    if(pos==1){
        q->next=p;
        return q;
    }
    NODE s=p;
    for(int i=1;i<pos-1;i++){
        s=s->next;
        if(s==NULL){
            printf("size is greater ");
            s->next=q;
            return p;
        }
    }
    q->next=s->next;
    s->next=q;
    return p;
}
NODE deletePos(NODE p,int pos){
    NODE s=p;
    NODE prev;
    if(p==NULL){
    printf("deletion not possible");    
    return p;
    }
    if(pos==1){
        p=deleteFront(p);
        return p;
    }
    for(int i=1;i<pos;i++){
        prev=s;
        s=s->next;
        if(s==NULL){
            printf("position greater deletion not possible");
            return p;
        }
    }
    prev->next=s->next;
    freenode(s);
    return p;
}
int search(NODE p,int ele){
    int index=0;
    if(p==NULL){
        printf("empty list");
    }
    NODE s=p;
    while(s!=NULL){
    if(s->data==ele){
        index++;
        return index;
    }    
    s=s->next;
    index++;
    }
    if(s==NULL){
        printf("not found");
        return -1000;
    }
}
void displaystack(NODE p){
    if(p==NULL){
        printf("list is empty")
    }
    NODE q=p;
    while (q!=NULL)
    {
        /* code */
        printf("%d\t",q->data);
        q=q->next;
    }
    printf("\n");
    
}
void main(){
    NODE p=NULL;
    int n,pos,ele;
    while(1){
        printf("\n1.insert front\n2.delete front\n3.insert rear\n4.delete rear\n5.insert pos\n6.delete pos\n7.search\n8.display\n9.exit");
        printf("\nenter your choice\n");
        scanf("%d",&n);
        switch(n){
            case 1:printf("eneter the element to be inserted\n");
            scanf("%d",&ele);
            p=insertFront(p,ele);
            break;
            case 2:p=deleteFront(p);
            break;
            case 3:printf("eneter the element to be inserted\n");
            scanf("%d",&ele);
            p=insertRear(p,ele);
            break;
            case 4:p=deleteRear(p);
            break;
            case 5:printf("eneter the element to be inserted\n");
            scanf("%d",&ele);
            printf("enter the position to be inserted\n");
            scanf("%d",&pos);
            p=insertPos(p,ele,pos);
            break;
            case 6:
            printf("enter the position\n");
            scanf("%d",&pos);
            p=deletePos(p,pos);
            break;
            case 7:
            printf("\nenter the element to be searched\n");
            scanf("%d",&ele);
            int index=search(p,ele);
            printf("\nele found at %d\n",index);
            break;
            case 8:displaystack(p);
            break;
            case 9:exit(0);
            break;
            default:printf("wrong choice");
            break;
        }
    }
}