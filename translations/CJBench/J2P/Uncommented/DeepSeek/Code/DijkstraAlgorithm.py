def get_min_distance_vertex(distances, processed):
    min_value = float('inf')
    min_index = -1
    for v in range(len(distances)):
        if not processed[v] and distances[v] <= min_value:
            min_value = distances[v]
            min_index = v
    return min_index

def run(graph, source, vertex_count):
    if source < 0 or source >= vertex_count:
        raise ValueError("Incorrect source vertex")
    
    distances = [float('inf')] * vertex_count
    processed = [False] * vertex_count
    distances[source] = 0
    
    for count in range(vertex_count - 1):
        u = get_min_distance_vertex(distances, processed)
        processed[u] = True
        for v in range(vertex_count):
            if not processed[v] and graph[u][v] != 0 and distances[u] != float('inf') and distances[u] + graph[u][v] < distances[v]:
                distances[v] = distances[u] + graph[u][v]
    
    return distances

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    vertex_count = int(data[0])
    graph = []
    index = 1
    for i in range(vertex_count):
        row = []
        for j in range(vertex_count):
            row.append(int(data[index]))
            index += 1
        graph.append(row)
    
    source = int(data[-1])
    
    distances = run(graph, source, vertex_count)
    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(len(distances)):
        print("Vertex " + str(i) + " : " + str(distances[i]))

main()
