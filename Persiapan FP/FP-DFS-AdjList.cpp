#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <chrono>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int source, int des){
            cout << endl;
            cout << "\n>> Shortest Path using DFS:" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(source, des, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "- Weight = " << dfsWeight << endl;
        }

        void solveDFS(int source, int des, vector<int> path, vector<bool> visited, int currWeight){
            if(source == des) {
                path.push_back(des);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[source] = true;
            path.push_back(source);
            list<int>::iterator it;
            for ( it = adj[source].begin(); it != adj[source].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(source, *it)];
                    solveDFS(*it, des, path, visited, wtemp);
                }
            }
        }
};

int main(){
    Graph graph(20);
	graph.addVertex("Fr House", 1, 1, 1);
	graph.addVertex("INDORASA", 1, 13, 13);
	graph.addVertex("Sanglah Market", 1, 3, 3);
	graph.addVertex("RS Ngoerah", 1, 2, 2);

	graph.addVertex("RS Ngoerah", 2, 2, 2);
	graph.addVertex("Ayam Gepuk", 2, 19, 19);

	graph.addVertex("Sanglah Market", 3, 3, 3);
	graph.addVertex("RS Prima Medika", 3, 4, 4);
	graph.addVertex("Eka Print", 3, 15, 15);

	graph.addVertex("RS Prima Medika", 4, 4, 4);

	graph.addVertex("Sinar Photo", 5, 5, 5);

	graph.addVertex("Karung Jantan", 6, 6, 6);

	graph.addVertex("Kober", 7, 7, 7);

	graph.addVertex("Marugame", 8, 8, 8);
	graph.addVertex("Kober", 8, 7, 7);
	graph.addVertex("Karung Jantan", 8, 6, 6);

	graph.addVertex("Ace Hardware", 9, 9, 9);
	graph.addVertex("Marugame", 9, 8, 8);

	graph.addVertex("The Ship", 10, 10, 10);
	graph.addVertex("Ace Hardware", 10, 9, 9);

	graph.addVertex("Matahari", 11, 11, 11);
	graph.addVertex("UNUD", 11, 14, 14);
	graph.addVertex("Gacoan", 11, 16, 16);

	graph.addVertex("Level 21", 12, 12, 12);
	graph.addVertex("iBox 1", 12, 20, 20);

	graph.addVertex("INDORASA", 13, 13, 13);
	graph.addVertex("Matahari", 13, 11, 11);
	graph.addVertex("Level 21", 13, 12, 12);

	graph.addVertex("UNUD", 14, 14, 14);

	graph.addVertex("Eka Print", 15, 15, 15);
	graph.addVertex("Sinar Photo", 15, 5, 5);

	graph.addVertex("Gacoan", 16, 16, 16);
	graph.addVertex("STIKOM", 16, 18, 18);

	graph.addVertex("IGOR", 17, 17, 17);
	graph.addVertex("Matahari", 17, 11, 11);

	graph.addVertex("STIKOM", 18, 18, 18);
	graph.addVertex("IGOR", 18, 17, 17);

	graph.addVertex("Ayam Gepuk", 19, 19, 19);
	graph.addVertex("Karung Jantan", 19, 6, 6);

	graph.addVertex("iBox", 20, 20, 20);
	graph.addVertex("The Ship", 20, 10, 10);
    graph.showGraph();

    cout << "\n >> Input Source & Destination" << endl;
    int source, des;

    cin >> source >> des;
    auto start  = chrono::steady_clock::now();
    graph.DFS(source, des);
    
    // Menghitung Runtime
    auto end = chrono::steady_clock::now();
	auto diff = end - start;
    cout << " - Compilation Time:" << endl;
	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
	return 0;

}   