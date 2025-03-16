import math

def main():
    n, d = map(int, input().split())
    point = [[0] * (d + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        point[i] = list(map(int, input().split()))
    
    count = 0
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            sum_squared = 0
            for k in range(1, d + 1):
                sum_squared += (point[i][k] - point[j][k]) ** 2
            distance = math.sqrt(sum_squared)
            if math.ceil(distance) == math.floor(distance):
                count += 1
    
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
