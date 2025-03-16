from itertools import permutations  # Importing permutations function for generating permutations
import sys  # Importing sys for reading input

def main():
    n = int(input())  # Read the number of test cases from the user
    number = ''.join(str(i) for i in range(1, n + 1))  # Create the number string

    listA = [''.join(p) for p in permutations(number)]  # Generate all permutations of the number string

    sum_indices = 0  # Initialize the sum of indices of matching permutations
    line = [input().strip() for _ in range(n)]  # Read n lines of input

    for j in range(n):  # Iterate through each line read from the user
        for i in range(len(listA)):  # Iterate through each permutation in the list
            if listA[i] == line[j]:  # Check if the current permutation matches the current line
                if sum_indices == 0:  # If this is the first matching permutation
                    sum_indices += i  # Add the index of the matching permutation to the sum
                else:  # If there is already a matching permutation in the sum
                    sum_indices -= i  # Subtract the index of the previous matching permutation from the sum

    print(abs(sum_indices))  # Print the absolute value of the sum

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
