'''
BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) 
and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). 
You must then move towards the next-level neighbour nodes.
'''


class Graph:

	def __init__(self, vertices):

		# adjacency list to store the graph
		self.adj = []
		self.vertices = vertices

		# building adjacency list
		for i in range(vertices):
			self.adj.append([])


	def bfsUtil(self, v, visited):

		# initialize a queue for BFS
		queue = []

		# enque the start node and mark it visited
		queue.append(v)
		visited.add(v)

		while queue:

			# deqeue a node from queue and print it
			v = queue.pop(0)
			print(v, end = " ")

			# enqueue all the adjacent node of the current
			# node which are not visited yet.
			for u in self.adj[v]:
				if u not in visited:
					queue.append(u)
					visited.add(u)


	def bfs(self):

		# visited set stores all the visited vertices
		visited = set()

		print("Breadth-First Traversal of the graph")

		for v in range(self.vertices):
			# handling the connected components
			if v not in visited:
				self.bfsUtil(v, visited)
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

	g.bfs()           # call the bfs function


if __name__ == '__main__':
	main()

'''
Time Complexity: O(vertices + edges)
Space Complexity: O(vertices)

INPUT:
Enter number of vertices: 5
Enter number of edges: 5
Enter the edges
0 1
0 2
2 3
3 1
0 4

OUTPUT:
Breadth-First Traversal of the graph
0 1 2 4 3 
'''