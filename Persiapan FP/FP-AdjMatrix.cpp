#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Graph
{
protected:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjMatrix = vector<vector<int>>(numVertices, vector<int>(numVertices, 0));
        // Array 2 dimensi, di dalam vektor ada vektor, lalu di dalamnya barulah angka-angka yang diisi angka 0
    }

    void addEdge(int src, int dest)
    {
        adjMatrix[src][dest] = 1;
    }

    void BFS(int startVertex, int endVertex)
    {
        vector<bool> visited(adjMatrix.size(), false);
        vector<int> q;
        q.push_back(startVertex);

        visited[startVertex] = true;

        int vis;
        while (!q.empty())
        {
            vis = q[0];
            cout << "[Vertex " << vis << "]" << endl;
            if (vis == endVertex)
                break;

            for (int i = 0; i < adjMatrix[vis].size(); i++)
            {
                if (adjMatrix[vis][i] == 1 && (!visited[i]))
                {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
            q.erase(q.begin());
        }
        cout << "END" << endl;
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (i < 10)
                cout << i << "  : ";
            else
                cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 0)
                    cout << ". ";
                else
                    cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph grph(24);
    grph.addEdge(0, 18);
    grph.addEdge(0, 15);
    grph.addEdge(0, 6);
    grph.addEdge(0, 9);

    grph.addEdge(1, 19);

    grph.addEdge(2, 23);


    grph.addEdge(3, 2);

    grph.addEdge(4, 21);

    grph.addEdge(5, 4);

    grph.addEdge(6, 7);
    grph.addEdge(6, 1);

    grph.addEdge(7, 19);

    grph.addEdge(8, 6);

    grph.addEdge(9, 8);
    grph.addEdge(9, 10);

    grph.addEdge(10, 12);

    grph.addEdge(11, 10);
    grph.addEdge(11, 8);

    grph.addEdge(12, 11);

    grph.addEdge(14, 13);

    grph.addEdge(15, 14);
    grph.addEdge(15, 16);

    grph.addEdge(18, 17);
    grph.addEdge(18, 3);

    grph.addEdge(19, 20);

    grph.addEdge(20, 5);

    grph.addEdge(21, 2);

    grph.addEdge(23, 22);

    cout << "\n>>> ADJACENCY LIST REPRESENTATION:" << endl;
    grph.printGraph();

    int dest;
    cout << "\n>>> Input Destination: \n";
    cin >> dest;
    cout << "\n>>> GRAPH BFS ALGORITHM FROM 0 TO " << dest << ":" << endl;
    grph.BFS(0, dest);

    return 0;
}