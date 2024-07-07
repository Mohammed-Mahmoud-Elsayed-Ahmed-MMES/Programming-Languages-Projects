#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Depth-limited search function
bool DLS(int depth, int target, int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    if(node == target)
        return true;

    if(depth <= 0)
        return false;

    visited[node] = true;

    for(int nextNode: graph[node])
    {
        if(!visited[nextNode])
        {
            if(DLS(depth-1, target, nextNode, graph, visited))
                return true;
        }
    }

    visited[node] = false;

    return false;
}

// Iterative deepening function
bool IDS(int start, int target, vector<vector<int>>& graph, int maxDepth)
{
    // Implement iterative deepening by gradually increasing the depth
    for(int depth=0; depth<=maxDepth; ++depth)
    {
        vector<bool> visited(graph.size(), false);

        if(DLS(depth, target, start, graph, visited))
            return true;
    }

    // Target node not found
    return false;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {3, 4}, {5}, {2}, {2}, {7}, {8}, {10}, {}};
    int start = 0, target = 10, maxDepth = 5;

    if(IDS(start, target, graph, maxDepth))
        cout << "Target found!" << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
