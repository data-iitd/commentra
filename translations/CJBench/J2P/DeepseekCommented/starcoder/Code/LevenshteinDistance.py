import sys

def naiveMain(string1, string2):
    # Initialize the distance matrix with dimensions (string1.length() + 1) x (string2.length() + 1)
    distanceMatrix = [[0 for j in range(len(string2) + 1)] for i in range(len(string1) + 1)]

    # Fill the distance matrix based on the comparison of characters in the two strings
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            distanceMatrix[i][j] = min(distanceMatrix[i - 1][j - 1] + cost, min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1))

    # Return the Levenshtein distance between the two strings
    return distanceMatrix[len(string1)][len(string2)]

def optimizedMain(string1, string2):
    # If the first string is empty, the distance is the length of the second string
    if string1 == "":
        return len(string2)

    # Initialize the distance array with dimensions (string1.length() + 1)
    previousDistance = [0 for i in range(len(string1) + 1)]

    # Fill the distance array based on the comparison of characters in the two strings
    for j in range(1, len(string2) + 1):
        prevSubstitutionCost = previousDistance[0]
        previousDistance[0] = j
        for i in range(1, len(string1) + 1):
            deletionCost = previousDistance[i] + 1
            insertionCost = previousDistance[i - 1] + 1
            substitutionCost = 0 if string1[i - 1] == string2[j - 1] else prevSubstitutionCost + 1
            prevSubstitutionCost = previousDistance[i]
            previousDistance[i] = min(deletionCost, min(insertionCost, substitutionCost))

    # Return the Levenshtein distance between the two strings
    return previousDistance[len(string1)]

# Main method to read input, determine the method to use, and print the Levenshtein distance
if __name__ == "__main__":
    string1 = sys.stdin.readline().strip()
    string2 = sys.stdin.readline().strip()
    method = int(sys.stdin.readline().strip())
    distance = naiveMain(string1, string2) if method == 1 else optimizedMain(string1, string2)
    print("The Levenshtein distance between the two strings is: " + str(distance))

