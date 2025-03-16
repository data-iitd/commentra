N = 2000

# Declare global variables
num1 = 0
math = [0] * (N + 1)

def main():
    global num1, math
    num1 = int(input())
    a = 0
    sum_possible = 0
    math[0] = 1
    
    # Loop to read each element and update the possible sums
    for i in range(num1):
        a = int(input())
        sum_possible += a
        
        # Update the math array to reflect the new possible sums
        for j in range(sum_possible, -1, -1):
            if math[j] == 1:
                math[j + a] = 1
    
    # Read the number of queries for possible sums
    num2 = int(input())
    
    # Loop to check if each queried sum is possible
    for i in range(num2):
        ans = int(input())
        # Check if the queried sum is possible and print the result
        print("yes" if math[ans] == 1 else "no")

# Call the main function
main()
