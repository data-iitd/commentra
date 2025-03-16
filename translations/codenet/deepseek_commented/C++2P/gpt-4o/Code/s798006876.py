MAX_N = int(1e3)  # Define the maximum size of the array
data = [0] * MAX_N  # Declare the array to store the data

while True:
    m, nmi, nma = map(int, input().split())  # Read the values of m, nmi, and nma
    if nmi == 0:  # Break the loop if nmi is 0
        break
    for i in range(m):
        data[i] = int(input())  # Read m integers into the array data
    ma = 0  # Initialize the maximum difference to 0
    ans = 0  # Initialize the answer index to 0
    for i in range(nmi - 1, nma - 1):  # Loop through the range from nmi-1 to nma-1
        if ma <= data[i] - data[i + 1]:  # Check if the current difference is greater than the maximum difference found so far
            ans = i + 1  # Update the answer index
            ma = data[i] - data[i + 1]  # Update the maximum difference
    print(ans)  # Print the answer index

# <END-OF-CODE>
