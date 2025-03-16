
# Declare the main function
def main():
 n = int(input()) # Read the size of the vector
 p = [int(x) for x in input().split()] # Read the elements of the vector p
 ans = 0 # Initialize the answer variable ans to zero

 # Check each element of the vector p starting from the first one
 for i in range(n-1): # Loop through each element except the last one
 if p[i] == i+1: # Check if the current element is equal to its index + 1
 p[i+1], p[i] = p[i], p[i+1] # Swap the current element with the next one if it is in the wrong position
 ans +=1 # Increment the answer if a swap was made

 # Check the last element of the vector p
 if p[n-1] == n: # Check if the last element is equal to its index + 1
 ans +=1 # Increment the answer if it is in the wrong position

 # Print the answer to the user
 print(ans) # Output the answer

