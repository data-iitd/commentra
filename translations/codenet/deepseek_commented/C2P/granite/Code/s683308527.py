
import sys  # Import necessary modules

n = int(input())  # Read the number of lines
for _ in range(n):  # Loop through each line
  s = input()  # Read the input line
  while "Hoshino" in s:  # Check if "Hoshino" is present in the line
    s = s.replace("Hoshino","Hoshina",1)  # Replace the first occurrence of "Hoshino" with "Hoshina"
  print(s)  # Print the modified line

