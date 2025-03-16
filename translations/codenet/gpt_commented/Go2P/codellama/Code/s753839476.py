
import sys

# Initialize input/output handling
io, flash = new_io()
defer flash() # Ensure the writer is flushed before exiting

# Read the number of heights, target temperature, and actual temperature
n, t, a = io.scan_int(), io.scan_float(), io.scan_float()
# Read the heights as a list of float64
heights = io.scan_float_list(n)

# Initialize minimum difference and index for tracking the closest height
min_diff = abs_diff_float(t-heights[0]*0.006, a)
min_idx = 0

# Iterate through the heights to find the one with the minimum temperature difference
for i, h in enumerate(heights[1:]):
    diff = abs_diff_float(t-h*0.006, a)
    if diff < min_diff:
        min_diff = diff
        min_idx = i + 1 # Update the index of the closest height

# Output the 1-based index of the closest height
print(min_idx + 1)

# 