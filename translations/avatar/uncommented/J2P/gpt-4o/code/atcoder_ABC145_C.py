import math

def main():
    N = int(input())
    pos = [list(map(int, input().split())) for _ in range(N)]
    
    total_distance = 0
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            total_distance += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
    
    print(total_distance / N)

def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
