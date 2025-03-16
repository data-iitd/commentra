
import sys

class Main:

    def __init__(self):
        pass

    def naiveMain(self, string1, string2):
        distanceMatrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]

        for i in range(1, len(string1) + 1):
            for j in range(1, len(string2) + 1):
                cost = 0 if string1[i - 1] == string2[j - 1] else 1
                distanceMatrix[i][j] = min(distanceMatrix[i - 1][j - 1] + cost, min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1))

        return distanceMatrix[len(string1)][len(string2)]

    def optimizedMain(self, string1, string2):
        if string1 == "":
            return len(string2)

        previousDistance = [0 for _ in range(len(string1) + 1)]

        for j in range(1, len(string2) + 1):
            prevSubstitutionCost = previousDistance[0]
            previousDistance[0] = j

            for i in range(1, len(string1) + 1):
                deletionCost = previousDistance[i] + 1
                insertionCost = previousDistance[i - 1] + 1
                substitutionCost = 0 if string1[i - 1] == string2[j - 1] else prevSubstitutionCost + 1
                prevSubstitutionCost = previousDistance[i]
                previousDistance[i] = min(deletionCost, min(insertionCost, substitutionCost))

        return previousDistance[len(string1)]

    def main(self):
        string1 = sys.stdin.readline().strip()
        string2 = sys.stdin.readline().strip()

        method = int(sys.stdin.readline().strip())

        distance = self.naiveMain(string1, string2) if method == 1 else self.optimizedMain(string1, string2)

        print("The Levenshtein distance between the two strings is: " + str(distance))

if __name__ == "__main__":
    Main().main()

