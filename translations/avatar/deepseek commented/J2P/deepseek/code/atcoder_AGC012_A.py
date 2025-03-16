import sys

def main():
    # Step 1: Read the input value `n` which represents the number of elements to process.
    n = int(input().strip())
    
    # Step 2: Read the array of size `3 * n` from the standard input.
    array = list(map(int, input().strip().split()))
    
    # Step 3: Sort the array in ascending order.
    array.sort()
    
    # Step 4: Initialize a variable `head` to point to the second last element of the array.
    head = len(array) - 2
    
    # Step 5: Initialize a variable `res` to store the result.
    res = 0
    
    # Step 6: Iterate `n` times, in each iteration:
    # - Add the value at the `head` position to `res`.
    # - Decrement `head` by 2.
    for _ in range(n):
        res += array[head]
        head -= 2
    
    # Step 7: Print the result `res`.
    print(res)

if __name__ == "__main__":
    main()
