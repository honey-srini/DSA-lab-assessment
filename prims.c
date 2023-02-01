#include<stdio.h>
int v;
void Prims(int adj[][v]){
    int arr[20] = {0},ne = 0,x,y,min,cost=0;
    x = y = 0;
    arr[1] = 1;
    while(ne < v-1){
        x = 0;
        y  = 0;
        min = 999;
        for(int i = 1; i <= v && arr[i] == 1 ; i++){
            for(int j = 1; j <= v; j++){
                if(arr[j] == 0 && adj[i][j]!=0){
                    if(min > adj[i][j]){
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d to %d : %d\n",x,y,adj[x][y]);
        cost=cost+adj[x][y];
        arr[y] = 1;
        ne++;
    } printf("The total cost of the minimum spanning tree is %d",cost) ;
}
void main(){
    int choice;
    v = 5;
    int adj[v][v];
        adj[1][1] = 0 ;
        adj[1][2] = 1 ;
        adj[1][3] = 7 ;
        adj[1][4] = 10 ;
        adj[1][5] = 5 ;

        adj[2][1] = 1 ;
        adj[2][2] = 0 ;
        adj[2][3] = 3 ;
        adj[2][4] = 0 ;
        adj[2][5] = 0 ;

        adj[3][1] = 7 ;
        adj[3][2] = 3 ;
        adj[3][3] = 0 ;
        adj[3][4] = 4 ;
        adj[3][5] = 0 ;

        adj[4][1] = 10 ;
        adj[4][2] = 0 ;
        adj[4][3] = 4 ;
        adj[4][4] = 0 ;
        adj[4][5] = 2 ;

        adj[5][1] = 5 ;
        adj[5][2] = 0 ;
        adj[5][3] = 0 ;
        adj[5][4] = 2 ;
        adj[5][5] = 0 ;
        Prims(adj);
}