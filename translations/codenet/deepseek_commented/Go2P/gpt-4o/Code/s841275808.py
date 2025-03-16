import sys

def main():
    # Reads the number of elements N.
    N = int(sys.stdin.readline().strip())
    
    # Initializes lists X and Y to store N integers.
    X = list(map(int, sys.stdin.readline().strip().split()))
    Y = X.copy()
    
    # Sorts list Y in ascending order.
    Y.sort()
    
    # Calculates the two middle values of the sorted list Y.
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]
    
    # For each element in list X, prints the corresponding median value.
    for i in range(N):
        if X[i] <= m1:
            print(m2)
        else:
            print(m1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
