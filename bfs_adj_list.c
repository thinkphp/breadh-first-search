#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#define FIN "bfs.in"
#define FOUT "bfs.out"
#define SIZE 100100

struct TNode {
	   int data;
	   struct TNode *next;
};

typedef struct TNode Node;

Node *list[SIZE];


void addEdge(int x, int y) {

	Node *c = (Node*)malloc(sizeof(Node));

	      c->data = y; 
	      c->next = list[x];
	      list[x] = c; 
}

void bfs(Node **list, int nodes, int start) {

        int queue[ SIZE ],

            visited[ SIZE ],

            first = 0,

            last = 0,

            costs[nodes+1];
        
        memset(visited, 0, sizeof(visited));

        memset(costs, -1, sizeof(costs));

        costs[start] = 0;

        visited[ start ] = 1;

        queue[ first ] = start;

        while( first <= last ) {

              int node = queue[ first ];

              Node*curr = list[node];

              while(curr) {

                if(visited[curr->data] == 0) {

                   queue[++last] = curr->data;

                   visited[curr->data] = 1;
        
                   costs[curr->data] = costs[node] + 1;
         
                }     
                curr = curr->next;
              }
            
              first++;                     

        }
        
        freopen(FOUT, "w", stdout);
        
        for(int i = 1; i <= nodes; ++i) printf("%d ", costs[i]);
}

int main(int argc, char const *argv[])
{
  	int nodes, edges, s, i, j; 

    freopen(FIN, "r", stdin);

    scanf("%d %d %d" , &nodes, &edges, &s); 
    
    while(edges--) {

          scanf("%d %d" , &i, &j);
          
          addEdge(i,j);
    }

    bfs(list, nodes, s);
	return 0;
}
