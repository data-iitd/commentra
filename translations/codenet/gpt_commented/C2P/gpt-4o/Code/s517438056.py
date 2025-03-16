import math

def main():
    # Read the number of vectors (N) and their dimensions (D) from user input
    N, D = map(int, input().split())

    # Allocate a 2D list (matrix) to hold N vectors of D dimensions
    matrix = []
    for _ in range(N):
        vector = list(map(int, input().split()))
        matrix.append(vector)

    # Calculate the pairwise distances between all vectors
    k = 0  # Variable to count pairs with integer distances
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0  # Variable to accumulate the squared differences
            # Calculate the squared distance between vector i and vector j
            for n in range(D):
                m += (matrix[i][n] - matrix[j][n]) ** 2
            # Calculate the Euclidean distance
            l = math.sqrt(m)
            # Check if the distance is an integer
            if l.is_integer():
                k += 1

    # Output the count of pairs of vectors with integer distances
    print(k)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
