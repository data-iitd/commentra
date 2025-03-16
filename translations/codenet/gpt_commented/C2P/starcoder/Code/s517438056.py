# <START-OF-CODE>

# Import the math module to use the sqrt() function
import math

# Function to calculate the Euclidean distance between two vectors
def euclidean_distance(vector1, vector2):
    # Check if the vectors are of the same dimension
    if len(vector1)!= len(vector2):
        print("Error: Vectors are not of the same dimension!")
        return -1
    # Calculate the squared distance between the two vectors
    squared_distance = 0
    for i in range(len(vector1)):
        squared_distance += (vector1[i] - vector2[i]) ** 2
    # Calculate the Euclidean distance
    distance = math.sqrt(squared_distance)
    # Return the Euclidean distance
    return distance

# Function to calculate the number of integer distances between all vectors
def count_integer_distances(vectors):
    # Check if the vectors are not empty
    if len(vectors) == 0:
        print("Error: Vectors are empty!")
        return -1
    # Calculate the number of integer distances between all vectors
    count = 0
    for i in range(len(vectors) - 1):
        for j in range(i + 1, len(vectors)):
            # Calculate the Euclidean distance between the two vectors
            distance = euclidean_distance(vectors[i], vectors[j])
            # Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if ceil(distance) == floor(distance):
                count += 1
    # Return the number of integer distances
    return count

# Main function
def main():
    # Read the number of vectors (N) and their dimensions (D) from user input
    N = int(input())
    D = int(input())
    # Check if the number of vectors is not zero
    if N == 0:
        print("Error: Number of vectors is zero!")
        return -1
    # Check if the dimensions of the vectors are not zero
    if D == 0:
        print("Error: Dimensions of the vectors are zero!")
        return -1
    # Create a list to hold the vectors
    vectors = []
    # Read the vectors from user input and store them in the list
    for i in range(N):
        vector = []
        for j in range(D):
            vector.append(int(input()))
        vectors.append(vector)
    # Calculate the number of integer distances between all vectors
    count = count_integer_distances(vectors)
    # Output the number of integer distances
    print(count)

# Call the main function
main()

# 