#!/usr/bin/env python3

import sys

# get_next_line reads the next line from the standard input.
def get_next_line():
	return sys.stdin.readline().strip()

# get_next_int reads the next integer from the standard input.
def get_next_int():
	return int(get_next_line())

# get_next_float reads the next float from the standard input.
def get_next_float():
	return float(get_next_line())

# get_next_string reads the next string from the standard input.
def get_next_string():
	return str(get_next_line())

# solve processes the input values and determines if the condition is met.
# It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
def solve(k, x):
	ans = "No" # Default answer is "No".
	if k*500 >= x: # Check the condition.
		ans = "Yes" # Update answer to "Yes" if condition is met.
	print(ans) # Output the result.

# main reads input values and processes them.
def main():
	# Check for environment variables to determine input and output files.
	if os.getenv("MASPY") == "ますピ":
		sys.stdin = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
	if os.getenv("MASPYPY") == "ますピッピ":
		sys.stdout = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

	# Read the first integer k.
	k = get_next_int()

	# Read the second integer x.
	x = get_next_int()

	# Solve the problem for the first time.
	solve(k, x)

	# If cnt is greater than 0, solve the problem additional times.
	cnt = 0
	if os.getenv("MASPYPY") == "ますピッピ":
		cnt = 2 # Set the count for additional processing.
	for i in range(cnt):
		print("-----------------------------------")
		solve(k, x)

# Entry point of program.
if __name__ == "__main__":
	main()

# 