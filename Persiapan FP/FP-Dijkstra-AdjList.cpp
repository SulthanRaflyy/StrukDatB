#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#include <chrono>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	list<pair<int,int>> adj[21];
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j.first << " ";
	        }
	        cout << endl;
	    }
	}

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();

			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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

    cout << ">> Showing Vertex.." << endl;
	graph.showAllVertex();


	int src;
	cout << "Input Source : ";
	cin >> src;
    auto start  = chrono::steady_clock::now();
    cout << ">> Shortest Path using Dijkstra:" << endl;
    graph.djikstra(src);

     // Menghitung Runtime
    auto end = chrono::steady_clock::now();
	auto diff = end - start;
    cout << " - Compilation Time:" << endl;
	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
	return 0;
}