#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define MAX 100100
#define FIN "bfs.in"
#define FOUT "bfs.out"

int nodes, edges;
std::vector<int> graphs[MAX];
std::queue<int> q;
int used[MAX];

void read() {
 
    int x, y;
    std::ifstream fin(FIN);

    fin>>nodes>>edges;
    
    for(unsigned int i = 1; i <= edges; ++i) {

        fin>>x>>y;
        
        graphs[x].push_back(y);
    }
}

void bfs(int node) {

     used[node] = 1;

     q.push(node);

     while(!q.empty()) {

            int curr = q.front();

            std::cout<<curr<<" ";

                q.pop();

                for(auto &i: graphs[curr]) {
  
                      if(!used[i]) {

                         used[i] = 1;

                         q.push(i);
                      }   
                } 
     }
}

int main(int argc, char const *argv[])
{
	read();

	for(int i = 1; i <= nodes; ++i)

		 if(!used[i]) 

	        bfs(i);

	return 0;
}
