# We import the sys module to read input from the standard input stream
import sys

def main():
    n = int(sys.stdin.readline().strip())  # We read an integer n from the standard input stream

    ans = 0  # We initialize a variable ans to 0, which will be used to store the answer

    for i in range(1, n + 1):  # We start a for loop that iterates from 1 to n
        ans += i * (n // i) * ((n // i) + 1) // 2  # We calculate the contribution of i to the answer and add it to ans

    print(ans)  # After the loop finishes, we print the value of ans to the standard output stream

if __name__ == "__main__":
    main()  # We call the main function to execute the program

# <END-OF-CODE>
