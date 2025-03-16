
# Read the total seconds from user input
S = int(input())

# Calculate hours, minutes, and seconds from the total seconds
# and print them in the format HH:MM:SS
print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")

# 