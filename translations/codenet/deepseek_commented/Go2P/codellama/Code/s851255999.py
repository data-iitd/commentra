
# Read the number of works
n = int(input())

# Create a list of work structs with a length of n
ws = [None] * n

# Read the time and limit for each work and store them in the list
for i in range(n):
    a, n = map(int, input().split())
    ws[i] = (a, n)

# Sort the list of works based on the limit field
ws.sort(key=lambda x: x[1])

# Initialize a sum variable to keep track of the cumulative time
sum = 0

# Iterate over the sorted list of works, adding the time of each work to the sum
for w in ws:
    sum += w[0]
    
    # Check if the cumulative time exceeds the limit of the current work
    if sum > w[1]:
        print("No")
        break
else:
    print("Yes")

