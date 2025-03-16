
import sys

class Main:

    def __init__(self):
        pass

    def findMajorityElement(self, array):
        if array == None or len(array) == 0:
            return None

        candidate = self.findCandidate(array)
        count = self.countOccurrences(candidate, array)

        if self.isMajority(count, len(array)):
            return candidate
        return None

    def findCandidate(self, array):
        count = 0
        candidate = -1
        for value in array:
            if count == 0:
                candidate = value
            count += (value == candidate) and 1 or -1
        return candidate

    def countOccurrences(self, candidate, array):
        count = 0
        for value in array:
            if value == candidate:
                count += 1
        return count

    def isMajority(self, count, totalCount):
        return 2 * count > totalCount

    def main(self):
        # Input the size of the array
        n = int(raw_input())
        array = [0] * n

        # Input the array elements
        for i in range(0, n):
            array[i] = int(raw_input())

        # Find and display the majority element if it exists
        majorityElement = self.findMajorityElement(array)
        if majorityElement!= None:
            print majorityElement
        else:
            print "No majority element"

# 