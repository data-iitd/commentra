import math

def main():
    n, d = map(int, input().split())
    points = [list(map(int, input().split())) for _ in range(n)]
    
    count = 0
    
    for i in range(n - 1):
        for j in range(i + 1, n):
            sum_of_squares = 0
            for k in range(d):
                sum_of_squares += (points[i][k] - points[j][k]) ** 2
            
            distance = math.sqrt(sum_of_squares)
            
            if math.ceil(distance) == math.floor(distance):
                count += 1
    
    print(count)

main()
