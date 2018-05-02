import random

def display(adj_matrix):
    print(len(adj_matrix) + 1)
    for row in adj_matrix:
        for cell in row:
            print(cell, end=' ')
        print()

tokens = input().split()
n = int(tokens[0])
m = int(tokens[1])
adj = []
options = []
for i in range(n - 1):
    adj.append([0] * (n - i - 1))
    for j in range(len(adj[i])):
        options.append((i, j))
selected = random.sample(options, m)
for pos in selected:
    adj[pos[0]][pos[1]] = 1
display(adj)
