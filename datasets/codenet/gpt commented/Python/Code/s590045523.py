# Read the number of elements in the list
N = int(input())

# Read the list of integers from input and convert them to a list of integers
L = list(map(int, input().split()))

# Initialize a counter for valid triangle combinations
ans = 0

# Iterate through the list to select the first vertex of the triangle
for i in range(N-2):
    # Iterate to select the second vertex of the triangle
    for j in range(i+1, N-1):
        # Iterate to select the third vertex of the triangle
        for k in range(j+1, N):
            # Assign the selected vertices to variables for clarity
            a = L[i]
            b = L[j]
            c = L[k]
            
            # Skip if any two vertices are the same (not a valid triangle)
            if a == b or b == c or c == a:
                continue
            
            # Check if the selected vertices can form a triangle using the triangle inequality theorem
            if a + b > c and b + c > a and c + a > b:
                # Increment the count of valid triangles
                ans += 1
                # Uncomment the following line to print the indices of the valid triangle
                # print("i:j:k:{},{},{}".format(i+1,j+1,k+1))

# Output the total count of valid triangles found
print(ans)
