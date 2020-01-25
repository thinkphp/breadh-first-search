#include <iostream>
#include <fstream>
#define SIZE 100100
#define FIN "bfs.in"
#define FOUT "bfs.out"

struct TNode {
	   int info;
	   struct TNode* next;
};

typedef struct TNode Node;

Node *arr[SIZE];

int costs[SIZE], 
    queue[SIZE];
char visited[SIZE];

int nodes, 
    edges, 
    s, 
    k = 0;

void add(int x, int y) {

     Node *c = new Node;

           c->info = x;

           c->next = arr[y];

           arr[y] = c; 
}

void read() {

     int  x, y;
	 std::ifstream fin(FIN);

	 fin>>nodes>>edges>>s;
	 
	 for(int i = 0; i < edges; ++i) {

	 	fin>>x>>y;

	 	add(y,x);
	 }
}

void bfs() {

	 for(int i = 0; i <= nodes; ++i) costs[i] = -1;

	 queue[k++] = s;

     visited[ s ] = 1;

     costs[s] = 0;

     for(int i = 0; i < nodes; ++i) {

         for(Node *it = arr[queue[i]]; it; it = it->next) {                   
                   
                   if(visited[it->info] != 1) {                          
                         
                          visited[it->info] = 1; 

                          costs[it->info] = costs[queue[i]] + 1;

                          queue[k++] = it->info;                         
                   } 
         }  

     }
}

void displayCosts() {

	 std::ofstream fout(FOUT);

	 for(int i = 1; i <= nodes; ++i) std::cout<<costs[i]<<" ";
}

int main(int argc, char const *argv[])
{
	read(); 
	bfs();
	displayCosts();
	return 0;
}
