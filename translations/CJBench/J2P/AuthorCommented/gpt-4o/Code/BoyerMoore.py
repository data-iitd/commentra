from typing import List, Optional

class MajorityElementFinder:
    @staticmethod
    def find_majority_element(array: List[int]) -> Optional[int]:
        if array is None or len(array) == 0:
            return None

        candidate = MajorityElementFinder.find_candidate(array)
        count = MajorityElementFinder.count_occurrences(candidate, array)

        if MajorityElementFinder.is_majority(count, len(array)):
            return candidate
        return None

    @staticmethod
    def find_candidate(array: List[int]) -> int:
        count = 0
        candidate = -1
        for value in array:
            if count == 0:
                candidate = value
            count += 1 if value == candidate else -1
        return candidate

    @staticmethod
    def count_occurrences(candidate: int, array: List[int]) -> int:
        count = 0
        for value in array:
            if value == candidate:
                count += 1
        return count

    @staticmethod
    def is_majority(count: int, total_count: int) -> bool:
        return 2 * count > total_count

def main():
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))

    majority_element = MajorityElementFinder.find_majority_element(array)
    if majority_element is not None:
        print(majority_element)
    else:
        print("No majority element")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
