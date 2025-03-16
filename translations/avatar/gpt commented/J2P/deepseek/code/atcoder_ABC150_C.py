import itertools

# Function to generate all permutations of a given target string
def permutation(target):
    if len(target) <= 1:
        return [target]
    else:
        perms = []
        for i in range(len(target)):
            for perm in permutation(target[:i] + target[i+1:]):
                perms.append(target[i] + perm)
        return perms

# Main function
def main():
    # Read the number of elements to be processed
    n = int(input())
    
    # Initialize a 2D list to store input strings
    line = [[''] * 1 for _ in range(2)]
    
    # Fill the 2D list with empty strings
    for i in range(2):
        line[i][0] = input().strip()
    
    # Create a string containing numbers from 1 to n
    number = ''.join(str(i) for i in range(1, n + 1))
    
    # Generate all permutations of the number string
    listA = permutation(number)
    
    # Variable to hold the sum of indices based on matching permutations
    sum_ = 0
    
    # Iterate through each row of the input strings
    for j in range(2):
        # Check each permutation against the input strings
        for i, perm in enumerate(listA):
            # If a permutation matches the input string, adjust the sum based on the index
            if perm == line[j][0]:
                if sum_ == 0:
                    sum_ += i  # Add index if sum is initially zero
                else:
                    sum_ -= i  # Subtract index if sum is not zero
    
    # Output the absolute value of the sum
    print(abs(sum_))

# Call the main function
if __name__ == "__main__":
    main()
