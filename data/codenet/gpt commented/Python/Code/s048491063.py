def main():
    # Read the number of stations (N), number of train routes (M), and number of queries (Q)
    N, M, Q = map(int, input().split())
    
    # Initialize a 2D list to store the number of trains between stations
    train = [[0 for _ in range(N)] for _ in range(N)]
    
    # Read the train routes and populate the train matrix
    for _ in range(M):
        l, r = map(int, input().split())
        # Increment the count of trains from station l to station r
        train[l-1][r-1] += 1

    # Initialize a 2D list for cumulative sums of trains
    accum = [[0 for _ in range(N+1)]]
    
    # Build the cumulative sum matrix
    for i in range(N):
        temp = [0]  # Temporary list to hold cumulative sums for the current station
        v = 0  # Variable to accumulate the number of trains
        for j in range(N):
            v += train[i][j]  # Update the count of trains for the current row
            # Calculate the cumulative sum for the current station and append to temp
            temp.append(accum[-1][j+1] + v)
        accum.append(temp)  # Append the cumulative sums for the current station to accum

    # Process each query to find the number of trains between specified stations
    for _ in range(Q):
        p, q = map(int, input().split())
        # Calculate the number of trains from station p to station q using the cumulative sums
        v = accum[q][q] - accum[p-1][q] - accum[q][p-1] + accum[p-1][p-1]
        print(v)  # Output the result for the current query

if __name__ == '__main__':
    main()  # Execute the main function
