import sys

def main():
    # Reading input from the console
    N = int(input().strip())
    x = int(input().strip())

    srime_list = list(map(int, input().strip().split()))

    cost_list = [None] * N
    for i in range(N):
        cost_list[i] = [0] * N

    # Filling the cost arrays with the minimum cost for each index and each cast number
    for i in range(N):
        cost_list[i][0] = srime_list[i]  # Setting the first element of the cost array to the original element
        for cast_num in range(1, N):
            cost_list[i][cast_num] = min(cost_list[i][cast_num - 1], srime_list[(i - cast_num + N) % N])

    result = []

    # Calculating the result for each index and adding it to the ArrayList
    for i in range(N):
        temp = i * x  # Multiplying the index with the multiplier
        for cost in cost_list[i]:  # Iterating through the cost array and adding the costs
            temp += cost
        result.append(temp)

    # Printing the minimum result
    print(min(result))

if __name__ == "__main__":
    main()
