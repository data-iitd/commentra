import sys

def main():
    # Read the number of elements (N) and a long value (x) from input
    N = int(input())
    x = int(input())
    
    # Initialize a list to store the prime numbers
    srimeList = []
    
    # Read N long values into the srimeList
    for i in range(N):
        srimeList.append(int(input()))
    
    # Initialize a 2D list to store costs
    costList = []
    
    # Create a 2D array for costs, where each row corresponds to an element in srimeList
    for i in range(N):
        costList.append([0] * N)
    
    # Populate the costList with minimum values based on the srimeList
    for i in range(N):
        # Set the first column of costList to the corresponding values from srimeList
        costList[i][0] = srimeList[i]
        # Calculate the minimum costs for each subsequent column
        for castNum in range(1, N):
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])
    
    # Initialize a list to store the final results
    result = []
    
    # Calculate the result for each index based on the costs and the value of x
    for i in range(N):
        result.append(i * x + sum(costList[i]))
    
    # Print the minimum value from the result list
    print(min(result))

if __name__ == "__main__":
    main()

