# Adjacency list to adjacency matrix:
def adjacency_list_to_matrix(adj_list):
    n = len(adj_list)
    matrix = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in adj_list[i]:
            matrix[i][j] = 1
            matrix[j][i] = 1
    return matrix

adj_list = [
    [1, 2], 
    [0, 2, 3], 
    [0, 1, 3], 
    [1, 2]
]

matrix = adjacency_list_to_matrix(adj_list)
for row in matrix:
    print(row)
