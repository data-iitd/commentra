
import sys

def main():
    n = int(input()) # Reading the number of elements
    arr = list(map(int, input().split())) # Reading the elements and converting them to a list
    
    arr.sort() # Sorting the list
    
    c = 1 # Initializing the counter variable
    
    # Iterating through the sorted list to find the smallest missing positive integer
    for i in range(n):
        if arr[i] >= c:
            c += 1
    
    print(c) # Printing the result

if __name__ == "__main__":
    main()

