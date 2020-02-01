#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#define FIN "bfs.in"
#define FOUT "bfs.out"

using namespace std;

typedef unsigned long ulong;

#define NDEBUG

class Breadth_First_Search {

      //constructor of the class
	  public:

	  	    Breadth_First_Search(vector<vector<ulong>* >& adjcencyList, ulong nVertices, ulong source) :
	  	                         adjList(adjcencyList), nodes(nVertices), source(source)

	  	         {

                                 costs.resize(nodes + 1, -1);
	  	         }

	  public: 
	       void execute() {

                            costs[ source ] = 0;

	  	   	    bfs(source);  

	       }	

	       void bfs(ulong node) {


                list<ulong> queue;

                queue.push_back(node);

                while( !queue.empty() ) {

                	  ulong curr = queue.front();

                	  queue.pop_front();

                	  vector<ulong> *neighbours = adjList[curr];

                	  if(!neighbours) continue;

                	  for(int i = 0; i < neighbours->size(); ++i) {

                	  	      ulong vertex = (*neighbours)[i];

                	  	      if(costs[vertex] == -1) {

                	  	      	costs[vertex] = costs[curr] + 1;

                	  	      	queue.push_back(vertex);
                	  	      }

                	  }       

                }              
	       }

	       const vector<long>& getCosts() {

                 return costs; 
	       }

      private:
            vector<vector<ulong>* >& adjList;
            ulong nodes;
            ulong source;
            vector<long> costs;

};

int main(int argc, char const *argv[])
{

	const char *inFile = "bfs.in";
	const char *outFile = "bfs.out";

	ulong nodes, edges, source;

	ifstream fin(inFile);
	ofstream fout(outFile);


    #ifndef NDEBUG 

	if(!fin || !fout) {

		cerr<<"Error opening one of \""<<inFile<<"\" or \""<<outFile<<"\""<<endl;;
	}

	#endif

	fin>>nodes>>edges>>source;

	vector<vector<ulong>* > adjList;

	adjList.resize(nodes+1, NULL);

	ulong x, y;

	for(ulong i = 0; i < edges; ++i) {

        fin>>x>>y;

        if(adjList[x] == NULL) {

        	adjList[x] = new vector<ulong>;

        }

        adjList[x]->push_back(y);
	}

 
    Breadth_First_Search bfs(adjList, nodes, source);

                         bfs.execute();  

    const vector<long>& costs = bfs.getCosts();                          

    for(vector<long>::const_iterator it = costs.begin()  + 1; it != costs.end(); ++it) 

    fout<<*it<<" ";      
	
    //clean up
    for(ulong i = 0; i < adjList.size(); ++i) {

    	if(adjList[i] != NULL) delete adjList[i];	
    }      
	
	return 0;
}
