# Declare an integer variable to hold the input seconds
S = int(input())

# Check if the input seconds are less than 60
if S < 60:
    # If less than 60 seconds, print the time in the format 0:0:seconds
    print(f"0:0:{S}")
# Check if the input seconds are less than 3600 (1 hour)
elif S < 3600:
    # If less than 1 hour, print the time in the format 0:minutes:seconds
    print(f"0:{S // 60}:{S % 60}")
# If the input seconds are 3600 or more (1 hour or more)
else:
    # Print the time in the format hours:minutes:seconds
    print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")

# <END-OF-CODE>
