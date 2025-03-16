import itertools

# Function to find indices of a character in a string
def find(s, ch):
    return [i for i, ltr in enumerate(s) if ltr == ch]

# Main block of the code
if __name__ == '__main__':
    # Read the integer input
    n = int(input())
    # Read the string input and remove spaces
    s = input().replace(" ", "")
    
    # If the string does not contain '0', print n - 1
    if '0' not in s:
        print(n - 1)
    else:
        # Find all indices of '0' in the string
        indices = find(s, '0')
        
        # If there is only one '0', print n
        if len(indices) == 1:
            print(n)
        else:
            # Initialize maximum to 0
            maximum = 0
            # Generate all combinations of two indices of '0'
            combs = itertools.combinations(indices, 2)
            
            # Iterate over each combination and calculate the maximum distance
            for x in combs:
                maximum = max(maximum, 2 + 2 * (abs(indices.index(x[0]) - indices.index(x[1])) - 1) - (abs(x[0] - x[1]) - 1))
            
            # Print the count of '1's plus the maximum distance
            print(s.count('1') + maximum)
