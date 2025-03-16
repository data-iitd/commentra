# Include the standard input/output library

def main():  # Declare the main function
    n, k = map(int, input().split())  # Read two integers from the standard input and store them in variables n and k
    p = []  # Declare an empty list p

    for _ in range(n):  # Iterate through the range of n
        p.append(int(input()))  # Read an integer from the standard input and store it in the list p

    for i in range(n):  # Iterate through the list p from index 0 to n-1
        l = i  # Initialize variable l to i
        for j in range(i + 1, n):  # Iterate through the list p from index i+1 to n-1
            if p[j] < p[l]:  # If the element at index j is smaller than the element at index l
                l = j  # Update the index of the smallest element
        if l != i:  # If the index of the smallest element is not equal to i
            p[i], p[l] = p[l], p[i]  # Swap the elements at indices i and l

    o = sum(p[i] for i in range(k))  # Sum the first k elements of the list p

    print(o)  # Print the value of the variable o to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
