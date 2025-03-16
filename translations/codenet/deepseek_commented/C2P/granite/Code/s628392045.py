
n = int(input()) # Read the number of elements
h = list(map(int, input().split())) # Read the heights of the elements and store them in a list
max_h = max(h) # Find the maximum height
flag = any(max_h - hi >= 2 for hi in h) # Check if the condition is met
print("No" if flag else "Yes") # Print "No" if the condition is met, otherwise print "Yes"

