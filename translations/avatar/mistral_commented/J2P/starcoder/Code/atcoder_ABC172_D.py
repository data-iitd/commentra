import sys ; // We import the sys module to read input from the standard input stream

n = int ( sys.stdin.readline ( ) ) ; // We read an integer n from the standard input stream using the readline method of the sys module

ans = 0 ; // We initialize a long variable ans to 0, which will be used to store the answer

for i in range ( 1, n + 1 ) : // We start a for loop that iterates from 1 to n
    ans += i * ( n // i ) * ( ( n // i ) + 1 ) // In each iteration of the loop, we calculate the contribution of i to the answer using the formula i * (n / i) * ((n / i) + 1) and add it to the ans variable

print ( ans ) ; // After the loop finishes, we print the value of ans to the standard output stream using the print function

# 