#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i = 0; i < int(n); i++) // Macro for repetition of a loop n times

string input, ss; // Input string and string for parsing
int a[3], it, cnt; // Arrays and counters

def Not(x): # Function to calculate NOT of a binary number
    return 2-x

def And(x, y): # Function to calculate AND of two binary numbers
    if x*y == 0: return 0 # If product of x and y is zero, return zero
    if x == 2 and y == 2: return 2 # If both x and y are 2, return 2
    return 1 # Otherwise, return 1

def Or(x, y): # Function to calculate OR of two binary numbers
    if x == 2 or y == 2: return 2 # If either x or y is 2, return 2
    if x == 1 or y == 1: return 1 # If either x or y is 1, return 1
    return 0 # Otherwise, return 0

def parse(): # Function to parse the input string and calculate the logical expression
    c = ss[it] # Read the next character from the input string
    if '0' <= c <= '2': return int(c) # If character is a binary digit, convert it to an integer and return
    if c == '-': return Not(parse()) # If character is NOT, recursively call parse() and apply NOT

    x = parse() # Parse the first binary number
    c = ss[it] # Read the next character from the input string
    y = parse() # Parse the second binary number
    it += 1 # Increment the index of the input string
    return c == '*' and And(x, y) or Or(x, y) # If character is AND, call And() function. Otherwise, call Or() function

while True: # Main function
    input = input() # Read input until end of file is reached
    if input == ".": break # If input is ".", break the loop
    rep(i,3) rep(j,3) rep(k,3): # Nested loop to generate all possible combinations of a, b, c
        a[0] = i; a[1] = j; a[2] = k;
        ss = input # Set the input string for the current combination
        for c in ss: # Replace P, Q, R with the values of a, b, c respectively
            if c == 'P': c = a[0]+'0'
            if c == 'Q': c = a[1]+'0'
            if c == 'R': c = a[2]+'0'
        it = 0 # Reset the index of the input string
        if parse() == 2: cnt += 1 # If the logical expression is valid, increment the counter
    print(cnt) # Print the number of valid expressions for the current input

