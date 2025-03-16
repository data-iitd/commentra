
N = int(input())  # Read the number of elements in the list
L = list(map(int, input().split()))  # Read the list of integers

ans = 0  # Initialize the counter for the number of valid triangles

# Iterate through all possible combinations of three different elements
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            a = L[i]
            b = L[j]
            c = L[k]
            
            # Check if the three elements can form a triangle
            if a == b or b == c or c == a:
                continue  # Skip if any two elements are equal
            
            # Check the triangle inequality
            if a+b>c and b+c>a and c+a>b:
                ans += 1  # Increment the counter if a valid triangle is found
                # print("i:j:k:{},{},{}".format(i+1,j+1,k+1))  # Optional: Print the indices of the triangle

print(ans)  # Print the total number of valid triangles found

