#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define SIZE 100100
#define FIN "graph.in"
#define FOUT "graph.out"

typedef unsigned int uint;

using namespace std;
vector<uint> Graph[SIZE];
uint visited[SIZE];
queue<uint> q;
uint nodes, edges;

void addEdge(int x, int y) {

     Graph[x].push_back(y);
}

void read() {

     int x, y;
     ifstream fin(FIN);

     fin>>nodes>>edges;

     while(edges--) {

     	   fin>>x>>y;

     	   addEdge(x,y);
     }
}

void bfs(uint node) {

     cout<<node<<" ";

     for(vector<uint>::iterator it = Graph[node].begin(); it != Graph[node].end(); it++) {

         if(!visited[*it]) {

     	     visited[*it] = 1;     	     

     	     q.push(*it);
     	  }   
     }
      
     q.pop();

     if(!q.empty()) bfs(q.front());     
}

void displayGraph() {

	 for(uint i = 1; i <= nodes; ++i) {

           if(Graph[i].size() > 0)

              for(vector<uint>::iterator it = Graph[i].begin(); it != Graph[i].end(); it++) {

              	  cout<<*it<<" ";    
              }

              cout<<endl;
	 }
}
void displayCosts() {

	 for(int i = 1; i <= nodes; ++i) cout<<costs[i]<<" ";
}	
int main(int argc, char const *argv[])
{

    read();

    //for debug
    //displayGraph();
    cout<<"Breadth First Search Traversal -> ";    
    for(int i = 1; i <= nodes; ++i) {

       if(!visited[i])           

          visited[ i ] = 1,
          q.push( i ),

         bfs(i);
    }   
    
    return 0;
}
