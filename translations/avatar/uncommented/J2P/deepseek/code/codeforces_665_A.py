import sys

def main():
    # Read input from stdin
    input_line1 = sys.stdin.readline().strip()
    a, tA = map(int, input_line1.split())
    
    input_line2 = sys.stdin.readline().strip()
    b, tB = map(int, input_line2.split())
    
    timing = sys.stdin.readline().strip()
    hrs, mins = map(int, timing.split(':'))
    simDeparture = hrs * 60 + mins
    simArrival = simDeparture + tA
    
    counter = 0
    for i in range(300, 1440, b):
        busDeparture = i
        busArrival = i + tB
        if busDeparture >= simArrival or simDeparture >= busArrival:
            continue
        counter += 1
    
    # Print output to stdout
    print(counter)

if __name__ == "__main__":
    main()
