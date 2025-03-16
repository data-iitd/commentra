
import sys

def main():
    n = int(input()) # Read the number of elements
    a = [0] * 33 # Initialize an array to count occurrences of bits set to 1
    
    # Count the number of bits set to 1 for each input number and store in array a
    for i in range(n):
        a[rec(int(input()))] += 1
    
    answer = 0 # Initialize the answer variable
    
    # Calculate the answer based on the given formula
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ
    
    # Print the final answer in the required format
    print(int(answer))

# Helper method to count the number of bits set to 1 in a given number
def rec(x):
    answer = 0 # Initialize the count of bits set to 1
    for k in range(31, -1, -1): # Iterate through each bit position
        if (x & (1 << k))!= 0: # Check if the k-th bit is set to 1
            answer += 1 # Increment the count if the bit is set
    return answer # Return the count of bits set to 1

if __name__ == "__main__":
    main() # Call the main function

