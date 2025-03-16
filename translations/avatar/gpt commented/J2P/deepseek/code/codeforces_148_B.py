import sys

def main():
    # Reading input values for VP, VD, T, F, and C
    VP = float(input())  # Velocity of the person
    VD = float(input())  # Velocity of the dog
    T = float(input())    # Initial time before the dog starts chasing
    F = float(input())    # Time taken for the dog to return to the person
    C = float(input())    # Distance the person needs to cover
    
    # If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
    if VD <= VP:
        print("0")  # Output 0 as the dog will never catch the person
        return
    
    answer = 0  # Initialize the number of times the dog catches up
    start = T  # Start time for the first chase
    
    # Loop to calculate how many times the dog can catch the person
    while True:
        # Calculate the distance the person covers before the dog catches up
        x = start * VP / (VD - VP)
        
        # Check if the distance covered by the person is greater than or equal to C
        if (start + x) * VP >= C:
            break  # Exit the loop if the person has covered the required distance
        
        # Update the start time for the next chase
        start += 2 * x + F  # Add the time taken for the dog to return and the time to catch up
        answer += 1  # Increment the count of catches
    
    # Output the total number of times the dog catches the person
    print(answer)

if __name__ == "__main__":
    main()
