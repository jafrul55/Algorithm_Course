# Adjacency matrix to adjacency list:
def adjacency_matrix_to_list(matrix):
    n = len(matrix)
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i,n):
            if matrix[i][j] == 1:
                adj_list[i].append(j)
                adj_list[j].append(i)
    return adj_list

matrix = [
    [0, 1, 1, 0],
    [1, 0, 1, 1],
    [1, 1, 0, 1],
    [0, 1, 1, 0]
]
print(adjacency_matrix_to_list(matrix))