def main():
    import sys
    
    # Read the number of elements (N) and a long value (x) from input
    N = int(sys.stdin.readline().strip())
    x = int(sys.stdin.readline().strip())
    
    # Initialize a list to store the prime numbers
    srime_list = []
    
    # Read N long values into the srime_list
    for _ in range(N):
        srime_list.append(int(sys.stdin.readline().strip()))
    
    # Initialize a 2D list to store costs
    cost_list = [[0] * N for _ in range(N)]
    
    # Populate the cost_list with minimum values based on the srime_list
    for i in range(N):
        # Set the first column of cost_list to the corresponding values from srime_list
        cost_list[i][0] = srime_list[i]
        # Calculate the minimum costs for each subsequent column
        for cast_num in range(1, N):
            cost_list[i][cast_num] = min(cost_list[i][cast_num - 1], srime_list[(i - cast_num + N) % N])
    
    # Initialize a list to store the final results
    result = []
    
    # Calculate the result for each index based on the costs and the value of x
    for i in range(N):
        result.append(i * x + sum(cost_array[i] for cost_array in cost_list))
    
    # Print the minimum value from the result list
    print(min(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
