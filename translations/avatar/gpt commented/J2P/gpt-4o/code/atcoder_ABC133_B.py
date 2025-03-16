import math

def main():
    # Read the number of vectors (N) and their dimensionality (D)
    N, D = map(int, input().split())
    
    # Initialize a list to store the vectors
    vectors = []
    
    # Read each vector's components from the input
    for _ in range(N):
        vector = list(map(int, input().split()))
        vectors.append(vector)
    
    # Initialize a counter for the number of pairs with integer distances
    answer = 0
    
    # Calculate the pairwise distances between all vectors
    for i in range(N - 1):
        for j in range(i + 1, N):
            dist = 0
            
            # Calculate the squared distance between vector i and vector j
            for d in range(D):
                x = vectors[i][d] - vectors[j][d]
                dist += x * x
            
            # Calculate the Euclidean distance
            sq = math.sqrt(dist)
            
            # Check if the distance is an integer (within a small epsilon)
            if abs(sq - math.floor(sq)) < 0.001:
                answer += 1
    
    # Output the total count of pairs with integer distances
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
