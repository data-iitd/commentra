def main():
    # Read the number of elements to be processed
    n = int(input())
    
    # Initialize variables to hold the sums of three different sets of integers
    a = 0
    b = 0
    c = 0
    
    # Read n integers and calculate their sum (a)
    a = sum(map(int, input().split()))
    
    # Read n-1 integers and calculate their sum (b)
    b = sum(map(int, input().split()))
    
    # Read n-2 integers and calculate their sum (c)
    c = sum(map(int, input().split()))
    
    # Calculate the difference between the sums: x = sum of first set - sum of second set
    x = a - b
    
    # Calculate the difference between the sums: y = sum of second set - sum of third set
    y = b - c
    
    # Print the results of the differences
    print(x)
    print(y)

if __name__ == "__main__":
    main()
