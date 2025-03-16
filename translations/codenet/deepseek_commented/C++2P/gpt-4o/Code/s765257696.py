def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Comment 3: Reads the size of the array p from standard input
    p = list(map(int, data[1:n+1]))  # Comment 4: Populates the array p with n integers from standard input

    ans = 0  # Comment 5: Initializes the variable ans to 0

    for i in range(n - 2):  # Comment 6: Loops through the array p
        if p[i] > p[i + 1] and p[i + 1] > p[i + 2]:  # Comment 7: Checks for a peak and increments ans
            ans += 1
        if p[i] < p[i + 1] and p[i + 1] < p[i + 2]:  # Comment 8: Checks for a valley and increments ans
            ans += 1

    print(ans)  # Comment 9: Prints the final value of ans to standard output

if __name__ == "__main__":
    main()  # Comment 10: Ends the program by calling the main function

# <END-OF-CODE>
