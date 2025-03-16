import math

def main():
    N, D = map(int, input().split())
    matrix = []
    
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)
    
    k = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0
            for n in range(D):
                m += (matrix[i][n] - matrix[j][n]) ** 2
            l = math.sqrt(m)
            if l.is_integer():
                k += 1
    
    print(k)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
