import sys
from collections import defaultdict

def count_set_bits(x):
    return bin(x).count('1')

def main():
    # Read the number of integers to process
    n = int(sys.stdin.readline().strip())
    
    # Dictionary to count occurrences of integers based on their bit count
    a = [0] * 33
    
    # Process each integer and count how many have the same number of set bits
    for _ in range(n):
        a[count_set_bits(int(sys.stdin.readline().strip()))] += 1
    
    # Variable to accumulate the final answer
    answer = 0.0
    
    # Calculate the contribution to the answer from each bit count
    for count in a:
        if count > 1:
            summ = (1 + count - 1) / 2.0 * (count - 1)
            answer += summ
    
    # Print the final answer as a long integer
    print(int(answer))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
