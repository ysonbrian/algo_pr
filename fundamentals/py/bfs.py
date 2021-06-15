def bfs(graph, start_node):
    visited = []
    need_visit = []

    need_visit.append(start_node)
    count = 0
    while need_visit:
        node = need_visit.pop(0)
        count += 1
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])
    print(count)
    return visited

graph = dict()

graph['A'] = ['B', 'C']
graph['B'] = ['A', 'D']
graph['C'] = ['A', 'G', 'H', 'I']
graph['D'] = ['B', 'E', 'F']
graph['E'] = ['D']
graph['F'] = ['D']
graph['G'] = ['C']
graph['H'] = ['C']
graph['I'] = ['C', 'J']
graph['J'] = ['I']

bfs(graph, 'A')