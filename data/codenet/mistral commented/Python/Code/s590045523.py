# Taking user input and converting it into an integer list
N = int(input())
L = list(map(int, input().split()))

# Initializing a variable 'ans' to 0
ans = 0

# Outer loop runs from 0 to N-3
for i in range(N-2):
    # Inner loop 1 runs from i+1 to N-1
    for j in range(i+1, N):
        # Inner loop 2 runs from j+1 to N
        for k in range(j+1, N):
            # Assigning variables a, b, and c with values from the list L
            a = L[i]
            b = L[j]
            c = L[k]
            # Checking if a, b, and c are not equal and form a triangle
            if a == b or b == c or c == a:
                continue
            # Checking if the sides a, b, and c form a triangle using the triangle inequality theorem
            if a+b > c and b+c > a and c+a > b:
                # Incrementing the variable 'ans' by 1 if the condition is true
                ans += 1
                # Uncomment the print statement to see the values of i, j, and k
                # print("i:j:k:{},{},{}".format(i+1,j+1,k+1))

# Printing the value of the variable 'ans'
print(ans)