#include<stdio.h>
#include<stdlib.h>
#define n 10
int hash[n]={NULL};
void insert(){
    int value,i,index,hash_value;
    printf("Enter the value:");
    scanf("%d",&value);
    hash_value=value%n;
    for(i=0;i<n;i++){
        index=(hash_value+i)%n;
        if(hash[index]==NULL){
            hash[index]=value;
            break;
        }
    }
}

void display(){
    int i ;
    for(i=0;i<n;i++){
        printf("\nindex : %d and value : %d",i,hash[i]);
    }
}

int main()
{
int choice;
while(1)
{
    printf("Enter choice:\n");
    printf("1.insert\n");
    printf("2.view\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        insert();
        break;

        case 2:
        display();
        break;

        default:
        printf("wrong choice");

        
    }
}

}
