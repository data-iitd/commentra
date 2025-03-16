N = int(input())  # Read the value of N from the standard input
A = list(map(int, input().split()))  # Read the elements of the array A

sum_A = sum(A)  # Calculate the sum of elements in A
wa = sum(range(1, N+1))  # Calculate the weighted sum

if sum_A % wa != 0:  # Check if the sum is divisible by wa
    print("NO")
else:
    shou = sum_A // wa  # Calculate the quotient shou
    sa = [(A[(i+1) % N] - A[i] - shou) for i in range(N)]  # Calculate the differences

    if all(x <= 0 and x % N == 0 for x in sa):  # Check if all differences are less than or equal to 0 and divisible by N
        print("YES")
    else:
        print("NO")
