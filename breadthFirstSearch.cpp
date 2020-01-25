#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define MAX 100100
#define FIN "bfs.in"
#define FOUT "bfs.out"

int nodes, edges, s;
std::vector<int> graphs[MAX];
std::queue<int> q;
int used[MAX];
int costs[MAX];

void read() {
 
    int x, y;
    std::ifstream fin(FIN);

    fin>>nodes>>edges>>s;
    
    for(unsigned int i = 1; i <= edges; ++i) {

        fin>>x>>y;
        
        graphs[x].push_back(y);
    }
}

void bfs() {

    for(unsigned int i = 1; i <= nodes; ++i) costs[i] = -1;

     costs[s] = 0;

     used[s] = 1;

     q.push(s);

     while(!q.empty()) {

            int curr = q.front();
        
                q.pop();

                for(auto &i: graphs[curr]) {
  
                      if(!used[i]) {

                         used[i] = 1;

                         costs[i] = costs[curr] + 1;

                         q.push(i);
                      }   
                } 
     }
}

void display() {

     std::ofstream fout(FOUT);

     for(unsigned int i = 1; i <= nodes; ++i) fout<<costs[i]<<" ";
}

int main(int argc, char const *argv[])
{
	read();
	 
    bfs();

    display();

	return 0;
}
