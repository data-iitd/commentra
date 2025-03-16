
# <START-OF-CODE>
import sys

def main():
    input = sys.stdin.readline()
    a, tA, b, tB = map(int, input.split())
    timing = sys.stdin.readline()
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
    print(counter)

if __name__ == '__main__':
    main()
# 