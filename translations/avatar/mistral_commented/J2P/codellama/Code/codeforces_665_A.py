
import sys

# Read the first line of input and parse the integers
a, tA = map(int, sys.stdin.readline().split())

# Read the second line of input and parse the integers
b, tB = map(int, sys.stdin.readline().split())

# Read the third line of input and parse the string
timing = sys.stdin.readline()
hrs, mins = map(int, timing.split())
simDeparture = hrs * 60 + mins
simArrival = simDeparture + tA

counter = 0

# Loop through the bus timings to find the number of buses that can accommodate students
for i in range(300, 1440, b):
    busDeparture = i
    busArrival = i + tB

    if busDeparture >= simArrival or simDeparture >= busArrival:
        continue
    counter += 1

# Write the output to the console
print(counter)

