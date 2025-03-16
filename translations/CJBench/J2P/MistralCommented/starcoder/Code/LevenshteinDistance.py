
import sys

def naiveMain(string1, string2):
    distanceMatrix = initializeDistanceMatrix(string1, string2) # Initialize the distance matrix
    populateDistanceMatrix(distanceMatrix, string1, string2) # Populate the distance matrix with costs
    return getDistance(distanceMatrix) # Return the final distance

def initializeDistanceMatrix(string1, string2):
    rows = len(string1) + 1
    columns = len(string2) + 1
    return [[(i == 0)? j : (j == 0)? i : 0 for j in range(columns)] for i in range(rows)]

def populateDistanceMatrix(distanceMatrix, string1, string2):
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            setDistance(distanceMatrix, i, j, cost)

def setDistance(distanceMatrix, i, j, cost):
    distanceMatrix[i][j] = calculateMinimumDistance(distanceMatrix[i - 1][j - 1], distanceMatrix[i][j - 1], distanceMatrix[i - 1][j], cost)

def calculateMinimumDistance(a, b, c, cost):
    return min(a + cost, min(b + 1, c + 1))

def optimizedMain(string1, string2):
    if string1 == "":
        return lengthOfString2(string2)
    previousDistance = [0] * (len(string1) + 1) # Initialize previous distances array
    for j in range(1, len(string2) + 1):
        prevSubstitutionCost = previousDistance[0]
        previousDistance[0] = j
        for i in range(1, len(string1) + 1):
            deletionCost = previousDistance[i] + 1
            insertionCost = previousDistance[i - 1] + 1
            substitutionCost = 0 if string1[i - 1] == string2[j - 1] else prevSubstitutionCost + 1
            updatePreviousDistance(previousDistance, i, j, deletionCost, insertionCost, substitutionCost)
    return previousDistance[len(string1)]

def updatePreviousDistance(previousDistance, i, j, deletionCost, insertionCost, substitutionCost):
    previousDistance[i] = min(deletionCost, min(insertionCost, substitutionCost))

def lengthOfString2(string2):
    return len(string2)

def main():
    string1 = sys.stdin.readline().strip() # Read the first string from the input
    string2 = sys.stdin.readline().strip() # Read the second string from the input
    method = int(sys.stdin.readline().strip()) # Read the method number from the input
    distance = naiveMain(string1, string2) if method == 1 else optimizedMain(string1, string2) # Call the naive method if method number is 1
    print("The Levenshtein distance between the two strings is: " + str(distance)) # Print the result to the console

if __name__ == "__main__":
    main()

