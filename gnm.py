import random

def connected(selected, n):
    M = [False] * n
    adj = [None] * n
    for i in range(n):
        adj[i] = [False] * n
    for p in selected:
        adj[p[0]][p[1]] = True
        adj[p[1]][p[0]] = True
    S = [0]
    M[0] = True
    while len(S) > 0:
        cur = S.pop()
        for i in range(n):
            if adj[cur][i] and not M[i]:
                M[i] = True
                S.append(i)
    for i in range(n):
        if not M[i]:
            return False
    print(n)
    for i in range(n):
        for j in range(n):
            if adj[i][j]:
                print(j, end=' ')
        print()
    return True

tokens = input().split()
n = int(tokens[0])
m = int(tokens[1])
options = []
for i in range(n):
    for j in range(i + 1, n):
        options.append((i, j))

while True:
    selected = random.sample(options, m)
    if connected(selected, n):
        break
