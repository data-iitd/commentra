# Include necessary headers for printf and scanf
import sys

# Define the main function
def main():
    s = sys.stdin.readline().rstrip() # Read the first string from the user and store it in s
    t = sys.stdin.readline().rstrip() # Read the second string from the user and store it in t
    hit = 0 # Initialize a counter for hits
    for i in range(3): # Compare characters in the strings
        if s[i] == t[i]: hit += 1 # Increment the hit counter if characters match
    print(hit) # Print the number of matching characters

# Call the main function
if __name__ == "__main__":
    main()

