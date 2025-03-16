import itertools

def find(s, ch):
    # This function returns a list of indices where the character 'ch' appears in the string 's'.
    return [i for i, ltr in enumerate(s) if ltr == ch]

if __name__ == '__main__':
    # Read an integer input 'n' which represents the length of the string.
    n = int(input())
    
    # Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
    s = input().replace("", "")
    
    # Check if the string 's' contains the character '0'.
    if '0' not in s:
        # If '0' is not present, the output is n - 1.
        print(n - 1)
    else:
        # Find all indices of '0' in the string 's'.
        indices = find(s, '0')
        
        # If there is only one '0', output the length of the string 'n'.
        if len(indices) == 1:
            print(n)
        else:
            # Initialize a variable to keep track of the maximum value found.
            maximum = 0
            
            # Generate all combinations of indices of '0' taken 2 at a time.
            combs = itertools.combinations(indices, 2)
            
            # Iterate through each combination of indices.
            for x in combs:
                # Calculate the maximum value based on the distance between the two indices.
                maximum = max(maximum, 2 + 2 * (abs(indices.index(x[0]) - indices.index(x[1])) - 1) - (abs(x[0] - x[1]) - 1))
            
            # Output the count of '1's in the string plus the maximum value calculated.
            print(s.count('1') + maximum)
