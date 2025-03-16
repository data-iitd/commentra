def main():
    # Step 3: Declare variables to store input values
    a, b, c, d, e, k = map(int, input().split())

    # Step 5: Calculate the difference between e and a and check if it is less than or equal to k
    result = "Yay!" if e - a <= k else ":("

    # Step 6: Print the result
    print(result)

# Step 7: Call the main function to execute the program
if __name__ == "__main__":
    main()
