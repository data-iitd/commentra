from typing import List, Optional

class Main:
    @staticmethod
    def find_majority_element(array: List[int]) -> Optional[int]:
        if array is None or len(array) == 0:
            return None

        candidate = Main.find_candidate(array)
        count = Main.count_occurrences(candidate, array)

        if Main.is_majority(count, len(array)):
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
        return array.count(candidate)

    @staticmethod
    def is_majority(count: int, total_count: int) -> bool:
        return 2 * count > total_count

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])
        array = [int(x) for x in data[1:n+1]]

        majority_element = Main.find_majority_element(array)
        if majority_element is not None:
            print(majority_element)
        else:
            print("No majority element")

if __name__ == "__main__":
    Main.main()
