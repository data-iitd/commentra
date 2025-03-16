# This is the main function where the program starts execution
def main():
    # Constants are variables whose values cannot be changed during runtime.
    # Here we define a constant named MX with a value of 10000.
    MX = 10000

    # We create two lists, one named 'sieve' and another named 'primes'.
    # The 'sieve' list is of size MX and is initialized with zeros.
    # The 'primes' list is of size 0 initially but will grow dynamically.
    sieve = [0] * MX
    primes = []

    # We initialize a for loop that starts from 2 and goes up to MX-1.
    # The reason for starting from 2 is that we are only interested in prime numbers.
    # If 'sieve[i]' is already non-zero, then 'i' is not a prime number and we move on to the next iteration.
    for i in range(2, MX):
        if sieve[i] != 0:
            continue
        # If 'sieve[i]' is zero, then 'i' is a prime number.
        # We append this prime number to the 'primes' list.
        primes.append(i)

        # Now we check all multiples of 'i' starting from 'i+i' (which is the next multiple of 'i').
        # We mark all these multiples as 'composite' by setting their corresponding 'sieve' elements to 'i'.
        for j in range(i + i, MX, i):
            sieve[j] = i

    # We read an integer 'n' from the standard input using 'input' function.
    n = int(input())

    # We initialize a variable 'ans' with a value of 0.
    # This variable will store the count of numbers that are not composite.
    ans = 0

    # We read 'n' integers from the standard input using 'input' function.
    for i in range(n):
        # We read an integer 'x' from the standard input.
        x = int(input())

        # We increment the 'ans' variable as 'x' is not composite at this point.
        ans += 1

        # We check all prime numbers in the 'primes' list to see if 'x' is divisible by any of them.
        # If 'x' is divisible by any prime number, then it is composite and we decrement the 'ans' variable.
        for j in range(len(primes)):
            if x > primes[j] and x % primes[j] == 0:
                ans -= 1
                break

    # We print the final answer using 'print' function.
    print(ans)

# This is the end of the code.
