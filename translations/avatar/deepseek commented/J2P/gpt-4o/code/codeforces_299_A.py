import sys

def main():
    # Step 1: Read the input value n, which represents the number of elements in the array.
    n = int(input())
    
    # Step 2: Create an array 'a' of size n and read n elements from the input.
    a = list(map(int, input().split()))
    
    # Step 3: Sort the array 'a'.
    a.sort()
    
    # Step 4: Find the minimum element in the sorted array 'a'.
    min_value = a[0]
    
    # Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
    for value in a:
        if value % min_value != 0:
            print(-1)
            return
    
    # Step 6: If all elements are divisible, print the minimum element.
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
