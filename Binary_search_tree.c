#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE insertBST(NODE root,int ele){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=ele;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL){
    return temp;
    }
    NODE cur=root;
    NODE prev=NULL;
    while(cur!=NULL){
        prev=cur;
        if(ele<cur->data){
        cur=cur->llink;
        }else{
        cur=cur->rlink;
        }
    }
    if(ele<prev->data){
        prev->llink=temp;
    }else{
    prev->rlink=temp;}
    return root;
}
void postorder(NODE root){
    if(root==NULL)
    return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->data);
}
void inorder(NODE root){
    if(root==NULL)
    return;
    inorder(root->llink);
    printf("%d\t",root->data);
    inorder(root->rlink);
}
void preorder(NODE root){
    if(root==NULL)
    return;
    printf("%d\t",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
NODE searchBST(NODE root,int ele){
    if(root==NULL||root->data==ele){
        return root;
    }
    if(ele<root->data){
    return searchBST(root->llink,ele);
    }else{
    return searchBST(root->rlink,ele);
    }
}
void main(){
    int a,ele;
    NODE root=NULL;
    while(1){
        printf("\n1.Insert an element in a tree\n2.Perform postorder\n3.Perform inorder\n4.Perform preorder\n5.Search the given element\n6.exit\n");
        printf("enter the choice\n");
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("\nenter the element\n");
            scanf("%d",&ele);
            root=insertBST(root,ele);
            break;
            case 2:
            postorder(root);
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            preorder(root);
            break;
            case 5:
            printf("\nenter the ele to be searched\n");
            scanf("%d",&ele);
            NODE root1=root;
            root1=searchBST(root1,ele);
            if(root1!=NULL){
            printf("\nelement  found\n");}
            else{
            printf("\nelement not found\n");}
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("wrong choice");
        }
    }
}