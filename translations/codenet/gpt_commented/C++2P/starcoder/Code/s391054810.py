# Declare variables to hold the height and width of the rectangle,
# as well as the height and width of the cut-out section.
h, w, hh, ww = int(input()), int(input()), int(input()), int(input())

# Calculate the area of the remaining rectangle after the cut-out section
# by subtracting the cut-out dimensions from the original dimensions.
# The area is calculated as (remaining height) * (remaining width).
print((h - hh) * (w - ww))

