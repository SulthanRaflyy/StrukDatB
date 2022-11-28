#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;

class Graph
{
protected: // Hanya bisa diakses lewat Publin
    int numVertices;
    list<int> *adjLists; // Membuat pointer yang nanti bisa diisi list, dan list nya bisa banyak
    // Ada pointer sehingga berfungsi seperti Array (bisa Lebih dari 1)
    bool *visited;

public: // Langsung bisa diakses
    Graph(int vertices)
    {
        numVertices = vertices;
        // Karena numVertices protected, jadi untuk meng assignnya memerlukan bantuan vertices
        adjLists = new list<int>[vertices];
        // Menyimpan pointer ke jumlah list yang diinginkan
        // Membuat list dgn datatype Integer , [vertices] adalah jumlah listnya
    }

    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        // src = source ; dest = destination
        //  Menambahkan VErtex terdekat
    }

    void BFS(int startVertex, int endVertex)
    {
        visited = new bool[numVertices];
        // visited adalah pointer, dengan new bool[numVertices] adalah array
        // Maka visited menjadi array, karena nilai di array pindah ke pointer
        for (int i = 0; i < numVertices; i++)
            visited[i] = false; // Mengisi nilai defaultnya menjadi false

        list<int> queue;              // Menyimpan Antrian
        visited[startVertex] = true;  // Untuk start langsung menjadi true
        queue.push_back(startVertex); // Memasukkan startVertex dalam Antrian

        list<int>::iterator i;

        while (!queue.empty())
        { // Queue tidak Kosong, maka jalan terus
            int currVertex = queue.front();
            cout << "[Vertex " << currVertex << "]\n";
            if (currVertex == endVertex)
                break;

            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
            {
                // Mencari  vertex terdekat dari CurrVertex
                int adjVertex = *i; // Mengakses value list
                if (!visited[adjVertex])
                { // Akan jalan kalo visited = 0
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex); // Memasukkan vertex ke dalam antrian
                }
            }
            queue.pop_front(); // Menghilangkan vertex yang sudah diproses di awal
        }
        cout << "END" << endl;
    }

    void printGraph()
    {
        list<int>::iterator i;
        for (int it = 0; it < numVertices; it++)
        {
            cout << "Vertex [" << it << "]";
            for (i = adjLists[it].begin(); i != adjLists[it].end(); ++i)
            {
                cout << " -> [" << *i << "]";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph grph(24);
    grph.addEdge(0, 6);
    grph.addEdge(0, 9);
    grph.addEdge(0, 15);
    grph.addEdge(0, 18);

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