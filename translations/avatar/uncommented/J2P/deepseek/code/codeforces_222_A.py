import sys

def main():
    n, k, l = map(int, sys.stdin.readline().split())
    lines = [int(sys.stdin.readline().strip()) for _ in range(n)]
    
    count = 1
    max_count = 0
    
    for i in range(1, n):
        if lines[i] == lines[i - 1]:
            count += 1
        else:
            max_count = max(max_count, count)
            count = 1
    
    max_count = max(max_count, count)
    
    if max_count + k > n:
        print(n - max_count)
    else:
        print(-1)

if __name__ == "__main__":
    main()
