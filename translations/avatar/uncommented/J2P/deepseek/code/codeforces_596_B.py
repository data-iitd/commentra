import sys

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    answer = abs(arr[0])
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])
    
    print(answer)

if __name__ == "__main__":
    main()
