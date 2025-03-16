# Declare variables for cell dimensions and paint dimensions
hcell, wcell, hpaint, wpaint = map(int, input().split())

# Calculate the number of black cells painted
nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

# Calculate the number of white cells remaining
# Total cells - painted black cells
nwhite = (hcell * wcell) - nblack

# Output the number of white cells
print(nwhite)
