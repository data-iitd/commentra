def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of integers
    a = list(map(int, data[1:n+1]))  # Read n integers from input
    
    # Remove duplicates, sort the list
    a = sorted(set(a))
    
    found = False  # Initialize a flag to check for consecutive triplets
    
    # Check for three consecutive integers in the sorted list
    for i in range(len(a) - 2):  # Ensure there are at least three elements to check
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:  # Check for consecutive triplet
            found = True  # Set found to true if consecutive triplet is found
            break  # No need to check further if we found a triplet
    
    # Output "YES" if a triplet was found, otherwise output "NO"
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
