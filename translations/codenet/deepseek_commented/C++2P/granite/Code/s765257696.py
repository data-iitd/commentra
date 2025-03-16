
import sys

def main():
    n = int(input()) # Comment 1: Reads the size of the array p from standard input
    p = list(map(int, input().split())) # Comment 2: Populates the array p with n integers from standard input
    ans = 0 # Comment 3: Initializes the variable ans to 0

    for i in range(n - 2): # Comment 4: Loops through the array p
        if p[i] > p[i+1] and p[i+1] > p[i+2]: ans += 1 # Comment 5: Checks for a peak and increments ans
        if p[i] < p[i+1] and p[i+1] < p[i+2]: ans += 1 # Comment 6: Checks for a valley and increments ans

    print(ans) # Comment 7: Prints the final value of ans to standard output

if __name__ == "__main__":
    sys.exit(main()) # Comment 8: Ends the program by returning 0

