# We declare and initialize some variables and arrays here.
kekka = [0,0]
prime_or_not = [0 for i in range(1001)]
prime_list = [0 for i in range(1001)]
prime_counter = 0

# This function calculates prime numbers up to 1000 and stores them in prime_list[].
def sosuubunnpu():
    # Initialize prime_or_not[] to all zeros.
    for i in range(1,1001):
        prime_or_not[i] = 0
    # Mark non-prime numbers as 1 in prime_or_not[].
    for i in range(2,1001):
        for j in range(2,1000/i+1):
            if prime_or_not[i]==0:
                prime_or_not[i*j] = 1
    # Store prime numbers in prime_list[].
    for i in range(2,1001):
        if prime_or_not[i]==0:
            prime_list[prime_counter] = i
            prime_counter+=1

# This function calculates the exponent of a prime number in a given number.
def innsuubunnkai(N,n):
    # Initialize time to 0.
    time = 0
    # Calculate the exponent of prime number n in N.
    while 1:
        if N%n == 0:
            N = N/n
            time+=1
        else:
            break
    # Store the result in kekka[].
    kekka[0] = time
    kekka[1] = N

# This is the main function where we call sosuubunnpu() and perform the main calculation.
def main():
    # Call sosuubunnpu() to calculate prime numbers.
    sosuubunnpu()
    # Read the input N from the standard input.
    N = int(input())
    # Initialize innsuu[] and A[] here.
    innsuu = [0 for i in range(11)]
    A = [[0 for i in range(11)] for j in range(N+1)]
    # Initialize prime_num[] to zeros.
    prime_num = [0 for i in range(1001)]
    # Calculate prime_num[] using innsuubunnkai().
    for current_num in range(2,N+1):
        kekka[1] = current_num
        for i in range(prime_counter):
            innsuubunnkai(kekka[1],prime_list[i])
            prime_num[i]+=kekka[0]
    # Calculate the final result.
    result = 1
    for current_num in range(2,N+1):
        for i in range(11):
            innsuu[i] += A[current_num][i]
    for i in range(prime_counter):
        result = (result*(prime_num[i]+1))%1000000007
    # Output the final result.
    print(result)

# 