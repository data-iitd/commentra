#include <iostream>
#include <queue>

using namespace std;

int main() {
    # Declare arrays to hold the arrival times for train and bus
    train = [0, 0]
    bus = [0, 0]

    # Input the arrival times for the train
    train[0], train[1] = map(int, input().split())
    # Input the arrival times for the bus
    bus[0], bus[1] = map(int, input().split())

    # Calculate the minimum arrival time between the two times for train and bus,
    # and output the total minimum arrival time
    print(min(train[0], train[1]) + min(bus[0], bus[1]))

    return 0 # End of the program
}

