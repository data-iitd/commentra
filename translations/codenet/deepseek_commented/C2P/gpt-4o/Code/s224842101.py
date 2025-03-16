# Step 1: Import necessary modules

def main():  # Step 2: Define the main function
    count = [0] * 4  # Step 3: Declare and initialize the count array

    for _ in range(3):  # Step 5: Read input values and update the count array
        a, b = map(int, input().split())
        count[a - 1] += 1  # Increment the count for node a
        count[b - 1] += 1  # Increment the count for node b

    s = 1  # Initialize s to 1
    for i in range(4): 
        s *= count[i]  # Step 6: Calculate the product of the counts

    if s == 4:  # Step 7: Check if the product is 4 and print the result
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
