import sys

# Function to calculate the minimum cost of casting a spell
def calculateCost(srimeList, x, i):
    # Initializing the cost array
    cost = [0] * len(srimeList)
    cost[0] = srimeList[i]

    # Calculating the cost array
    for j in range(1, len(srimeList)):
        cost[j] = min(cost[j - 1], srimeList[(i - j + len(srimeList)) % len(srimeList)])

    # Calculating the result
    result = i * x
    for j in range(len(srimeList)):
        result += cost[j]

    return result

# Main function
def main():
    # Reading input from the console
    N = int(input())
    x = int(input())
    srimeList = [int(input()) for i in range(N)]

    # Calculating the result for each index
    result = [calculateCost(srimeList, x, i) for i in range(N)]

    # Printing the minimum result
    print(min(result))

# Calling the main function
if __name__ == "__main__":
    main()

