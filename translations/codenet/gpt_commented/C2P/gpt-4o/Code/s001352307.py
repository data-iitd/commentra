# Global variables to hold the weight limit (W) and number of items (N)
W, N = 0, 0
# List to store the input items with their weights and values
input_items = []

def main():
    global W, N, input_items
    t = 0

    # Infinite loop to process multiple test cases
    while True:
        # Initialize the input_items list for each test case
        input_items = []
        
        # Read the weight limit (W) and number of items (N)
        W, N = map(int, input().split())
        # Break the loop if the weight limit is zero (end of input)
        if W == 0:
            break

        # Read the value and weight of each item
        for _ in range(N):
            value, weight = map(int, input().split(','))
            input_items.append((value, weight))

        # Array to store the maximum value and corresponding weight for each capacity
        ans = [[0, 0] for _ in range(1024)]

        # Dynamic programming to calculate the maximum value for each capacity
        for value, weight in input_items:
            # Traverse the capacities in reverse to avoid overwriting results
            for j in range(1023, weight - 1, -1):
                # Check if including the current item increases the maximum value
                if ans[j][0] < value + ans[j - weight][0]:
                    # Update the maximum value and corresponding weight
                    ans[j][0] = value + ans[j - weight][0]
                    ans[j][1] = weight + ans[j - weight][1]

        # Find the maximum value and corresponding weight for the exact weight limit
        j = 0
        while ans[W][0] == ans[W - j - 1][0]:
            j += 1

        # Print the results for the current test case
        print(f"Case {t + 1}:")
        print(ans[W - j][0])
        print(ans[W - j][1])

        t += 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
