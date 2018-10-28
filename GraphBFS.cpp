#include <iostream>
#include<list>
#include <malloc.h>
using namespace std;

struct graph{
    int V;
    list<int> *adj;
};
graph* createGraph(int V){
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->adj= new list<int>[V];
    return g;
}

void addEdge(graph *g, int v, int w){
    g->adj[v].push_back(w);
}
void BFS(graph *g,int s,int V){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g->adj[s].begin(); i != g->adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main() {
    graph *adj = createGraph(4);
    addEdge(adj,0, 1);

    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);

    BFS(adj,2,4);
    return 0;
}