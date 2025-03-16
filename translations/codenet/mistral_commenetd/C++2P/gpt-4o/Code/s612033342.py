def pow2(a):
    ret = 1  # Initialize result to 1
    for _ in range(a):
        ret *= 2  # Multiply result by 2 for each iteration of the loop
    return ret  # Return the final result

def count(hw, a, b):
    sum_count = 0  # Initialize sum to 0
    for i in range(len(hw)):  # Iterate through each row of the 2D grid
        for j in range(len(hw[0])):  # Iterate through each column of the current row
            if (a & (1 << i)) and (b & (1 << j)) and hw[i][j] == 1:
                sum_count += 1  # Increment sum if conditions are met
    return sum_count  # Return the final sum

def main():
    h, w, k = map(int, input().split())  # Read input values for height, width, and target count
    hw = [[0] * w for _ in range(h)]  # Initialize 2D grid with zeroes
    for i in range(h):  # Iterate through each row of the 2D grid
        row = input().strip()  # Read the row as a string
        for j in range(w):  # Iterate through each column of the current row
            if row[j] == '#':
                hw[i][j] = 1  # Set the corresponding cell in the grid to 1 if character is '#'
    
    sum_count = 0  # Initialize sum to 0
    for i in range(pow2(h)):  # Iterate through all possible binary combinations of height
        for j in range(pow2(w)):  # Iterate through all possible binary combinations of width
            if count(hw, i, j) == k:
                sum_count += 1  # Increment sum if the count matches the target count
    
    print(sum_count)  # Output the final sum to standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
