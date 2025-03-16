from typing import List, Optional

def find_majority_element(array: List[int]) -> Optional[int]:
    if array is None or len(array) == 0:
        return None
    candidate = find_candidate(array)
    count = count_occurrences(candidate, array)
    if is_majority(count, len(array)):
        return candidate
    return None

def find_candidate(array: List[int]) -> int:
    count = 0
    candidate = -1
    for value in array:
        if count == 0:
            candidate = value
        count += 1 if value == candidate else -1
    return candidate

def count_occurrences(candidate: int, array: List[int]) -> int:
    count = 0
    for value in array:
        if value == candidate:
            count += 1
    return count

def is_majority(count: int, total_count: int) -> bool:
    return 2 * count > total_count

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    majority_element = find_majority_element(array)
    if majority_element is not None:
        print(majority_element)
    else:
        print("No majority element")

# <END-OF-CODE>











