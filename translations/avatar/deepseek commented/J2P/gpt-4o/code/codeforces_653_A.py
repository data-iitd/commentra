def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of integers
    a = list(map(int, data[1:n+1]))  # Read each integer value into a list
    
    a = sorted(set(a))  # Remove duplicates and sort the list
    found = False  # Initialize a flag to check for consecutive integers
    
    for i in range(len(a) - 2):  # Iterate until the third last element
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:  # Check for three consecutive integers
            found = True  # Set the flag if three consecutive integers are found
    
    print("YES" if found else "NO")  # Print "YES" if consecutive integers are found, otherwise print "NO"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
