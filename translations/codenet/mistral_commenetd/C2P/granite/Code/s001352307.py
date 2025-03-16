

# Define a function to calculate the maximum size of a rectangle that can be formed by placing a block of given size at each position
def calculate_rectangle_size(width, blocks):
    # Initialize a 2D array ans to store the maximum size of a rectangle that can be formed by placing a block of given size at each position
    ans = [[0, 0] for _ in range(width + 1)]

    # Loop through all positions j from the width down to 0
    for j in range(width, -1, -1):
        # Loop through all blocks
        for block in blocks:
            # If the maximum size of a rectangle that can be formed by placing a block of size block at position j is less than the sum of the size of the current block and the maximum size of a rectangle at position j - block, update the maximum size of a rectangle at position j
            if ans[j][0] < block[0] + ans[j - block[1]][0]:
                ans[j][0] = block[0] + ans[j - block[1]][0]
                ans[j][1] = block[1] + ans[j - block[1]][1]

    # Find the position j such that the maximum size of a rectangle at position width - j is greater than the maximum size of a rectangle at position width - j - 1
    for j in range(width + 1):
        if ans[width - j][0] > ans[width - j - 1][0]:
            break

    # Return the maximum size of a rectangle and the size of the block that forms it
    return ans[width - j][0], ans[width - j][1]

# Define a function to read the input and call the function to calculate the maximum size of a rectangle
def read_input():
    # Initialize a variable t to keep track of the number of test cases
    t = 0

    # Loop until the width is zero
    while True:
        # Read the width and number of blocks from the input
        width, num_blocks = map(int, input().split())

        # If the width is zero, break out of the loop
        if width == 0:
            break

        # Read the dimensions of each block and store them in a list of tuples
        blocks = []
        for _ in range(num_blocks):
            block_width, block_height = map(int, input().split(','))
            blocks.append((block_width, block_height))

        # Call the function to calculate the maximum size of a rectangle and print the result for the current test case
        result = calculate_rectangle_size(width, blocks)
        print(f"Case {t + 1}:")
        print(result[0])
        print(result[1])

        # Increment the variable t to keep track of the number of test cases
        t += 1

# Call the function to read the input
read_input()

