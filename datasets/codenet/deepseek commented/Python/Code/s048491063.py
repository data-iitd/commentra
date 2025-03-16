def main():
    # Step 1: Reading Input Values
    # Read the values of N (number of stations), M (number of train routes), and Q (number of queries)
    N, M, Q = map(int, input().split())
    
    # Step 2: Initializing the Train Matrix
    # Initialize a matrix `train` with dimensions N x N filled with zeros
    train = [[0 for _ in range(N)] for _ in range(N)]
    
    # Step 3: Reading Train Routes
    # Read M pairs of values l and r, indicating a train route from station l to station r
    for _ in range(M):
        l, r = map(int, input().split())
        train[l-1][r-1] += 1
    
    # Step 4: Accumulating Train Counts
    # Create an accumulated sum matrix `accum` to quickly calculate train counts between any two stations
    accum = [[0 for _ in range(N+1)]]
    for i in range(N):
        temp = [0]
        v = 0
        for j in range(N):
            v += train[i][j]
            temp.append(accum[-1][j+1]+v)
        accum.append(temp)
        # print(temp)
    
    # Step 5: Processing Queries
    # Read Q queries, each specifying a range p to q, and print the number of trains between stations p and q
    for _ in range(Q):
        p, q = map(int, input().split())
        v = accum[q][q] - accum[p-1][q] - accum[q][p-1] + accum[p-1][p-1]
        print(v)

if __name__ == '__main__':
    main()
