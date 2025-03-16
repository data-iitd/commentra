import sys

def main():
    # Read the number of elements (N) and a long value (x) from input
    N = int(input().strip())
    x = int(input().strip())
    
    # Initialize a list to store the prime numbers
    srime_list = list(map(int, input().strip().split()))
    
    # Initialize a 2D list to store costs
    cost_list = []
    
    # Create a 2D array for costs, where each row corresponds to an element in srime_list
    for i in range(N):
        cost_list.append([0] * N)
    
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
        result.append(i * x + sum(cost_list[j][i] for j in range(N)))
    
    # Print the minimum value from the result list
    print(min(result))

if __name__ == "__main__":
    main()
