# Import the necessary module for input
import sys

def main():
    # Read the number of elements (n) and the maximum value (m)
    n, m = map(int, sys.stdin.readline().split())
    
    # Initialize a list to store the input values
    arr = [0] * n
    
    # Initialize a frequency list to count occurrences of each number from 1 to 10
    gen = [0] * 11  # gen[0] will remain unused
    
    # Read n integers from input and populate the arr and gen lists
    for i in range(n):
        arr[i] = int(sys.stdin.readline().strip())  # Store the input value in arr
        gen[arr[i]] += 1  # Increment the count of the corresponding number in gen
    
    # Initialize a variable to hold the final answer
    ans = 0
    
    # Calculate the number of valid pairs (i, k) where i != k
    for i in range(1, m + 1):
        for k in range(1, m + 1):
            if i != k:
                # Add the product of the counts of i and k to the answer
                ans += gen[i] * gen[k]
    
    # Since each pair (i, k) is counted twice, divide the result by 2
    print(ans // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
