import sys

def main():
    N = int(input())
    x = int(input())
    srimeList = []
    for i in range(N):
        srimeList.append(int(input()))
    costList = []
    for i in range(N):
        costList.append([srimeList[i]])
        for castNum in range(1, N):
            costList[i].append(min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]))
    result = []
    for i in range(N):
        result.append(i * x + sum(costList[i]))
    print(min(result))

if __name__ == "__main__":
    main()

