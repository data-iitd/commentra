import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    x = int(data[1])
    srimeList = list(map(int, data[2:N+2]))
    
    costList = [[0] * N for _ in range(N)]
    
    for i in range(N):
        costList[i][0] = srimeList[i]
        for castNum in range(1, N):
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])
    
    result = []
    for i in range(N):
        j = i
        total_cost = sum(costArray[j] for costArray in costList)
        result.append(i * x + total_cost)
    
    print(min(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
