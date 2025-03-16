import sys
from collections import defaultdict

def count_bits_set_to_one(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k)) != 0:
            answer += 1
    return answer

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    a = [0] * 33  # Initialize an array to count occurrences of bits set to 1
    
    # Count the number of bits set to 1 for each input number and store in array a
    for i in range(1, n + 1):
        a[count_bits_set_to_one(int(data[i]))] += 1
    
    answer = 0.0  # Initialize the answer variable
    
    # Calculate the answer based on the given formula
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ
    
    # Print the final answer in the required format
    print(int(answer))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
