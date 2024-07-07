/* Depth First Search is an algorithm for traversing or searching tree or graph data structures.
And it is working FROM-LEFT(branches)-TO-RIGHT(branches).
And uses Stack and Recursion in its code.*/

#include <bits/stdc++.h>
#include <stack>
using namespace std;

int num_of_edges,from,to,goal,start;
stack<int> openList;
vector<int> adj[150009],answer;//answer = closedList
vector<int> closedList;
bool visited[150009],done;

//Another DFS function like Eng/M.Elnamouly and i prefer it because it is similar to BFS with slight differences.
void DFS(int start)
{
    openList.push(start);
    visited[start] = true;
    while(!openList.empty())
    {
        int currentState = openList.top();
        openList.pop();
        closedList.push_back(currentState);
        if(currentState == goal)
            return;
        for(auto state:adj[currentState])
        {
            DFS(state);
        }
    }
    return;
}
//I add it because the new DFS function
void Display()
{
    cout << "The path is : " << endl;
    for(int i = 0; i < closedList.size(); i++)
    {
        cout << closedList[i] << " ";
    }
}
int main()
{
    cout<<"Enter number of edges: ";
    cin>>num_of_edges;
    cout<<"Enter the edges: ";
    for(int i=0;i<num_of_edges;i++){
        cin>>from>>to;
        adj[from].push_back(to);
    }
    cout<<"Enter the starting node: ";
    cin>>start;
    cout<<"Enter the goal: ";
    cin>>goal;
    DFS(start);
    /*cout<<"The order of the nodes to reach the goal is: ";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }*/
    Display();

    return 0;
}
