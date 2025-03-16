#include <stdio.h>

int main() {
    # Declare an integer variable to hold the input seconds
    in = int(input())

    # Declare variables to hold hours, minutes, and seconds
    h = in // 3600
    in %= 3600

    m = in // 60
    in %= 60

    s = in

    # Print the result in the format of hours:minutes:seconds
    print(f"{h}:{m}:{s}")
}

