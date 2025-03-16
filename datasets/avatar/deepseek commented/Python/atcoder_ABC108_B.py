# 1. The code starts by taking input from the user, which is split into a list of strings.
p = input().split(" ")

# 2. The first element of the list is converted to an integer and assigned to x1.
x1 = int(p[0])

# 3. The second element of the list is converted to an integer and assigned to y1.
y1 = int(p[1])

# 4. The third element of the list is converted to an integer and assigned to x2.
x2 = int(p[2])

# 5. The fourth element of the list is converted to an integer and assigned to y2.
y2 = int(p[3])

# 6. The difference between x2 and x1 is calculated and assigned to DIF1.
DIF1 = x2 - x1

# 7. The difference between y2 and y1 is calculated and assigned to DIF2.
DIF2 = y2 - y1

# 8. x3 is calculated as x2 minus DIF2.
x3 = x2 - DIF2

# 9. y3 is calculated as y2 plus DIF1.
y3 = y2 + DIF1

# 10. x4 is calculated as x1 minus DIF2.
x4 = x1 - DIF2

# 11. y4 is calculated as y1 plus DIF1.
y4 = y1 + DIF1

# 12. Finally, the coordinates x3, y3, x4, and y4 are printed in a formatted string.
print(str(x3) + " " + str(y3) + " " + str(x4) + " " + str(y4))
