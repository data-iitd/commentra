

import itertools # Importing itertools module for creating permutations

def permutation(target, ans):
 if len(target) <= 1: # Base case: if the target string length is less than or equal to 1
 return [ans + target] # Return a list containing the current permutation
 else:
 return [ans + target[i] + target[:i] + target[i+1:] for i in range(len(target))] # Return a list of permutations of the remaining string

def main():
 n = int(input()) # Read the number of test cases from the user
 number = ''.join(str(i) for i in range(1, n+1)) # Create the number string
 listA = permutation(number, '') # Call the permutation function to find all permutations of the number string
 sum = 0 # Declare an integer variable to store the sum of the indices of the matching permutations
 for line in sys.stdin: # Iterate through each line read from the user
 for i, perm in enumerate(listA): # Iterate through each permutation in the list
 if perm == line.strip(): # Check if the current permutation matches the current line
 if sum == 0: # If this is the first matching permutation
 sum += i # Add the index of the matching permutation to the sum
 else: # If there is already a matching permutation in the sum
 sum -= i # Subtract the index of the previous matching permutation from the sum
 print(abs(sum)) # Print the absolute value of the sum

