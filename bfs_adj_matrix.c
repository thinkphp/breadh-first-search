#include <stdio.h>
#include <string.h>
#define FIN "bfs.in"
#define SIZE 50


void bfs(int matrix[][SIZE], int nodes, int start) {

     int queue[nodes], 
         i, j,
         visited[nodes], 
         first = 0, 
         last = 0, 
         curr;
     
     queue[ first ] = start;

     memset(visited, 0, sizeof(visited));

     visited[ start ] = 1;     

     while(first <= last) {

           curr = queue[first];

           for(j = 1; j <= nodes; ++j) 

                   if(0 == visited[j] && 1 == matrix[curr][ j ]) {
     
                   	  last = last + 1;

                   	  queue[ last ] = j;

                   	  visited[ j ] = 1;    
                   }           

           first++;
     }      

     for(i = 0 ; i < nodes; ++i) printf("%d ", queue[i]);
}

void display(int mat[][SIZE], int nodes) {

     for(int i = 1; i <= nodes; ++i) {

     	for(int j = 1; j <= nodes; ++j) {

     		printf("%d ", mat[i][j]);
     	
        }		
            printf("\n");
     } 	
}


int main(int argc, char const *argv[])
{

	int matrix[SIZE][SIZE],

	   nodes, edges, s, i, j;

    freopen(FIN, "r", stdin);

    scanf("%d %d %d", &nodes, &edges, &s);

    while(edges--) {

         scanf("%d %d", &i, &j);

         matrix[i][j] = 1;                  
    }

    display(matrix, nodes);

    bfs(matrix, nodes, 4);    
	
	return 0;
}
