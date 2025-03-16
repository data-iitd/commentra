#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
    # Declare variables for input and a map to store string entries
    n = int(input()) # Number of commands to process
    str = [] # Arrays to hold command and string inputs
    com = []
    T = {} # Map to track the presence of strings (true if present)

    # Loop through each command
    for i in range(n):
        # Read the command and the associated string
        com.append(input())
        str.append(input())
        
        # Check if the command is 'insert' (indicated by the first character being 'i')
        if com[i][0] == 'i':
            # Insert the string into the map with a value of true
            T[str[i]] = True
        else:
            # If the command is not 'insert', check if the string exists in the map
            if str[i] in T:
                # If the string exists, print "yes"
                print("yes")
            else:
                # If the string does not exist, print "no"
                print("no")

    # Return 0 to indicate successful execution
    return 0
}

