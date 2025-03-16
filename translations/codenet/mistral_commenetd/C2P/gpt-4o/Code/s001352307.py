# Define constants W and N for the width and number of blocks respectively
W, N = 0, 0

# Define a 2D list input to store the dimensions of each block
input_blocks = [[0, 0] for _ in range(1024)]

# Define a 2D list ans to store the maximum size of a rectangle that can be formed by placing a block of given size at each position
ans = [[0, 0] for _ in range(1024)]

def main():
    global W, N, input_blocks, ans
    t = 0

    while True:
        # Initialize all elements of lists ans and input_blocks to zero
        for i in range(1024):
            ans[i][0] = 0
            ans[i][1] = 0
            input_blocks[i][0] = 0
            input_blocks[i][1] = 0

        # Read the width W and number of blocks N from the input
        W, N = map(int, input().split())

        # If width W is zero, break out of the loop and move on to the next test case
        if W == 0:
            break

        # Read the dimensions of each block and store them in the input_blocks list
        for i in range(N):
            input_blocks[i][0], input_blocks[i][1] = map(int, input().split(','))

        # For each position j from the width W down to 0, update the maximum size of a rectangle that can be formed by placing a block of given size at that position
        for i in range(N):
            for j in range(W, input_blocks[i][1] - 1, -1):
                # If the maximum size of a rectangle that can be formed by placing a block of size input_blocks[i] at position j - input_blocks[i][1] is less than the sum of the size of the current block and the maximum size of a rectangle at position j - input_blocks[i][1], update the maximum size of a rectangle at position j
                if ans[j][0] < input_blocks[i][0] + ans[j - input_blocks[i][1]][0]:
                    ans[j][0] = input_blocks[i][0] + ans[j - input_blocks[i][1]][0]
                    ans[j][1] = input_blocks[i][1] + ans[j - input_blocks[i][1]][1]

        # Find the position j such that the maximum size of a rectangle at position W - j is greater than the maximum size of a rectangle at position W - j - 1
        for j in range(W + 1):
            if ans[W - j][0] > ans[W - j - 1][0]:
                break

        # Print the result for the current test case
        print(f"Case {t + 1}:")
        print(ans[W - j][0])
        print(ans[W - j][1])

        t += 1

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
