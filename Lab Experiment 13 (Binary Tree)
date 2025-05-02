#include<stdio.h>
#include<stdlib.h>
#define Max 100
int tree[Max];
void init(){
    for(int i =0;i<Max;i++){
        tree[i]=-1;
    }
}
void insert(int value,int root){
    if(tree[root]==-1)
    tree[root]=value;
    else if(value<tree[root])
    insert(value,2*root+1);
    else if(value>tree[root])
    insert(value,2*root+2);
}
void preorder(int root){
    if(tree[root]!=-1){
        printf("%d ",tree[root]);
        preorder(2*root+1);
        preorder(2*root+2);
}
}
void inorder(int root){
    if(tree[root]==-1)
        return ;
    inorder(2*root+1);
    printf("%d ",tree[root]);
    inorder(2*root+2);
}
void postorder(int root){
    if(tree[root]==-1)
        return ;
    postorder(2*root+1);
    postorder(2*root+2);
    printf("%d ",tree[root]);
}
int search(int i,int target){
    if(i>=Max || tree[i]==-1)
        return -1;
    else if(tree[i]==target)
        return i;
    else if(target<tree[i])
        return search(2*i+1, target);
    else 
        return search(2*i+2,target);
}
int findMin(int i){
    while(i<Max && tree[2*i+1] != -1)
        i= 2*i + 1;
    return i;
}
int findMax(int i){
    while(i<Max && tree[2*i + 2] != -1)
        i= 2*i + 2;
    return i;
}
void delete(int i,int value){
    i = search(i,value);
    if(i==-1)
        printf("Element not found!!!!\n");
    else{
        int left = 2*i+1;
        int right = 2*i+2;
        if((left>=Max||tree[left]==-1)&&(right>=Max || tree[right]==-1))
        tree[i]=-1;
        else if(tree[left] == -1){//having right child only
            int min = findMin(right);
            tree[i]= tree[min];
            delete(min,tree[min]);
        }
        else if(tree[right] == -1){//having left child only 
            int max= findMax(left);
            tree[i]=tree[max];
            delete(max,tree[max]);
        }
        else{
            int min = findMin(right);
            tree[i]= tree[min];
            delete(min,tree[min]);
        }
       
    }
}

int main (){
    init();
    int n,choice,index;
   while(1){
    printf("\n1. Insert\n2. Pre Order\n3. Inorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\n");
    printf("Enter the choice = ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the value = ");
            scanf("%d",&n);
            insert(n,0);
            break;
        case 2:
            printf("\n Pre-Order \n");
            preorder(0);
            break;
        case 3:
            printf("\n In-Order \n");
            inorder(0);
            break;
        case 4:
            printf("\n Post-Order \n");
            postorder(0);
            break;
        case 5:
            printf("Enter the value = ");
            scanf("%d",&n);
            index = search(0,n);
            if(index==-1)
                printf("Not found !!!\n");
            else
                printf("Found!!!\n");
            break;
        case 6:
            printf("Enter the value = ");
            scanf("%d",&n);
            delete(0,n);
            break;
        case 7:
            exit(0);
        break;
        default:
        printf("Invalid choice !!!!!\n");
    }
   }
    return 0;
}
