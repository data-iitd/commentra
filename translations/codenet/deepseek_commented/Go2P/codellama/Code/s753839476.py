
import sys

# Main function: Reads input values, calculates the minimum difference, and prints the index.
def main():
    n, t, a = map(float, sys.stdin.readline().split()) # Read values for n, t, and a.
    heights = list(map(float, sys.stdin.readline().split())) # Read a list of heights.

    minDiff = abs(t - heights[0] * 0.006 - a) # Calculate the initial minimum difference.
    minIdx = 0 # Initialize the index of the minimum difference.
    for i, h in enumerate(heights[1:]): # Iterate through the heights starting from the second element.
        diff = abs(t - h * 0.006 - a) # Calculate the difference for the current height.
        if diff < minDiff: # Update the minimum difference and index if a smaller difference is found.
            minDiff = diff
            minIdx = i + 1
    print(minIdx + 1) # Print the index (plus one for 1-based indexing).

if __name__ == "__main__":
    main()

