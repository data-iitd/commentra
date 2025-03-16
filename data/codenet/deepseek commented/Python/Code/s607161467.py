
R = int(input())  # Taking an integer input R

if R < 1200:  # Checking if R is less than 1200
  print("ABC")  # If true, print "ABC"
elif R < 2800:  # Checking if R is less than 2800 (and greater than or equal to 1200)
  print("ARC")  # If true, print "ARC"
else:  # If R is not less than 1200 and not less than 2800
  print("AGC")  # Print "AGC"

