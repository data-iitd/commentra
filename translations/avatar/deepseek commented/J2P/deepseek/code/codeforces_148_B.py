import sys

def main():
    # Read the input values
    VP = float(input())
    VD = float(input())
    T = float(input())
    F = float(input())
    C = float(input())
    
    # If the thief's speed is not greater than the police's speed, print 0 and exit
    if VD <= VP:
        print(0)
        return
    
    # Initialize the answer variable to 0
    answer = 0
    start = T
    
    # Loop until the police car catches the thief
    while True:
        # Calculate the distance covered by the police car in one unit of time
        x = start * VP / (VD - VP)
        
        # If the total distance covered by the police car is greater than or equal to C, break the loop
        if (start + x) * VP >= C:
            break
        
        # Update the start variable by adding the distance covered and the refueling time
        start += 2 * x + F
        # Increment the answer variable by 1
        answer += 1
    
    # Print the final value of answer
    print(answer)

# Call the main function
if __name__ == "__main__":
    main()
