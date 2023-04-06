from collections import defaultdict

adj_list = defaultdict(list)

n,m = map(int,input().split())
for i in range(m):
    u,v = map(int,input().split())
    adj_list[u].append(v)

count_edge = 0
for u in list(adj_list.keys()):  # make a copy of the keys to avoid dic size error
    for v in adj_list[u]:
        if u not in adj_list[v]:
            count_edge += 1
    
print(f"Not bidirectional value->{count_edge}")

""" 
#Not bidirection value is:
4 6
1 0 
0 1 
1 3 
3 1 
1 2 
3 2 
----------
4 7
1 0 
0 1 
1 3 
3 1 
1 2
2 1 
3 2
--------
4 5
1 0 
1 3 
3 1 
1 2 
3 2 
"""
