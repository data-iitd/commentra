def pow2(a):
    ret = 1
    for _ in range(a):
        ret *= 2
    return ret

def count(hw, a, b):
    sum_count = 0
    for i in range(len(hw)):
        for j in range(len(hw[0])):
            if (a >> i) & 1 and (b >> j) & 1 and hw[i][j] == 1:
                sum_count += 1
    return sum_count

def main():
    h, w, k = map(int, input().split())
    
    # Initialize the grid with dimensions h x w, filled with 0s
    hw = [[0] * w for _ in range(h)]
    
    # Read the grid and set 1s where there is a '#'
    for i in range(h):
        row = input().strip()
        for j in range(w):
            if row[j] == '#':
                hw[i][j] = 1
    
    sum_count = 0
    
    # Iterate over all possible combinations of row and column selections
    for i in range(pow2(h)):
        for j in range(pow2(w)):
            if count(hw, i, j) == k:  # Check if the condition is met and sum the valid combinations
                sum_count += 1
    
    # Output the result
    print(sum_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
