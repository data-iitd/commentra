import sys

# Function to find the majority element in the given array
def findMajorityElement(array):
    # Check if the array is null or empty; if so, return an empty Optional
    if array is None or len(array) == 0:
        return None
    # Find the candidate for the majority element
    candidate = findCandidate(array)
    # Count the occurrences of the candidate in the array
    count = countOccurrences(candidate, array)
    # Check if the candidate is indeed the majority element
    if isMajority(count, len(array)):
        return candidate # Return the candidate as the majority element
    return None # Return empty if no majority element is found

# Function to find the candidate for the majority element using the Boyer-Moore Voting Algorithm
def findCandidate(array):
    count = 0 # Initialize count
    candidate = -1 # Initialize candidate
    # Iterate through the array to find the candidate
    for value in array:
        if count == 0:
            candidate = value # Set the current value as the candidate
        # Increment or decrement the count based on whether the current value matches the candidate
        count += (value == candidate)? 1 : -1
    return candidate # Return the found candidate

# Function to count the occurrences of the candidate in the array
def countOccurrences(candidate, array):
    count = 0 # Initialize count
    # Iterate through the array to count occurrences of the candidate
    for value in array:
        if value == candidate:
            count += 1 # Increment count if the value matches the candidate
    return count # Return the total count of occurrences

# Function to check if the count of the candidate is more than half of the total count
def isMajority(count, totalCount):
    return 2 * count > totalCount # Return true if count is greater than half of totalCount

# Main method to execute the program
if __name__ == '__main__':
    # Read the size of the array
    n = int(input())
    array = [] # Initialize the array
    # Read the elements of the array from input
    for i in range(n):
        array.append(int(input()))
    # Find the majority element in the array
    majorityElement = findMajorityElement(array)
    # Print the majority element if present, otherwise print a message
    if majorityElement is not None:
        print(majorityElement) # Print the majority element
    else:
        print("No majority element") # Print message if no majority element found

