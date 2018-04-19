import random

def display(adj_matrix):
    print(len(adj_matrix) + 1)
    for row in adj_matrix:
        for cell in row:
            print(cell, end=' ')
        print()

def fill(p):
    if random.random() <= p:
        return 1
    return 0


tokens = input().split()
n = int(tokens[0])
p = float(tokens[1])
adj = []
for i in range(n - 1):
    adj.append([])
    for j in range(i + 1, n):
        adj[i].append(fill(p))
display(adj)
