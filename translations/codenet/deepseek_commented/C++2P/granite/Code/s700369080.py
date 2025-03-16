
x1, y1, x2, y2 = map(int, input().split()) # Read four integers from the standard input
dx, dy = x2 - x1, y2 - y1 # Calculate the differences between the coordinates
x3, y3 = x2 - dy, y2 + dx # Compute the new coordinates based on the differences
x4, y4 = x1 - dy, y1 + dx # Compute the new coordinates based on the differences
print(x3, y3, x4, y4) # Output the new coordinates