import sys
import itertools

def solve(N: int, x: "List[int]", y: "List[int]"):
    # Create a list of indices from 0 to N-1
    indices = [i for i in range(N)]
    
    # Generate all possible permutations of the indices
    permutations = itertools.permutations(indices)
    
    # Initialize a list to store the total distances for each permutation
    distances = []
    
    # Iterate through each permutation of indices
    for permutation in permutations:
        total_distance = 0
        
        # Calculate the total distance for the current permutation
        for i in range(0, N - 1):
            f, t = permutation[i:i + 2]  # Get the current and next index
            # Calculate the Euclidean distance between the two points
            distance = ((x[t] - x[f]) ** 2 + (y[t] - y[f]) ** 2) ** 0.5
            total_distance += distance  # Accumulate the total distance
        
        # Append the total distance for the current permutation to the list
        distances.append(total_distance)
    
    # Calculate the average distance across all permutations
    result = sum(distances) / len(distances)
    
    # Print the average distance
    print(result)
    return

def main():
    # Generator function to iterate over tokens from standard input
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    # Create an iterator for the input tokens
    tokens = iterate_tokens()
    
    # Read the number of points
    N = int(next(tokens))
    
    # Initialize lists to store x and y coordinates
    x = [int()] * (N)
    y = [int()] * (N)
    
    # Read the x and y coordinates for each point
    for i in range(N):
        x[i] = int(next(tokens))
        y[i] = int(next(tokens))
    
    # Call the solve function with the number of points and their coordinates
    solve(N, x, y)

# Entry point of the program
if __name__ == "__main__":
    main()
