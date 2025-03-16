# Function to be called when running the script
def main():

    # Read input: number of stations N, number of trains M, and number of queries Q
    N, M, Q = map(int, input().split())

    # Initialize a 2D array train to represent the number of trains passing through each edge
    train = [[0 for _ in range(N)] for _ in range(N)]

    # Read M input lines, each representing a train passing through an edge
    for _ in range(M):
        # Read the starting and ending stations of the train
        l, r = map(int, input().split())
        # Increment the number of trains passing through the edge (l-1, r-1)
        train[l-1][r-1] += 1

    # Initialize a list accum to store the prefix sums of the number of trains passing through each station
    accum = [[0 for _ in range(N+1)]]

    # For each station i from 0 to N-1:
    for i in range(N):
        # Initialize a temporary list temp to store the prefix sums of the number of trains passing through each station up to i
        temp = [0]
        # Initialize a variable v to store the total number of trains passing through station i
        v = 0
        # For each station j from 0 to N-1:
        for j in range(N):
            # Add the number of trains passing through the edge (i, j) to the variable v
            v += train[i][j]
            # Append the sum of the prefix sums up to j and the current number of trains passing through station i to the temporary list temp
            temp.append(accum[-1][j+1]+v)
        # Append the temporary list temp to the list accum
        accum.append(temp)
        # Uncomment this line to print the temporary list temp for debugging purposes
        # print(temp)

    # For each query _ in the range 0 to Q-1:
    for _ in range(Q):
        # Read the starting and ending stations p and q of the query
        p, q = map(int, input().split())
        # Calculate the number of trains passing through stations p and q and the edge (p-1, q)
        v = accum[q][q] - accum[p-1][q] - accum[q][p-1] + accum[p-1][p-1]
        # Print the result of the query
        print(v)

# Call the main function when running the script
if __name__ == '__main__':
    main()
