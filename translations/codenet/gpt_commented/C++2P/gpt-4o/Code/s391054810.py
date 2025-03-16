# Declare variables to hold the height and width of the rectangle,
# as well as the height and width of the cut-out section.
h, w, hh, ww = map(int, input().split())

# Calculate the area of the remaining rectangle after the cut-out section
# by subtracting the cut-out dimensions from the original dimensions.
# The area is calculated as (remaining height) * (remaining width).
print((h - hh) * (w - ww))

# Return 0 to indicate that the program finished successfully.
# In Python, we don't need to explicitly return 0.
# <END-OF-CODE>
