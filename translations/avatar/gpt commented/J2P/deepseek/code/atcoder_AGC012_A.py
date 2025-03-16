import sys

def main():
    # Reading the integer n which determines the size of the array
    n = int(input().strip())
    
    # Reading the array elements from the input
    array = list(map(int, input().strip().split()))
    
    # Sorting the array in ascending order
    array.sort()
    
    # Setting the head pointer to the second last element of the sorted array
    head = 3 * n - 2
    
    # Initializing a variable to accumulate the result
    res = 0
    
    # Looping n times to sum up the required elements from the sorted array
    for i in range(n):
        res += array[head]  # Adding the current element pointed by head to the result
        head -= 2  # Moving the head pointer two positions to the left for the next iteration
    
    # Printing the final result
    print(res)

if __name__ == "__main__":
    main()
