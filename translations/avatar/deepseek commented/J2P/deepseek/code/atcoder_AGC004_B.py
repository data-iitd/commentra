import sys

def main():
    # Read the number of elements N and the cost multiplier x
    N = int(input().strip())
    x = int(input().strip())

    # Read the elements and store them in a list
    srime_list = list(map(int, input().strip().split()))

    # Initialize a list to store the costs
    cost_list = [None] * N
    for i in range(N):
        cost_list[i] = [0] * N

    # Fill cost_list with the minimum costs for each element in srime_list
    for i in range(N):
        cost_list[i][0] = srime_list[i]
        for cast_num in range(1, N):
            cost_list[i][cast_num] = min(cost_list[i][cast_num - 1], srime_list[(i - cast_num + N) % N])

    # Calculate the final results
    result = []
    for i in range(N):
        result.append(i * x + sum(cost_list[j][i] for j in range(N)))

    # Print the minimum cost found
    print(min(result))

if __name__ == "__main__":
    main()
