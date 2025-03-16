import sys

def main():
    # Read the values for n, a, and b from the input
    n, a, b = map(int, sys.stdin.readline().split())
    
    # Read 'a' integers into list1
    list1 = list(map(int, sys.stdin.readline().split()))
    
    # Read 'b' integers into list2
    list2 = list(map(int, sys.stdin.readline().split()))
    
    # Iterate from 0 to n-1 to check the presence of each index in list1
    for i in range(n):
        # If the current index + 1 is in list1, print 1
        if i + 1 in list1:
            print(1, end=' ')
        else:
            # Otherwise, print 2
            print(2, end=' ')

if __name__ == "__main__":
    main()
