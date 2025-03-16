

import sys

def main():
    # Read the first train's details
    a, tA = map(int, input().split())

    # Read the second train's details
    b, tB = map(int, input().split())

    # Read the current timing
    timing = input()
    hrs, mins = map(int, timing.split(':'))

    # Calculate the simulated departure and arrival times for train a
    simDeparture = hrs * 60 + mins
    simArrival = simDeparture + tA

    # Initialize counter to keep track of conflicts
    counter = 0

    # Iterate through the bus schedule, checking for conflicts
    for i in range(300, 1440, b):
        busDeparture = i
        busArrival = i + tB

        # Check if there's a conflict (bus and train schedules overlap)
        if busDeparture >= simArrival or simDeparture >= busArrival:
            continue

        # Increment counter if a conflict is found
        counter += 1

    # Print the number of conflicts found
    print(counter)

if __name__ == "__main__":
    main()

