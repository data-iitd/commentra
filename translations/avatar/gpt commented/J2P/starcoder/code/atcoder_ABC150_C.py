import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.List; 
import java.util.Scanner; 

def permutation(list, target, ans):
    # Base case: if the target string is of length 1 or less, add the current answer to the list
    if len(target) <= 1:
        list.append(ans + target)
    else:
        # Recursive case: iterate through each character in the target string
        for i in range(len(target)):
            # Recursively call permutation with the remaining characters and the current character added to the answer
            permutation(list, target[:i] + target[i+1:], ans + target[i])
    # Return the list of permutations
    return list

def main():
    # Create a scanner object to read input from the user
    scanner = Scanner(System.in)
    
    # Read the number of elements to be processed
    n = int(scanner.next())
    
    # Initialize a 2D array to store input strings
    line = [["", ""], ["", ""]]
    
    # Fill the 2D array with empty strings
    for i in range(2):
        for j in range(1):
            line[i][j] = ""
            # Read n strings from the user and concatenate them into the first column of the array
            for j in range(n):
                line[i][0] += scanner.next()
    
    # Create a string containing numbers from 1 to n
    number = ""
    for i in range(1, n+1):
        number += str(i)
    
    # List to hold all permutations of the number string
    listA = []
    # Generate all permutations of the number string
    permutation(listA, number, "")
    
    # Variable to hold the sum of indices based on matching permutations
    sum = 0
    
    # Iterate through each row of the input strings
    for j in range(len(line)):
        # Check each permutation against the input strings
        for i in range(len(listA)):
            # If a permutation matches the input string, adjust the sum based on the index
            if listA[i] == line[j][0]:
                if sum == 0:
                    sum += i # Add index if sum is initially zero
                else:
                    sum -= i # Subtract index if sum is not zero
    # Output the absolute value of the sum
    print(abs(sum))

if __name__ == "__main__":
    main()

