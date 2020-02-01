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
 
 
void addEdge(Node** list, int x, int y) {
 
	Node *c = (Node*)malloc(sizeof(Node));
 
	      c->data = y; 
	      c->next = list[x];
	      list[x] = c; 
}
 
void bfs(Node **list, int nodes, int start) {
 
        int queue[ SIZE ],
 
            visited[ SIZE ],
 
            first = 0,
 
            last = 0;

        memset(visited, 0, sizeof(visited));

        visited[ start ] = 1;
 
        queue[ first ] = start;
 
        while( first <= last ) {
 
              int node = queue[ first ];
 
              Node*curr = list[node];
 
              while(curr) {
 
                if(visited[curr->data] == 0) {
 
                   queue[++last] = curr->data;
 
                   visited[curr->data] = 1;
 
                }     
                curr = curr->next;
              }
 
              first++;                     
 
        }
 
        freopen(FOUT, "w", stdout);
 
        for(int i = 0; i < nodes; ++i) printf("%d ", queue[i]);
}
 
int main(int argc, char const *argv[])
{
	Node *list[SIZE];
	
  	int nodes, edges, i, j, s; 
 
    freopen(FIN, "r", stdin);
 
    scanf("%d %d %d" , &nodes, &edges, &s); 
 
    while(edges--) {
 
          scanf("%d %d" , &i, &j);
 
          addEdge(list, i,j);
    }
 
    bfs(list, nodes, 4);

	return 0;
}
