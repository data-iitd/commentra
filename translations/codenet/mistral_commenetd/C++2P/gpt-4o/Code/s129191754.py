def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements in the vector
    a = list(map(int, data[1:n+1]))  # Read the elements of the vector

    a.sort()  # Sort the vector in ascending order

    # Check if there are any consecutive elements in the sorted vector
    for i in range(n - 1):
        # If there are consecutive elements, print "NO" and exit the program
        if a[i] == a[i + 1]:
            print("NO")
            return

    # If no consecutive elements were found, print "YES"
    print("YES")

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
