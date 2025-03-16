#include<iostream>
#include<string>
using namespace std;

int main() {
    # Declare variables to hold two integers and a character for the operation
    a, b = 0, 0
    S = ''

    # Start an infinite loop to continuously accept user input
    while True:
        # Read two integers and an operator from the user
        a, S, b = input().split()

        # Perform addition if the operator is '+'
        if S == '+':
            print(int(a) + int(b))

        # Perform subtraction if the operator is '-'
        if S == '-':
            print(int(a) - int(b))

        # Perform multiplication if the operator is '*'
        if S == '*':
            print(int(a) * int(b))

        # Perform division if the operator is '/'
        if S == '/':
            print(int(a) / int(b))

        # Exit the loop if the operator is '?'
        if S == '?':
            break

# 