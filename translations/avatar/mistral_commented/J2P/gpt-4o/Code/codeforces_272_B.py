import sys
from collections import defaultdict

# A function to count the number of set bits in the binary representation of a number
def rec(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k)) != 0:  # If the k-th bit is set
            answer += 1  # Increment the answer
    return answer

def main():
    # Read the number of test cases
    n = int(sys.stdin.readline().strip())
    
    # Initialize a dictionary to store the frequency of each number
    a = [0] * 33

    # Read each test case and update the frequency of the number in the array 'a'
    for _ in range(n):
        num = int(sys.stdin.readline().strip())  # Read a number
        index = rec(num)  # Get the index of the number in the array 'a'
        a[index] += 1  # Increment the frequency of the number in the array 'a'

    # Calculate the answer
    answer = 0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)  # Calculate the sum of squares of numbers up to the current number
        answer += summ  # Add the sum to the answer

    print(int(answer))  # Print the answer as an integer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
