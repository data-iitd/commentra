def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    A = list(map(int, data[1:N+1]))
    
    count = 0
    i = 0
    
    while i < N:
        if i == N - 1:
            count += 1
            break
        elif A[i] == A[i + 1]:
            i += 1
        elif A[i] < A[i + 1]:
            while i < N - 1 and A[i] <= A[i + 1]:
                i += 1
            count += 1
        else:
            while i < N - 1 and A[i] >= A[i + 1]:
                i += 1
            count += 1
    
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
