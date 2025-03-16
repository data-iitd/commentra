import sys  # Import sys to read input from standard input

def main():
    # Read the first line of input and parse the integers
    a, tA = map(int, sys.stdin.readline().strip().split())  # Number of students and time taken by student A

    # Read the second line of input and parse the integers
    b, tB = map(int, sys.stdin.readline().strip().split())  # Number of students in bus B and time taken by bus B

    # Read the third line of input and parse the string
    timing = sys.stdin.readline().strip()  # Read the string representing the bus timing
    hrs = int(timing[:2])  # Parse the hours from the string
    mins = int(timing[3:])  # Parse the minutes from the string
    simDeparture = hrs * 60 + mins  # Calculate the simulation time of bus departure
    simArrival = simDeparture + tA  # Calculate the simulation time of bus arrival

    counter = 0  # Initialize the counter to 0

    # Loop through the bus timings to find the number of buses that can accommodate students
    for i in range(300, 1440, b):  # Loop through the bus timings from 300 to 1439 in increments of busB
        busDeparture = i  # Store the bus departure time
        busArrival = i + tB  # Calculate the bus arrival time

        if busDeparture >= simArrival or simDeparture >= busArrival:  # Check if the bus departure or arrival time is after the simulation time
            continue  # If so, skip to the next iteration of the loop
        counter += 1  # Increment the counter if the bus timing is valid

    # Write the output to the console
    print(counter)  # Print the number of buses that can accommodate students

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
