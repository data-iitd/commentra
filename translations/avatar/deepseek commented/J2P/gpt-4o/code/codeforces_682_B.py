import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Reading the number of elements
    lst = list(map(int, data[1:n+1]))  # Creating a list to store the elements
    
    lst.sort()  # Sorting the list
    
    c = 1  # Initializing the counter variable
    
    # Iterating through the sorted list to find the smallest missing positive integer
    for num in lst:
        if num >= c:
            c += 1
    
    print(c)  # Printing the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
