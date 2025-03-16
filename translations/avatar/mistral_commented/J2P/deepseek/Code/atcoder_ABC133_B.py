import math
import sys

def main():
    # Reading the number of vectors N and their dimensions D from user input
    N, D = map(int, sys.stdin.readline().split())

    # Creating a 2D integer array 'vectors' of size N x D to store the vectors
    vectors = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    # Initializing the answer variable to 0
    answer = 0

    # Iterating through all pairs of vectors (i, j) where i < j
    for i in range(N - 1):
        for j in range(i + 1, N):

            # Calculating the Euclidean distance between the vectors i and j
            dist = 0
            for d in range(D):
                x = vectors[i][d] - vectors[j][d]  # Difference between corresponding components
                dist += (x * x)  # Squaring the difference and adding to the distance

            # Calculating the square root of the distance and checking if it is a perfect square
            sq = math.sqrt(dist)
            answer += (abs(sq - math.floor(sq)) < 0.001)

    # Printing the final answer
    print(answer)

if __name__ == "__main__":
    main()

