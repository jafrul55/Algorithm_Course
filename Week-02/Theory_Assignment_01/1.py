from collections import defaultdict

def is_bidirectional(graph):
    for node,neighbours in graph.items():
        for neighbour in neighbours:
            if node not in graph[neighbour]:
                return False
    return True

# n = number of nodes
# m = number of edges
n,m = map(int,input().split())

# Create an adjacency list representation of the graph:
graph = defaultdict(list)

for i in range(m):
    u,v = map(int,input().split())
    graph[u].append(v)


#check if the graph is bidirectional:
if is_bidirectional(graph):
    print("The graph is bidirectional.")
else:
    print("This graph is not bidirectional.")


""" 
#for not bidirectional input:
5 6
0 1
1 2
1 3
2 0
3 4
4 1

#for directional input:
4 8
0 1
1 0
1 2
2 1
1 3
3 1
2 3
3 2
"""
