#include <iostream>
using namespace std;
int graph[100][100];
bool visited[100];
void DFS(int node, int n)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == false)
        {
            DFS(i, n);
        }
    }
}
void BFS(int start, int n)
{
    bool seen[100] = {false};
    int q[100];
    int front = 0, rear = 0;
    q[rear++] = start;
    seen[start] = true;
    while (front < rear)
    {
        int node = q[front++];
        cout << node << " ";
        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1 && seen[i] == false)
            {
                q[rear++] = i;
                seen[i] = true;
            }
        }
    }
}
int main()
{
    int n, e, u, v, start;
    cout << "Enter number of buildings: ";
    cin >> n;
    cout << "Enter number of roads: ";
    cin >> e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Enter roads between buildings:\n";
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "Enter starting building: ";
    cin >> start;
    cout << "DFS Traversal: ";
    DFS(start, n);
    cout << "\nBFS Traversal: ";
    BFS(start, n);
    cout << endl;
    return 0;
}