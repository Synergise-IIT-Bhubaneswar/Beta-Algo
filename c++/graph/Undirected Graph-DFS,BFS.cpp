/*
    DFS - BFS of undirected graph.


    First, input the number of nodes(n), and number of edges(m) in the graph.

    Then input m pairs of adjacent nodes, and create an adjacency list.

    Then bfs and dfs function is called.

    The time complexity of DFS and BFS is O(n+m)


*/

#include <bits/stdc++.h> 

using namespace std;

class graph{

    int n,m;                   // n - number of nodes, m - number of edges
    vector<vector<int>> adj;   // adjacency list
    public:
    graph(){
        cin>>n>>m;
        adj.resize(n+1);        
        create_adjacency(); 
    }
    void create_adjacency(){
        for(int i=0;i<m;i++){
            int u,v; cin >> u >> v;    // adjacent nodes
            adj[u].push_back(v);      
            adj[v].push_back(u);
        }
    }
    void dfs(int x){                  // dfs starts at node x
        vector<bool> vis(n+1,false);  //  visited vector is created to mark which nodes are visited
        dfsrec(x,vis);                // dfsrec function is called with starting node x
    }
    void bfs(int x){                  // bfs start at node x
        vector<bool> vis(n+1,false);  // visited vector is created to mark which nodes are visited
        bfsrec(x,vis);                // dfsrec function is called with starting node x
    }
    private:
    void dfsrec(int x,vector<bool> &vis){
        cout << x << "\n";            // current node is printed
        vis[x] = true;                // current node is mark visited
        for(auto p:adj[x]){           // current node's adjacency list is traversed 
            if(vis[p]) continue;      // if this neighbour is already visited, we skip it
            dfsrec(p, vis);           // if this neighbouor is not visited, we run dfs from this node
        }
    }
    void bfsrec(int x, vector<bool> &vis){
        queue<int> q1;                // queue q1 is created to store order of nodes
        q1.push(x);                   // the given node x is pushed into the queue
        vis[x] = true;                // x is marked visited
        while(!q1.empty()){           
            int node = q1.front();    // current element at front is stored in node and then popped from the queue
            cout << node << " ";      // node is printed
            q1.pop();            
            for(auto z:adj[node]){    // node's neighbour is traversed
                if(vis[z]) continue;  // if it is already marked visited, then skip 
                vis[z] = true;        // mark the neighbour visited
                q1.push(z);           // push this neighbour in the queue
            }
        }
        cout << "\n";
    }

};


int main(){

    graph g;  // create a graph g

    g.dfs(1); // pass the starting node for dfs
    g.bfs(1); // pass the starting node for bfs

    return 0;
}