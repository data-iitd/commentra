# Import necessary libraries
import sys
import itertools

# Function to find the solution
def solve(N: int, x: List[int], y: List[int]):
    # Initialize an empty list to store distances
    distances = []

    # Generate all possible permutations of indices from 0 to N-1
    indices = [i for i in range(N)]
    permutations = itertools.permutations(indices)

    # For each permutation, calculate the total distance between adjacent points
    for permutation in permutations:
        total_distance = 0
        for i in range(N - 1):
            # Get the first and second indices of the current pair
            f, t = permutation[i:i+2]
            # Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            distance = ((x[t] - x[f]) ** 2 + (y[t] - y[f]) ** 2) ** 0.5
            # Add the distance to the total distance
            total_distance += distance
        # Append the total distance to the distances list
        distances.append(total_distance)

    # Calculate the average distance from all permutations
    result = sum(distances) / len(distances)

    # Print the result
    print(result)

# Main function to read input and call the solve function
def main():
    # Function to read tokens from standard input
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Read the number of points and their coordinates from input
    tokens = iterate_tokens()
    N = int(next(tokens))
    x = [int()] * N
    y = [int()] * N
    for i in range(N):
        x[i] = int(next(tokens))
        y[i] = int(next(tokens))

    # Call the solve function with the given input
    solve(N, x, y)

# Run the main function if the script is executed directly
if __name__ == "__main__":
    main()
