
import sys

def findMajorityElement(array):
    if array == None or len(array) == 0:
        return None
    candidate = findCandidate(array)
    count = countOccurrences(candidate, array)
    if isMajority(count, len(array)):
        return candidate
    return None

def findCandidate(array):
    count = 0
    candidate = -1
    for value in array:
        if count == 0:
            candidate = value
        count += (value == candidate) and 1 or -1
    return candidate

def countOccurrences(candidate, array):
    count = 0
    for value in array:
        if value == candidate:
            count += 1
    return count

def isMajority(count, totalCount):
    return 2 * count > totalCount

def main():
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for i in range(n)]
    majorityElement = findMajorityElement(array)
    if majorityElement!= None:
        print(majorityElement)
    else:
        print("No majority element")

if __name__ == "__main__":
    main()

