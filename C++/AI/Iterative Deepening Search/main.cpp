/*There are two common ways to traverse a graph, BFS and DFS. Considering a Tree (or Graph) of huge height
and width, both BFS and DFS are not very efficient due to following reasons.

1-DFS first traverses nodes going through one adjacent of root, then next adjacent.
The problem with this approach is, if there is a node close to root, but not in first few subtrees
explored by DFS, then DFS reaches that node very late. Also, DFS may not find shortest path to a
node (in terms of number of edges).

2-BFS goes level by level, but requires more space. The space required by DFS is O(d) where d is depth of
tree, but space required by BFS is O(n) where n is number of nodes in tree (Why? Note that the last level of
tree can have around n/2 nodes and second last level n/4 nodes and in BFS we need to have every level one by one in queue).
IDDFS combines depth-first search’s space-efficiency and breadth-first search’s fast search
(for nodes closer to root).

How does IDDFS work?
IDDFS calls DFS for different depths starting from an initial value. In every call, DFS is restricted from
going beyond given depth. So basically we do DFS in a BFS fashion.*/

#include<bits/stdc++.h>
#include <stack>
using namespace std;

int num_of_edges,from,to,goal,start;
vector<int> adj[150009];
bool visited[150009];

/*class Graph
{
	int V;

	list<int> *adj;

	bool DLS(int src, int target, int limit);

public:

	Graph(int V);

	void addEdge(int src, int des);

	bool IDDFS(int src, int target, int max_depth);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int src, int des)
{
	adj[src].push_back(des);
}
*/
bool DLS(int src, int target, int limit)
{
    if (src == target)
    {
        cout<<"Path : "<<target<<" ";
        return true;
    }

    if (limit <= 0)
        return false;

    for (auto i = adj[src].begin(); i != adj[src].end(); ++i)
    {
        if (DLS(*i, target, limit-1) == true)
        {
            cout<<src<<" ";
            return true;
        }
    }

    return false;
}
/* adj[src].begin() is used to get an iterator pointing to the first element of the adjacency list of
the source vertex. The adjacency list is a collection of vertices adjacent to the source vertex in a graph.
Example src = 0 then begin() will bring the value 1
*/

/* adj[src].end() is used to get an iterator pointing to the end of the adjacency list of the source vertex.
The adjacency list is a collection of vertices adjacent to the source vertex in a graph.*/

/* The *i in this code is a pointer that is used to pass an argument by reference to the function DLS().
It is dereferenced so that the value at the memory address pointed to by i is passed to the function
instead of the address itself. This means that any changes made to the value of *i within the function will
also affect its value outside of the function.

In the given code, *i is passed as the first argument to the DLS() function, which is then used in some way
inside the function logic. Specifically, it is used as one of the parameters to compare with the target
value; if the comparison returns true, the function returns the value true.*/

bool IDDFS(int src, int target, int max_depth)
{

    for (int i = 0; i <= max_depth; i++)
        if (DLS(src, target, i) == true)
            return true;

    return false;
}
int main()
{

    /*Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);*/
    cout<<"Enter number of edges: ";
    cin>>num_of_edges;
    cout<<"Enter the edges: ";
    for(int i=0; i<num_of_edges; i++)
    {
        cin>>from>>to;
        adj[from].push_back(to);
    }
    cout<<"Enter the starting node: ";
    cin>>start;
    cout<<"Enter the goal: ";
    cin>>goal;
    int maxDepth;
    cout<<"Enter the Max Depth: ";
    cin>>maxDepth;

    //int target = 6, maxDepth = 2, src = 0;
    if (IDDFS(start, goal, maxDepth) == true)
        cout << "\nTarget is reachable from source "
             "within max depth";
    else
        cout << "Target is NOT reachable from source "
             "within max depth";
    return 0;
}
