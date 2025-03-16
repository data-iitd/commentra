import sys

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    a, tA = map(int, data[0].split())
    b, tB = map(int, data[1].split())
    
    timing = data[2]
    hrs = int(timing[:2])
    mins = int(timing[3:])
    
    simDeparture = hrs * 60 + mins
    simArrival = simDeparture + tA
    counter = 0
    
    for i in range(300, 1440, b):
        busDeparture = i
        busArrival = i + tB
        if busDeparture >= simArrival or simDeparture >= busArrival:
            continue
        counter += 1
    
    print(counter)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
