#include <iostream>
#include <fstream>
#define SIZE 100100
#define FIN "graph.in"
#define FOUT "graph.out"

struct TNode {
	   int info;
	   struct TNode* next;
};

typedef struct TNode Node;

Node *arr[SIZE];

int queue[SIZE];
char visited[SIZE];

int nodes, 
    edges;  

void add(int x, int y) {

     Node *c = new Node;

           c->info = x;

           c->next = arr[y];

           arr[y] = c; 
}

void read() {

   int  x, y;

	 std::ifstream fin(FIN);

	 fin>>nodes>>edges;
	 
	 for(int i = 0; i < edges; ++i) {

	 	fin>>x>>y;

	 	add(y,x);
	 }
}

void bfs(int node) {
      
     int k = 0;

     visited[node] = 1;

	   queue[k++] = node;

     std::cout<<node<<" "; 
        
         for(int i = 0; i < nodes; ++i)

         for(Node *it = arr[queue[i]]; it; it = it->next) {                   
                   
                   if(visited[it->info] != 1) {      

                          std::cout<<it->info<<" "; 
                         
                          visited[it->info] = 1;                           

                          queue[k++] = it->info;                         
                   } 
         }       
}

int main(int argc, char const *argv[])
{

	read(); 

  for(int i = 1; i <= nodes; ++i) 

    if(!visited[i])
    bfs(i);

	return 0;
}
