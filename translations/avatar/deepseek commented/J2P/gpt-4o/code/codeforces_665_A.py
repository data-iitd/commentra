import sys

def main():
    # Read the first train's details
    a, tA = map(int, sys.stdin.readline().split())  # Train number a and travel time for train a
    
    # Read the second train's details
    b, tB = map(int, sys.stdin.readline().split())  # Train number b and travel time for train b
    
    # Read the current timing
    timing = sys.stdin.readline().strip()
    hrs = int(timing[:2])  # Extract hour from timing
    mins = int(timing[3:])  # Extract minute from timing
    
    # Calculate the simulated departure and arrival times for train a
    simDeparture = hrs * 60 + mins
    simArrival = simDeparture + tA
    
    # Initialize counter to keep track of conflicts
    counter = 0
    
    # Iterate through the bus schedule, checking for conflicts
    for i in range(300, 1440, b):
        busDeparture = i  # Bus departure time
        busArrival = i + tB  # Bus arrival time
        
        # Check if there's a conflict (bus and train schedules overlap)
        if busDeparture >= simArrival or simDeparture >= busArrival:
            continue
        
        # Increment counter if a conflict is found
        counter += 1
    
    # Print the number of conflicts found
    print(counter)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
