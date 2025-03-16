# Importing necessary libraries
from typing import List

def main():
    N = int(input())  # Read the number of elements N
    x = int(input())  # Read the cost multiplier x

    srime_list = [int(input()) for _ in range(N)]  # Read N integers into srime_list

    cost_list = [[0] * N for _ in range(N)]  # Create a list of lists to store costs

    # Fill cost_list with the minimum costs for each element in srime_list
    for i in range(N):
        cost_list[i][0] = srime_list[i]  # Initialize the first element of the cost array
        for cast_num in range(1, N):
            cost_list[i][cast_num] = min(cost_list[i][cast_num - 1], srime_list[(i - cast_num + N) % N])

    result = []  # Create a list to store the final results
    for i in range(N):
        result.append(i * x + sum(cost_array[i] for cost_array in cost_list))

    # Print the minimum cost found
    print(min(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
