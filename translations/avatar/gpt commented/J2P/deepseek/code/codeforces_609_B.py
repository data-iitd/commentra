import sys

def main():
    # Read the number of elements (n) and the maximum value (m)
    n, m = map(int, sys.stdin.readline().split())
    
    # Initialize an array to store the input values
    arr = list(map(int, sys.stdin.readline().split()))
    
    # Initialize a frequency array to count occurrences of each number from 1 to 10
    gen = [0] * 11
    
    # Populate the gen array with the counts of each number in arr
    for num in arr:
        gen[num] += 1
    
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
