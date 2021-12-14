'''
The Depth-First Search is a recursive algorithm that uses the concept of backtracking. It involves 
thorough searches of all the nodes by going ahead if potential, else by backtracking.
'''

class Graph:

	def __init__(self, vertices):

		# adjacency list to store the graph
		self.adj = []
		self.vertices = vertices

		# building adjacency list
		for i in range(vertices):
			self.adj.append([])

	def dfsUtil(self, v, visited):

		# visit the current node
		print(v, end = " ")

		# mark the current node as visited
		visited.add(v)

		# recur for all the adjacent nodes
		for u in self.adj[v]:
			# recur for adjacent node only when it is not visited before
			if u not in visited:
				self.dfsUtil(u, visited)


	def dfs(self):

		# visited set stores all the visited vertices
		visited = set()

		print("Depth-first Traversal of Graph");

		for v in range(self.vertices):
			# recur for each connected component 
			if v not in visited:
				self.dfsUtil(v, visited)
				print()


def main():

	vertices = int(input("Enter number of vertices: "))

	g = Graph(vertices)

	edges = int(input("Enter number of edges: "))

	# adding edges in the graph
	print("Enter the edges")
	for i in range(edges):

		u, v = input().split()
		u, v = int(u), int(v)

		g.adj[u].append(v)
		g.adj[v].append(u)

	g.dfs()           # call the dfs function


if __name__ == '__main__':
	main()

'''
Time Complexity: O(vertices + edges)
Space Complexity: O(vertices)

INPUT:
Enter number of vertices: 4
Enter number of edges: 3
Enter the edges
0 1
2 3
0 3

OUTPUT:
Depth-first Traversal of Graph
0 1 3 2 
'''
