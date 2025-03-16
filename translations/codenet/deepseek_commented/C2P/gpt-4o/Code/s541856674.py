# Step 1: Import necessary modules

def main():  # Step 2: Define the main function
    N = 0  # Step 3: Declare variables
    R = 0

    N, R = map(int, input().split())  # Step 4: Read input values

    if N >= 10:  # Step 5: Implement conditional logic
        print(R)  # If true, print the value of R
    else:
        print(R + 100 * (10 - N))  # Otherwise, calculate and print the adjusted value of R

if __name__ == "__main__":  # Step 6: Ensure main runs when the script is executed
    main()

# <END-OF-CODE>
