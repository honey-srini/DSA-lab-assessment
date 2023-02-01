#include<stdio.h>
#include<stdlib.h>
int v,n;

typedef struct edge{
    int u,v,w;
} edge;

void DisplayKruskal(int size);
void Display(int adj[][v]);
edge elist[20], span[20];

void sort(){
    edge temp;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n-i; j++){
            if(elist[j].w > elist[j+1].w){
                temp = elist[j];
                elist[j] = elist[j+1];
                elist[j+1] = temp;
            }
        }
    }
}

// int find(int belongs[], int i){
//     // while(belongs[i]){
//     //     i = belongs[i];
//     //     return i;
//     // }
//     return belongs[i];
//         //    i = belongs[i];
//         //    return i;
// }
void Union(int belongs[], int i, int j){
    for(int k = 0; k <= v; k++){
        if(belongs[k] == j){
            belongs[k] = i;
        }
    }
}

void Kruskal(int adj[][v]){
    int belongs[20],sn = 1,cn1,cn2;
    n = 1;
    for(int i = 1; i <= v; i ++){
        for(int j = 1; j <= v; j++){
            if(adj[i][j] != 0){
                elist[n].u = i;
                elist[n].v = j;
                elist[n].w = adj[i][j];
                n++;
            }
        }
    }
    sort();

    for(int i = 1; i < n; i++){
        // cn1 = find(belongs,elist[i].u);
        // cn2 = find(belongs,elist[i].v);
        cn1 = belongs[elist[i].u];
        cn2 = belongs[elist[i].v];

        if(cn1!= cn2){
            span[sn] = elist[i];
            sn++;
            Union(belongs, cn1, cn2);
        }
    }
    DisplayKruskal(sn);
}

void init(int adj[][v]){
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            adj[i][j] = 0;
        }
    }
}
void DisplayKruskal(int size){
    int i, cost= 0;
    for(i = 1; i < size; i++){
        printf("\nedge(%d,%d) : %d", span[i].u, span[i].v, span[i].w);
        cost = cost + span[i].w;
    }
    printf("\nCost : %d", cost);

}

void Display(int adj[][v]){
     for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }    
}

void main(){
    int choice;
        printf("\nLet's create graph first\n");
        printf("\nNumber of vetices: ");
        scanf("%d",&v);
    int adj[v][v];
    init(adj);
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

    Kruskal(adj);

}