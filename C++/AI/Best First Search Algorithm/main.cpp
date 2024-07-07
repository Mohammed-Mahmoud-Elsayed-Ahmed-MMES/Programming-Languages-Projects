#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

/* `typedef pair<int, int> pi;` is a statement in C++ which creates an alias `pi` for the data type
`pair<int, int>`. Here, `pair<int, int>` is a standard template library (STL) class in C++ that stores a
pair of two elements of `int` data type.

By using the `typedef` keyword, we can define our own name for this `pair<int, int>` data type as `pi`.
So, `pi` can be used interchangeably with `pair<int, int>` in the code. This can make the code more
readable and easier to write.

For example, we can define a variable of `pi` type as follows:

```
pi myPair = make_pair(1, 2);
```

This creates a `pi` variable named `myPair` by using the `make_pair` function to initialize it with the
values 1 and 2. */

vector<vector<pi> > graph;

/* vector<vector<pi>> graph` is a 2D vector, or a vector of vectors, where each element of the outer vector
represents a node in a graph, and each element of the inner vector represents an edge between that node and
some other node in the graph.

Here, `pi` is likely a struct or pair data structure that represents a weighted edge in the graph.
An example definition of `pi` might be:

```cpp
typedef pair<int, int> pi;
```
where the first value represents the weight of the edge and the second value represents the index of the
other node that the edge connects to.

Therefore, the elements of the inner vector of `graph` will be a collection of `pi` pairs representing all
the edges connected to a particular node represented by its index in the outer vector.*/


// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));

    /* This code is adding an element to the adjacency list of a graph representation.

    Here, `graph` is a vector where each index represents a node in the graph. Each element in the vector is
    a vector of pairs, where each pair represents an edge that connects the current node with another node.

    `push_back` is a function that adds an element to the end of a vector. `make_pair` is a function that
    creates a pair from two arguments.

    So, `graph[x].push_back(make_pair(cost, y))` means that we are adding a new pair (cost, y) to the vector
    located at index x in the graph vector. This represents the fact that node x is connected to node y with
    an edge of cost `cost`.*/
    graph[y].push_back(make_pair(cost, x));
}

// Function For Implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int actual_Src, int target, int n)
{
    vector<bool> visited(n, false);
    // MIN HEAP priority queue
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    // sorting in pq gets done by first value of pair
    /* `priority_queue<pi, vector<pi>, greater<pi>> pq` is a declaration of a priority queue object called `pq`.
    The queue elements are pairs of integers (`pi` is most likely a typedef for `pair<int,int>`).
    The third argument `greater<pi>` is a function object used as a comparator which compares the pairs in
    such a way that the smallest element appears at the top of the queue.

    In other words, the `greater<pi>` comparator is applied to the `pi` elements in the priority queue,
    and it ensures that the smallest element is always at the top of the queue, as determined by
    the `>` operator. By default, the priority queue sorts elements in decreasing order, which means
    the largest element appears at the top of the queue. In this case, the third argument specifies a
    custom comparator to use instead.*/
    pq.push(make_pair(0, actual_Src));
    int s = actual_Src;
    visited[s] = true;
    while (!pq.empty()) {
        int x = pq.top().second;
        // Displaying the path having lowest cost

        /* This is a C++ statement that assigns the value of the second element from the top element of the
        priority queue `pq` to an integer variable `x`. Here, `pq.top()` returns the top element of the
        priority queue (i.e., the one with the highest priority value), and `pq.top().second` returns the
        second element of that top element. The `second` element refers to the value of the second item in a
        pair, which is commonly used to store two related values. Thus, `int x = pq.top().second` assigns
        this value to the integer variable `x`.*/

        cout << x << " ";
        pq.pop();
        if (x == target)
            break;

        for (int i = 0; i < graph[x].size(); i++) {
            if (!visited[graph[x][i].second]) {
                visited[graph[x][i].second] = true;
                pq.push(make_pair(graph[x][i].first,graph[x][i].second));
            }
        }
    }
}

// Driver code to test above methods
int main()
{
    // No. of Nodes
    int v = 14;
    graph.resize(v);

    // The nodes shown in above example(by alphabets) are
    // implemented using integers addedge(x,y,cost);
    addedge(0, 1, 3);
    addedge(0, 2, 6);
    addedge(0, 3, 5);
    addedge(1, 4, 9);
    addedge(1, 5, 8);
    addedge(2, 6, 12);
    addedge(2, 7, 14);
    addedge(3, 8, 7);
    addedge(8, 9, 5);
    addedge(8, 10, 6);
    addedge(9, 11, 1);
    addedge(9, 12, 10);
    addedge(9, 13, 2);

    int source = 0;
    int target = 9;

    // Function call
    best_first_search(source, target, v);
    return 0;
}
