#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#include  <chrono>
using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }

    void shortestDistance(int src, int dest){
		int pred[V], dist[V];
		cout << " - Shortest Path:" << endl;
		shortest_path(src, dest, pred, dist);
		vector<int> path;
		int c = dest;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		cout << " - Shortest Distance:" << endl;
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	graph.addVertex("Fr House", 1, 1);
	graph.addVertex("INDORASA", 1, 13);
	graph.addVertex("Sanglah Market", 1, 3);
	graph.addVertex("RS Ngoerah", 1, 2);

	graph.addVertex("RS Ngoerah", 2, 2);
	graph.addVertex("Ayam Gepuk", 2, 19);

	graph.addVertex("Sanglah Market", 3, 3);
	graph.addVertex("RS Prima Medika", 3, 4);
	graph.addVertex("Eka Print", 3, 15);

	graph.addVertex("RS Prima Medika", 4, 4);

	graph.addVertex("Sinar Photo", 5, 5);

	graph.addVertex("Karung Jantan", 6, 6);

	graph.addVertex("Kober", 7, 7);

	graph.addVertex("Marugame", 8, 8);
	graph.addVertex("Kober", 8, 7);
	graph.addVertex("Karung Jantan", 8, 6);

	graph.addVertex("Ace Hardware", 9, 9);
	graph.addVertex("Marugame", 9, 8);

	graph.addVertex("The Ship", 10, 10);
	graph.addVertex("Ace Hardware", 10, 9);

	graph.addVertex("Matahari", 11, 11);
	graph.addVertex("UNUD", 11, 14);
	graph.addVertex("Gacoan", 11, 16);

	graph.addVertex("Level 21", 12, 12);
	graph.addVertex("iBox 1", 12, 20);

	graph.addVertex("INDORASA", 13, 13);
	graph.addVertex("Matahari", 13, 11);
	graph.addVertex("Level 21", 13, 12);

	graph.addVertex("UNUD", 14, 14);

	graph.addVertex("Eka Print", 15, 15);
	graph.addVertex("Sinar Photo", 15, 5);

	graph.addVertex("Gacoan", 16, 16);
	graph.addVertex("STIKOM", 16, 18);

	graph.addVertex("IGOR", 17, 17);
	graph.addVertex("Matahari", 17, 11);

	graph.addVertex("STIKOM", 18, 18);
	graph.addVertex("IGOR", 18, 17);

	graph.addVertex("Ayam Gepuk", 19, 19);
	graph.addVertex("Karung Jantan", 19, 6);

	graph.addVertex("iBox", 20, 20);
	graph.addVertex("The Ship", 20, 10);

	cout << "\n>> Showing Vertex .." << endl;
	graph.showAllVertex();

	cout << "\n>> Input Source & Destination" << endl;
	int source, dest;
	cin >> source >> dest;

	cout << ">> Shortest Distance" << endl;
	auto start  = chrono::steady_clock::now();
    graph.shortestDistance(source,dest);

	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << " - Compilation Time:" << endl;
	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
	return 0;
}