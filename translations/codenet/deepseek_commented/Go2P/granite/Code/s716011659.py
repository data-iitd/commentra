
import sys

def main():
    n = int(input()) # Reading the size of the array
    arrA = list(map(int, input().split())) # Reading the elements of the array

    cumSumA = [0] * (n + 1)
    cumSumA[0] = 0 # Initialize the cumulative sum array
    for i, a in enumerate(arrA):
        cumSumA[i + 1] = cumSumA[i] + a # Calculate cumulative sums

    ans = float('inf') # Initialize the answer with a large number
    for i in range(1, n):
        if abs(cumSumA[n] - cumSumA[i] * 2) < ans:
            ans = abs(cumSumA[n] - cumSumA[i] * 2) # Update the answer if a smaller difference is found

    print(int(ans)) # Output the minimum difference

if __name__ == "__main__":
    main()

