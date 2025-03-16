def main():
    n = int(input())  # Read the value of n from the standard input
    a = list(map(float, input().split()))  # Read n floating-point numbers and create a list a

    while len(a) > 1:  # Continue until only one element remains in the list a
        a.sort()  # Sort the list a in ascending order
        na = []  # Create a new list na to store the updated elements
        for j in range(2, len(a)):  # Iterate over the list a starting from the third element
            na.append(a[j])  # Append the elements from a to na, excluding the first two
        na.append((a[0] + a[1]) / 2)  # Append the average of the first two elements to na
        a = na  # Update the list a with the new list na

    print(a[0])  # Print the single remaining element in the list a

if __name__ == "__main__":
    main()

# <END-OF-CODE>
