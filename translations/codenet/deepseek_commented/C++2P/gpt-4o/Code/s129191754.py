def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read an integer n
    a = list(map(int, data[1:n+1]))  # Read n integers into a list a
    
    a.sort()  # Sort the list a
    
    for i in range(n - 1):  # Iterate through the sorted list to check for duplicates
        if a[i] == a[i + 1]:
            print("NO")  # If duplicates are found, print "NO" and exit
            return
    
    print("YES")  # If no duplicates are found, print "YES"

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
