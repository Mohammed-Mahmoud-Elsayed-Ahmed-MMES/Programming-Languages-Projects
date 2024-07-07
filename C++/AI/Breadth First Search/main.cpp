/*Breadth-first search (BFS) is an algorithm used for traversing or searching tree or
graph data structures. It starts at the tree root (or some arbitrary node of a graph)
and explores the neighbor nodes first, before moving to the next level neighbors.
This algorithm is used to find the shortest path between two nodes in an unweighted graph or a tree.
BFS can also be used to find all the connected components of a graph.*/

//Level-by-Level

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// create used variables & lists
int initialState,goalState,numOfEdges,from,to,depth[100];
bool visited[1000];
queue<int> openList;
vector<int> stateSpace[1000]; //Contains Edges
vector<int> closedList;

void stateSpaceGraph()
{
    cout << "Enter number of edges : " << endl;
    cin >> numOfEdges;

    cout << "Enter edges : " << endl;
    for(int i = 0; i < numOfEdges; i++)
    {
        cin >> from >> to;
        stateSpace[from].push_back(to);
        //In other words, it creates an edge from the `from` node to the `to` node.
    }
}

void BFS(int start)
{
    openList.push(start);
    /*Overall, the `push()` method is commonly used in JavaScript to add elements to an array.
    In this case, it is used to add a new node to a list of nodes to be evaluated.*/
    depth[start] = 0;
    visited[start] = true;

    while(!openList.empty())
    {
        int currentState = openList.front();
        /*is used to access the first element of the container openList. The container must be non-empty
        for this function to be called. If the container is empty, calling this function results
        in undefined behavior*/

        openList.pop();
        /* is used to remove the first element and return the last element from the `openList` array.
        The `pop()` method is a built-in method of the array object in JavaScript.
        In the context of this code, `openList` is likely being used to keep track of a list of
        items that need to be processed or searched through, and using `pop()` can be useful
        when working through this list, as it allows you to work with the most recent addition to
        the list first,and to remove the nodes that have been visited in a search algorithm. */

        closedList.push_back(currentState);
        /* is used to add the currentState object to the end of the container closedList.
        This function is used to store the visited states in a search algorithm.
        The container can be any sequence container that supports insertion at the end such
        as vector, deque, etc.*/
        if(currentState == goalState)
            return;
        for(auto state:stateSpace[currentState])
        /* The `for` loop with the variable `state` is known as a "range-based for loop,"
        and it allows you to iterate over a range of values, which in this case is the `stateSpace[currentState]`.
       `stateSpace` is likely a two-dimensional array or matrix that stores all possible states of a system.
       `currentState` is an index that specifies the current state of the system.
       In the code, we are using the range-based `for` loop to iterate over all possible states that
       can be reached from the current state and storing them in the `state` variable.
       So, in summary,
       this code loops through all possible states that can be reached from the current state and
       performs some action on each of them. The exact action being performed on each state would
       need to be determined by examining the rest of the code.*/
        {
            if(visited[state])
            {
                continue;
                /*is used to skip the current iteration of a loop and move on to the next iteration.
                This statement is used to control the flow of a loop.*/
            }
            openList.push(state);
            visited[state]=true;
            depth [state] = depth[currentState]+1;

        }
    }
    return;
}

void Display()
{
    cout << "The path is : " << endl;
    for(int i = 0; i < closedList.size(); i++)
    {
        cout << closedList[i] << " ";
    }
    cout << "The goal in level number " << depth[goalState] << endl;
}

int main()
{
    stateSpaceGraph();
    cout<<"Enter inintial state: " << endl;
    cin>>initialState;
    cout<<"Enter goal state: " << endl;
    cin>>goalState;
    BFS(initialState);
    Display();

    return 0;
}
