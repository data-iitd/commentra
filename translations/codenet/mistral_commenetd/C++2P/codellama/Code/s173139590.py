
#include <iostream>
#include <string>
using namespace std;

# Initialize variables to store the number of each contest result
n = 0 # number of contest results to be read
ac_count = 0 # number of AC (Accepted) results
wa_count = 0 # number of WA (Wrong Answer) results
tle_count = 0 # number of TLE (Time Limit Exceeded) results
re_count = 0 # number of RE (Runtime Error) results

def main():
    # Read the number of contest results from the standard input
    n = int(input())

    # Read each contest result and update the corresponding counter
    for i in range(n):
        s = input() # string to store the contest result (AC, WA, TLE, or RE)
        if s == "AC": # if the contest result is AC
            ac_count += 1 # increment the number of AC results
        elif s == "WA": # if the contest result is WA
            wa_count += 1 # increment the number of WA results
        elif s == "TLE": # if the contest result is TLE
            tle_count += 1 # increment the number of TLE results
        elif s == "RE": # if the contest result is RE
            re_count += 1 # increment the number of RE results

    # Print the number of each contest result to the standard output
    print("AC x", ac_count)
    print("WA x", wa_count)
    print("TLE x", tle_count)
    print("RE x", re_count)

# 