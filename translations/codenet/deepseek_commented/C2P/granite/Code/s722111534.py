
# Read the number of cells in the grid and the number of rows/columns to be painted
hcell, wcell = map(int, input().split())
hpaint, wpaint = map(int, input().split())

# Calculate the number of black cells
nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

# Calculate the number of white cells
nwhite = (hcell * wcell) - nblack

# Print the number of white cells
print(nwhite)

