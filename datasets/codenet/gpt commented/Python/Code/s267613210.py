import sys

# Define input functions for reading data
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

def main():
    # Read the values of K (total distance) and N (number of points)
    K, N = input_nums()
    
    # Read the positions of the points into a list A
    A = input_nums()
    
    # Initialize a list to store the distances between consecutive points
    dist = []
    
    # Calculate the distances between each consecutive pair of points
    for i in range(len(A)-1):
        dist.append(A[i+1] - A[i])
    
    # Calculate the distance from the last point back to the first point
    dist.append(K + A[0] - A[-1])
    
    # Find the maximum distance between consecutive points
    maxv = max(dist)
    
    # Print the total distance minus the maximum distance
    # This effectively gives the minimum distance to cover all points
    print(sum(dist) - maxv)

# Entry point of the program
if __name__ == '__main__':
    main()
