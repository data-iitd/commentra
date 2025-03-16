import sys

def main():
    # Reading the number of elements N from standard input
    N = int(input().strip())
    
    # Reading N integers from standard input and storing them in a list A
    A = list(map(int, input().strip().split()))
    
    # Initializing a counter to keep track of the number of segments
    count = 0
    
    # Loop through the list to identify segments of increasing or decreasing values
    i = 0
    while i < N:
        # If we are at the last element, increment the count
        if i == N - 1:
            count += 1
            break
        # If the current element is equal to the next element, move to the next element
        elif A[i] == A[i + 1]:
            i += 1
        # If the current element is less than the next element, find the end of the increasing segment
        elif A[i] < A[i + 1]:
            while i < N - 1 and A[i] <= A[i + 1]:
                i += 1
            count += 1
        # If the current element is greater than the next element, find the end of the decreasing segment
        else:
            while i < N - 1 and A[i] >= A[i + 1]:
                i += 1
            count += 1
    
    # Output the total number of segments found
    print(count)

if __name__ == "__main__":
    main()
