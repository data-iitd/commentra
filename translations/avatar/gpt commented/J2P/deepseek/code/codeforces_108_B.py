import sys

def main():
    # Reading the number of elements in the array
    n = int(input())
    
    # Initializing an array of size n
    a = list(map(int, input().split()))
    
    # Sorting the array in ascending order
    a.sort()
    
    # Loop to check the condition for adjacent elements in the sorted array
    for i in range(n - 1):
        # Checking if the next element is less than double the current element
        # and ensuring they are not equal
        if a[i + 1] < a[i] * 2:
            # If the condition is met, print "YES" and exit the program
            print("YES")
            sys.exit()
    
    # If no such pair is found, print "NO"
    print("NO")

if __name__ == "__main__":
    main()
