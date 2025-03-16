def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    pos = []
    
    for i in range(1, N + 1):
        x = int(data[i * 2 - 1])
        y = int(data[i * 2])
        pos.append((x, y))
    
    sum_dist = 0
    
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            sum_dist += distance(pos[i], pos[j])
    
    avg_dist = sum_dist / N
    print("{:.10f}".format(avg_dist))

def distance(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5

main()
