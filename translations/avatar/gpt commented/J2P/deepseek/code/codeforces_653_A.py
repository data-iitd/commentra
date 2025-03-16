import sys

def main():
    # Read the number of integers from input
    n = int(input())
    # Initialize a list to store the integers
    a = []
    
    # Read n integers from input and add them to the list
    for _ in range(n):
        value = int(input())
        a.append(value)
    
    # Remove duplicates, sort the list, and collect it back into a list
    a = sorted(set(a))
    
    # Initialize a flag to check for consecutive triplets
    found = False
    
    # Check for three consecutive integers in the sorted list
    for i in range(len(a)):
        # Ensure there are at least three elements to check
        if i + 1 < len(a) and i + 2 < len(a):
            # Check if the current, next, and the one after next integers are consecutive
            if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
                found = True  # Set found to True if consecutive triplet is found
                break  # No need to continue once a triplet is found
    
    # Output "YES" if a triplet was found, otherwise output "NO"
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()
