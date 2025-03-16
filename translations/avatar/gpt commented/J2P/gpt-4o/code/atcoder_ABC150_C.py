from itertools import permutations

def main():
    # Read the number of elements to be processed
    n = int(input())
    
    # Initialize a list to store input strings
    line = [""] * 2
    
    # Fill the list with empty strings and read n strings from the user
    for j in range(2):
        for _ in range(n):
            line[j] += input()
    
    # Create a string containing numbers from 1 to n
    number = ''.join(str(i) for i in range(1, n + 1))
    
    # Generate all permutations of the number string
    listA = [''.join(p) for p in permutations(number)]
    
    # Variable to hold the sum of indices based on matching permutations
    sum_indices = 0
    
    # Iterate through each row of the input strings
    for j in range(len(line)):
        # Check each permutation against the input strings
        for i in range(len(listA)):
            # If a permutation matches the input string, adjust the sum based on the index
            if listA[i] == line[j]:
                if sum_indices == 0:
                    sum_indices += i  # Add index if sum is initially zero
                else:
                    sum_indices -= i  # Subtract index if sum is not zero
    
    # Output the absolute value of the sum
    print(abs(sum_indices))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
