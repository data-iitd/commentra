
import sys
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

def main():
    # Read the total distance K and the number of checkpoints N
    K, N = input_nums()
    # Read the positions of the checkpoints
    A = input_nums()
    # Initialize a list to store the distances between consecutive checkpoints
    dist = []
    # Calculate the distances between consecutive checkpoints
    for i in range(len(A)-1):
        dist.append(A[i+1]-A[i])
    # Calculate the distance between the first and last checkpoints (wrapping around the circle)
    dist.append(K+A[0]-A[-1])
    # Find the maximum distance
    maxv = max(dist)
    # Print the sum of all distances minus the maximum distance to skip the longest segment
    print(sum(dist) - maxv)
    

if __name__ == '__main__':
    main()

