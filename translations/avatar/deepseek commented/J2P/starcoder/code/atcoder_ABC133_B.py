
import math
import sys

def main():
    # Read the number of vectors (N) and the dimension (D)
    N, D = map(int, sys.stdin.readline().split())

    # Initialize the array to store the vectors
    vectors = []
    for i in range(N):
        vectors.append(list(map(int, sys.stdin.readline().split())))

    # Initialize the answer variable
    answer = 0

    # Calculate the Euclidean distance between each pair of vectors
    for i in range(N - 1):
        for j in range(i + 1, N):
            dist = 0
            for d in range(D):
                x = (vectors[i][d] - vectors[j][d])
                dist += (x * x)
            sq = math.sqrt(dist)
            # Check if the distance is an integer and increment the answer if it is
            answer += (abs(sq - math.floor(sq)) < 0.001)

    # Print the answer
    print(answer)

if __name__ == '__main__':
    main()

