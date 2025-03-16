def pow2(a):
    ret = 1  # Initialize result to 1
    for _ in range(a):
        ret *= 2  # Multiply by 2, 'a' times
    return ret  # Return the result

def count(hw, a, b):
    sum_count = 0  # Initialize sum to count the valid positions
    # Iterate through each row of the hw matrix
    for i in range(len(hw)):
        # Iterate through each column of the hw matrix
        for j in range(len(hw[0])):
            # Check if the i-th bit of 'a' and the j-th bit of 'b' are set, and if hw[i][j] is 1
            if (a >> i & 1) and (b >> j & 1) and (hw[i][j] == 1):
                sum_count += 1
    return sum_count  # Return the total count of valid positions

def main():
    # Read the dimensions of the matrix and the target count 'k'
    h, w, k = map(int, input().split())
    hw = [[0] * w for _ in range(h)]  # Initialize a 2D list with dimensions h x w filled with 0

    # Read the matrix input
    for i in range(h):
        row = input().strip()  # Read each row as a string
        for j in range(w):
            # If the character is '#', mark it as 1 in the hw matrix
            if row[j] == '#':
                hw[i][j] = 1

    sum_count = 0  # Initialize sum to count the valid configurations
    # Iterate through all possible combinations of rows (2^h)
    for i in range(pow2(h)):
        # Iterate through all possible combinations of columns (2^w)
        for j in range(pow2(w)):
            # If the count of '1's matches the target 'k', increment the sum
            if count(hw, i, j) == k:
                sum_count += 1

    print(sum_count)  # Output the total count of valid configurations

if __name__ == "__main__":
    main()

# <END-OF-CODE>
