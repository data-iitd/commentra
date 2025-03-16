# Step 1: Include necessary headers
import sys

# Step 2: Define the main function
def main():
	a = int(sys.stdin.readline()) # Step 3: Read input values
	b = int(sys.stdin.readline())
	mawari = 2 * (a + b) # Step 4: Calculate mawari
	menseki = a * b # Step 5: Calculate menseki
	print(menseki, mawari) # Step 6: Print the results

# Step 7: Call the main function
if __name__ == "__main__":
	main()

# Step 8: Return 0
sys.exit(0)

# 