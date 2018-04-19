from graph_tool.all import *

n = int(input())
G = Graph(directed=False)
V = [G.add_vertex() for i in range(n)]
for i in range(n - 1):
    E = [x for x in input().split()]
    for j in range(len(E)):
        if E[j] == '1':
            G.add_edge(V[i], V[i + j + 1])
graph_draw(G, vertex_text=G.vertex_index, vertex_font_size=18,
   output_size=(512, 512), output='out.png')
