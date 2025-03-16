
import sys

def main():
    N = int(input()) # Step 1: Read the input value N
    A = list(map(int, input().split())) # Step 2: Read the elements of the array A
    count = 0 # Step 3: Initialize a counter 'count' to zero
    i = 0
    while i < N - 1:
        if A[i] == A[i + 1]:
            i += 1
        elif A[i] < A[i + 1]:
            while i < N - 1 and A[i] <= A[i + 1]:
                i += 1
            count += 1 # Step 7: Increment the counter 'count' after each segment
        else:
            while i < N - 1 and A[i] >= A[i + 1]:
                i += 1
            count += 1 # Step 8: Increment the counter 'count' after each segment
    print(count) # Step 9: Print the value of the counter 'count'

if __name__ == "__main__":
    main()
