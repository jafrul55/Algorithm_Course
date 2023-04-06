def Count_connected_component(graph):
    visited = set() #To track of visiting nodes
    component = 0  #To count the number of connected component
    
    def dfs(node):
        visited.add(node)
        for neighbour in graph[node]:
            if neighbour not in visited:
                dfs(neighbour)


    #iterate over all node in the graph
    for node in graph:
        if node not in visited:
            dfs(node)
            component += 1
    return component

#input:
graph1 = {
    1:[2,3],
    2:[1,3],
    3:[1,2],
    4:[5],
    5:[4]
}

graph2 = {
    1:[2,3],
    2:[1,3],
    3:[1,2],
    4:[5],
    5:[4],
    6:[]
}


Number = Count_connected_component(graph1)
print(f"The number of connected component: {Number}")

    
    

