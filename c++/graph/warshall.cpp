#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
// defined number of vertices
#define N 4
#define M INT_MAX
void printpath(int path[][N], int v, int u)
{
    if (path[v][u] == v)
        return;

    printpath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}
void solution(int cost[N][N], int path[N][N])
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << "Shortest Path from " << v << " -> " << u << " is ("
                     << v << " ";
                printpath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}
// implemented Floyd warshall Algorithm
void WarshallAlgo(int adjMatrix[][N])
{
    int cost[N][N], path[N][N];
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != INT_MAX)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }
    // Adding vertices individually
    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            if (cost[v][v] < 0)
            {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }
    solution(cost, path);
}

int main()
{
    int adjMatrix[N][N] =
        {
            {0, M, -2, M},
            {4, 0, 3, M},
            {M, M, 0, 2},
            {M, -1, M, 0}};  // graph input
    WarshallAlgo(adjMatrix); // calling of function

    return 0;
}
/*
Time Complexity:O(Ver^3)
Space Complexity:O(Ver^2)
Shortest Path from 0 -> 1 is (0 2 3 1)
Shortest Path from 0 -> 2 is (0 2)
Shortest Path from 0 -> 3 is (0 2 3)
Shortest Path from 1 -> 0 is (1 0)
Shortest Path from 1 -> 2 is (1 0 2)
Shortest Path from 1 -> 3 is (1 0 2 3)
Shortest Path from 2 -> 0 is (2 3 1 0)
Shortest Path from 2 -> 1 is (2 3 1)
Shortest Path from 2 -> 3 is (2 3)
Shortest Path from 3 -> 0 is (3 1 0)
Shortest Path from 3 -> 1 is (3 1)
Shortest Path from 3 -> 2 is (3 1 0 2)*/