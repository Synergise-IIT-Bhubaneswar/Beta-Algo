/* Breadth-first search is an algorithm for searching a graph for a node that satisfies a given property. It starts at the tree root and 
explores all nodes at the present depth prior to moving on to the nodes at the next depth level.*/

import java.util.*;

public class BFS_directed_graph
{
    private int v;
    private LinkedList <Integer> adj[];
    
    BFS_directed_graph(int ver)
    {
        v=ver;
        adj=new LinkedList[v];
        for(int i=0;i<v;i++)
            adj[i]=new LinkedList();
    }

    void addEdge(int x, int y)
    {
        adj[x].add(y);
    }

    void BFSalgo(int s)
    {
        boolean vis[]=new boolean[v];
        LinkedList <Integer> queue =new LinkedList();
        vis[s]=true;
        queue.add(s);
        while(queue.size()!=0)
        {
            s=queue.poll();
            System.out.print(s+" ");
            Iterator <Integer> it=adj[s].listIterator();
            while(it.hasNext())
            {
                int n=it.next();
                if(!vis[n])
                {
                    vis[n]=true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of vertices: ");
        int accept=sc.nextInt();
        BFS_directed_graph obj=new BFS_directed_graph(accept);
        System.out.println("Enter the number of edges: ");
		int e=sc.nextInt();
        for(int i=0;i<e;i++)
		{
			System.out.println("Enter edge "+i+": ");
			int x=sc.nextInt();
			int y=sc.nextInt();
			obj.addEdge(x, y);
		}
        System.out.println("BFS starting from vertex 1 is: ");
		obj.BFSalgo(1);
    }
}