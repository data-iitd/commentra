
import numpy as np
def main():
    n = int(input())
    matrix = np.empty((n, n))
    for i in range(n):
        matrix[i] = list(map(float, input().split()))
    inverse = np.linalg.inv(matrix)
    for row in inverse:
        print(*row)
if __name__ == "__main__":
    main()
