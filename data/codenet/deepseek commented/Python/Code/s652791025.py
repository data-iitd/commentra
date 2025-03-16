
n = input()
# Taking user input and converting the last digit of the input to an integer.
n = int(n[-1])

if n == 2 or n == 4 or n == 5 or n == 7 or n == 9:
  # Checking if the last digit is one of the specified values and printing "hon" if it is.
  print("hon")
elif n == 0 or n == 1 or n == 6 or n == 8:
  # If the last digit is not one of the specified values, checking if it is one of the other specified values and printing "pon" if it is.
  print("pon")
else:
  # If the last digit is not one of the specified values, printing "bon".
  print("bon")

