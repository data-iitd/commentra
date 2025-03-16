def main():
    # Read input values for A and B from the user
    A, B = map(int, input().split())

    # Calculate the sum of A and B and store it in variable C
    C = A + B

    # Check if A, B, and C are all not divisible by 3
    if A % 3 != 0 and B % 3 != 0 and C % 3 != 0:
        # If the condition is true, output "Impossible"
        print("Impossible")
    else:
        # If the condition is false, output "Possible"
        print("Possible")

# Call the main function
main()

