# Step 1: Import necessary modules (none needed in this case)

def main():  # Step 2: Define the main function
    a, b, c = map(int, input().split())  # Step 3: Read input values

    if b > a * c:  # Step 5: Implement the if-else condition
        print(c)  # If true, print c
    else:
        print(b // a)  # Otherwise, print b divided by a (using integer division)

if __name__ == "__main__":  # Step 6: Ensure the main function runs
    main()

# <END-OF-CODE>
