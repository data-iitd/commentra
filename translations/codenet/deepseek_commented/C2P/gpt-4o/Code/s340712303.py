# Include the standard input/output library
N = 2000  # Define a constant N for the size of the array
num1 = 0  # Declare global variable num1
math = [0] * (N + 1)  # Declare global variable math

def main():  # Main function is the entry point of the program
    global num1  # Use the global variable num1
    a = 0
    num2 = 0
    ans = 0
    sum = 0
    local_math = [0] * (N + 1)  # Declare local variable math (shadowing the global variable)
    
    local_math[0] = 1  # Initialize the first element of local_math to 1
    
    num1 = int(input())  # Read the number of elements in the first set of inputs
    for i in range(num1):  # Loop through num1 times
        a = int(input())  # Read each element
        sum += a  # Update the sum
        for j in range(sum - a, -1, -1):  # Loop to mark possible sums
            if local_math[j] == 1:
                local_math[j + a] = 1  # If the sum j is possible, mark sum j+a as possible

    num2 = int(input())  # Read the number of elements in the second set of inputs
    for i in range(num2):  # Loop through num2 times
        ans = int(input())  # Read each element
        print("yes" if local_math[ans] == 1 else "no")  # Check if the sum is possible and print the result

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
