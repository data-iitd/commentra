from collections import Counter

def main():
    # Read the number of integers to process
    n = int(input())
    
    # Initialize a Counter to count occurrences of integers in the range [-10, 10]
    cnt = Counter()
    
    # Loop to read n integers and count their occurrences
    for _ in range(n):
        # Increment the count for the input integer adjusted by +10 to handle negative values
        cnt[int(input()) + 10] += 1
    
    # Variable to store the final result
    res = 0
    
    # Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
    for i in range(10):
        # Multiply the counts of i and (20 - i) and add to the result
        res += cnt[i] * cnt[20 - i]
    
    # Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
    res += cnt[10] * (cnt[10] - 1) // 2
    
    # Output the final result
    print(res)

if __name__ == "__main__":
    main()
