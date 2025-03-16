
import sys

def findMajorityElement(array):
    # Check if the array is empty or null, return empty optional if so
    if array == None or len(array) == 0:
        return None

    candidate = findCandidate(array)
    # Determine the candidate element

    count = countOccurrences(candidate, array)
    # Count the occurrences of the candidate element in the array

    if isMajority(count, len(array)):
        # If the candidate element has more than half the total count in the array, it's the majority element
        return candidate

    return None
    # Return empty optional if the candidate element is not the majority element

def findCandidate(array):
    count = 0
    candidate = -1
    # Initialize the count and candidate variables

    for value in array:
        if count == 0:
            # If there's no current candidate, set the first encountered value as the candidate
            candidate = value
        count += (value == candidate)? 1 : -1
        # Increment the count if the current value is the same as the candidate, otherwise decrement it
    return candidate
    # Return the candidate element after the loop

def countOccurrences(candidate, array):
    count = 0
    # Initialize the count variable

    for value in array:
        if value == candidate:
            count += 1
            # Increment the count if the current value is the same as the candidate
    return count
    # Return the count of occurrences of the candidate element after the loop

def isMajority(count, totalCount):
    # Check if the count of the candidate element is more than half the total count in the array
    return 2 * count > totalCount

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    # Read the number of elements in the array from the user input

    array = [int(sys.stdin.readline()) for i in range(n)]
    # Read each element in the array from the user input

    majorityElement = findMajorityElement(array)
    # Find the majority element in the array using the findMajorityElement method

    if majorityElement!= None:
        print(majorityElement)
        # Print the majority element if it exists
    else:
        print("No majority element")
        # Print "No majority element" if there's no majority element in the array

