import sys

def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().split()))
    A.sort(reverse=True)
    max_diff = float('inf')
    result_pair = (0, 0)
    
    for i in range(1, N):
        diff = abs(A[0] - 2 * A[i])
        if diff < max_diff:
            max_diff = diff
            result_pair = (A[0], A[i])
    
    print(result_pair[0], result_pair[1])

if __name__ == "__main__":
    main()
