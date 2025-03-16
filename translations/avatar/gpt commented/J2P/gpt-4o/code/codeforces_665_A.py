import sys

def main():
    # Read the first line of input and split it to get values for 'a' and 'tA'
    a, tA = map(int, sys.stdin.readline().split())
    
    # Read the second line of input and split it to get values for 'b' and 'tB'
    b, tB = map(int, sys.stdin.readline().split())
    
    # Read the third line of input which contains the time in "HH:MM" format
    timing = sys.stdin.readline().strip()
    
    # Parse the hours and minutes from the input time
    hrs = int(timing[:2])  # Extract hours
    mins = int(timing[3:])  # Extract minutes
    
    # Convert the input time to total minutes since midnight
    simDeparture = hrs * 60 + mins
    
    # Calculate the simulated arrival time by adding 'tA' to the departure time
    simArrival = simDeparture + tA
    
    # Initialize a counter to keep track of valid bus schedules
    counter = 0
    
    # Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
    for i in range(300, 1440, b):
        busDeparture = i  # Current bus departure time
        busArrival = i + tB  # Calculate bus arrival time
        
        # Check if the bus schedule overlaps with the simulated arrival time
        if busDeparture >= simArrival or simDeparture >= busArrival:
            continue  # If there's no overlap, skip to the next bus
        
        # If there is an overlap, increment the counter
        counter += 1
    
    # Output the total count of valid bus schedules
    print(counter)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
