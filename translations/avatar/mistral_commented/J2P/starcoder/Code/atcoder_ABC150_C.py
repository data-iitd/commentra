
# Importing the necessary libraries
import sys
import itertools

# Function to find permutations of a given string
def permutation(list, target, ans):
 if len(target) <= 1: # Base case: if the target string length is less than or equal to 1
 list.append(ans + target) # Add the current permutation to the list
 else:
 for i in range(len(target)): # Iterate through each character in the target string
 permutation(list, target[:i] + target[i + 1:], ans + target[i]) # Recursive call to find permutations of the remaining string
 return list # Return the list of permutations

# Main function to read user input and find the sum of the permutations
def main():
 n = int(sys.stdin.readline()) # Read the number of test cases from the user

 number = "" # Declare an empty string variable to store the number string
 for i in range(1, n + 1): # Iterate through each test case and create the number string
 number += str(i)

 listA = [] # Declare an empty list to store the permutations
 permutation(listA, number, "") # Call the permutation function to find all permutations of the number string

 sum = 0 # Declare an integer variable to store the sum of the indices of the matching permutations
 for line in sys.stdin: # Iterate through each line read from the user
 for i in range(len(listA)): # Iterate through each permutation in the list
 if listA[i] == line.split()[0]: # Check if the current permutation matches the current line
 if sum == 0: # If this is the first matching permutation
 sum += i # Add the index of the matching permutation to the sum
 else: # If there is already a matching permutation in the sum
 sum -= i # Subtract the index of the previous matching permutation from the sum
 break
 break

 print(abs(sum)) # Print the absolute value of the sum

if __name__ == "__main__":
 main()

