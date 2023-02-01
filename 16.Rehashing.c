#include <stdio.h>
#include <stdlib.h>
#define n 5

int hash[n] = {};
int rhash[2*n] = {};
int flag=0;

int prime(int num)
{
    int i,j;
    for(i=num+1;;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;
        }
        if(j==i)
        {
            return i;
        }
    }
}

int count(){
    int i, counter=0;
    for(i=0;i<n;i++){
        if (hash[i]!=0 && hash[i]!=-1)
        {
            counter+=1;
        }
    }
    return counter;
}

void insert(){
    int value,hashkey,index,rhashkey;
    int p = prime(2*n);
    printf("\nEnter a value : ");
    scanf("%d",&value);

    if (count()>n-1)
    {
        if (flag==0)
        {
            flag=1;
            printf("\nInner count==n.SO . . .");
            int nvalue,i,k;
            for ( i = 0; i < n; i++)
            {
                nvalue = hash[i];
                for(int j=0;j<2*n;j++){
                    rhashkey = nvalue%p;
                    index = (rhashkey+j)%p;
                    if(rhash[index] == 0 || rhash[index] == -1){
                        rhash[index] = nvalue;
                        break;
                    }
                }
            }
            for ( k = 0; k < 2*n; k++)
            {
                rhashkey = value%p;
                index = (rhashkey+k)%p;
                if(rhash[index] == 0 || rhash[index] == -1){
                    rhash[index] = value;
                    break;
                }
            }
        }
        else
        {
            int i;
            for ( i = 0; i < 2*n; i++)
            {
                rhashkey = value%p;
                index = (rhashkey+i)%p;
                if(rhash[index] == 0 || rhash[index] == -1){
                    rhash[index] = value;
                    break;
                }
            }
            if(i == 2*n){
                printf("\nTable if full\n");
            }
        }
    }
    else if (count()<n)
    {
        int i;
        for(i=0;i<n;i++){
            hashkey = value%n;
            index = (hashkey+i)%n;
            if(hash[index] == 0 || hash[index] == -1){
                hash[index] = value;
                break;
            }
        }
    }
}
void delete(){
    int value,i,hashkey,index,rhashkey;
    printf("\nEnter a value : ");
    scanf("%d",&value);
    if (flag==0)
    {
        hashkey = value%n;
        for(i=0;i<n;i++){
            index = (hashkey+i)%n;
            if(hash[index] == value){
                hash[index] = -1;
                printf("\nElement deleted successfully\n");
                break;
            }
        }
    }
    else
    {
        int i;
        int p = prime(2*n);
        rhashkey = value%p;
        for ( i = 0; i < 2*n; i++)
        {
            index = (rhashkey+i)%p;
            if(rhash[index] == value){
                rhash[index] = -1;
                printf("\nElement deleted successfully\n");
                break;
            }
        }
    }
    
}
void display(){
    int i;
    if (flag==1)
    {
        for(i=0;i<(2*n);i++){
        printf("key = %d and value = %d\n",i,rhash[i]);
        }
    }
    else if (flag==0)
    {
        for(i=0;i<n;i++){
        printf("key = %d and value = %d\n",i,hash[i]);
        }
    }
}

void search(){
    int value,i,hashkey,index,flag = 0;
    printf("\nEnter a value : ");
    scanf("%d",&value);
    hashkey = value%n;
    for(i=0;i<n;i++){
        index = (hashkey+i)%n;
        if(hash[index] == value){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("Element is found at key %d\n",index);
    }else{
        printf("\nElement not found\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("REHASHING\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.DISPLAY\n");
        printf("4.SEARCH\n");
        printf("5.EXIT\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            search();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\nWrong choice. Try again.");
        }
    }
}