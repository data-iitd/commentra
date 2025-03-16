import math

def main():
    # Step 1: Reading Input
    N, D = map(int, input().split())
    
    # Allocate memory for the matrix
    matrix = []
    
    # Step 2: Inputting Points
    for _ in range(N):
        point = list(map(int, input().split()))
        matrix.append(point)
    
    # Step 3: Calculating Distances
    k = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0
            for n in range(D):
                m += (matrix[i][n] - matrix[j][n]) ** 2
            l = math.sqrt(m)
            if l.is_integer():
                k += 1
    
    # Step 4: Outputting the Result
    print(k)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
