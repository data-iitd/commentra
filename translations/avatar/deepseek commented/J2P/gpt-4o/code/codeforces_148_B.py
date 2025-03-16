def main():
    import sys
    
    VP = int(input())  # Read the initial speed of the police car (VP)
    VD = int(input())  # Read the initial speed of the thief car (VD)
    T = int(input())   # Read the initial head start time (T)
    F = int(input())   # Read the time it takes for the police car to refuel (F)
    C = int(input())   # Read the distance to catch the thief (C)
    
    if VD <= VP:
        print(0)  # If the thief's speed is not greater than the police's speed, print 0 and exit
        return
    
    answer = 0  # Initialize the answer variable to 0
    start = T   # Initialize the start variable to the initial head start time (T)
    
    while True:
        x = start * VP / (VD - VP)  # Calculate the distance covered by the police car in one unit of time
        
        if (start + x) * VP >= C:
            break  # If the total distance covered by the police car is greater than or equal to C, break the loop
        
        start += 2 * x + F  # Update the start variable by adding the distance covered and the refueling time
        answer += 1  # Increment the answer variable by 1
    
    print(answer)  # Print the final value of answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
