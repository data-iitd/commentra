#include<stdio.h>

# Function prototype for linear search
def linersearch(a, n, key):
    i = 0

    # Sentinel value: place the key at the end of the array
    a[n] = key

    # Search for the key in the array
    while a[i] != key:
        i += 1 # Increment index until the key is found

    # Return true if the key was found within the original array bounds
    return i != n

def main():
    i, n, s, q, t, count = 0, 0, [], 0, 0, 0

    # Read the number of elements in the array
    n = int(input())

    # Read n elements into the array s
    for i in range(n):
        s.append(int(input()))

    # Read the number of queries
    q = int(input())

    # Process each query to check if the element exists in the array
    for i in range(q):
        t = int(input()) # Read the query element
        # Use linear search to check if the element t is in the array s
        if linersearch(s, n, t): count += 1 # Increment count if found

    # Output the total count of found elements
    print(count)

if __name__ == "__main__":
    main()

