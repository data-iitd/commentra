
# Python code to solve the problem

# Global variables to hold the weight limit (W) and number of items (N)
W, N = 0, 0
# Array to store the input items with their weights and values
input = []

def main():
    global W, N, input
    t = 0 # Counter for the number of test cases

    # Infinite loop to process multiple test cases
    while True:
        # Initialize the input array to empty for each test case
        input = []

        # Read the weight limit (W) and number of items (N)
        W, N = map(int, input().split())
        # Break the loop if the weight limit is zero (end of input)
        if W == 0:
            break

        # Read the value and weight of each item
        for i in range(N):
            input.append(list(map(int, input().split(','))))

        # Dynamic programming to calculate the maximum value for each capacity
        ans = [[0, 0] for _ in range(W + 1)]
        for i in range(N):
            for j in range(W, input[i][1] - 1, -1):
                if ans[j][0] < input[i][0] + ans[j - input[i][1]][0]:
                    ans[j][0] = input[i][0] + ans[j - input[i][1]][0]
                    ans[j][1] = input[i][1] + ans[j - input[i][1]][1]

        # Find the maximum value and corresponding weight for the exact weight limit
        j = 0
        while ans[W][0] == ans[W - j - 1][0]:
            j += 1

        # Print the results for the current test case
        print(f"Case {t + 1}:\n{ans[W - j][0]}\n{ans[W - j][1]}")

        t += 1 # Increment the test case counter

if __name__ == "__main__":
    main()

