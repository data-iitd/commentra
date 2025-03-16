from typing import List, Optional

class MajorityElementFinder:
    @staticmethod
    def find_majority_element(array: List[int]) -> Optional[int]:
        # Check if the array is None or empty; if so, return None
        if array is None or len(array) == 0:
            return None
        # Find the candidate for the majority element
        candidate = MajorityElementFinder.find_candidate(array)
        # Count the occurrences of the candidate in the array
        count = MajorityElementFinder.count_occurrences(candidate, array)
        # Check if the candidate is indeed the majority element
        if MajorityElementFinder.is_majority(count, len(array)):
            return candidate  # Return the candidate as the majority element
        return None  # Return None if no majority element is found

    @staticmethod
    def find_candidate(array: List[int]) -> int:
        count = 0  # Initialize count
        candidate = -1  # Initialize candidate
        # Iterate through the array to find the candidate
        for value in array:
            if count == 0:
                candidate = value  # Set the current value as the candidate
            # Increment or decrement the count based on whether the current value matches the candidate
            count += 1 if value == candidate else -1
        return candidate  # Return the found candidate

    @staticmethod
    def count_occurrences(candidate: int, array: List[int]) -> int:
        count = 0  # Initialize count
        # Iterate through the array to count occurrences of the candidate
        for value in array:
            if value == candidate:
                count += 1  # Increment count if the value matches the candidate
        return count  # Return the total count of occurrences

    @staticmethod
    def is_majority(count: int, total_count: int) -> bool:
        return 2 * count > total_count  # Return true if count is greater than half of total_count

def main():
    n = int(input())  # Read the size of the array
    array = list(map(int, input().split()))  # Read the elements of the array from input
    # Find the majority element in the array
    majority_element = MajorityElementFinder.find_majority_element(array)
    # Print the majority element if present, otherwise print a message
    if majority_element is not None:
        print(majority_element)  # Print the majority element
    else:
        print("No majority element")  # Print message if no majority element found

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
