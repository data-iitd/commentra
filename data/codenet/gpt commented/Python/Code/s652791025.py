# Get user input and convert it to an integer based on the last character
n = input()
n = int(n[-1])

# Check if the last digit corresponds to the 'hon' category
if n == 2 or n == 4 or n == 5 or n == 7 or n == 9:
    print("hon")  # Print "hon" for specific last digits

# Check if the last digit corresponds to the 'pon' category
elif n == 0 or n == 1 or n == 6 or n == 8:
    print("pon")  # Print "pon" for another set of specific last digits

# If the last digit does not match any previous categories, it falls into the 'bon' category
else:
    print("bon")  # Print "bon" for all other last digits
