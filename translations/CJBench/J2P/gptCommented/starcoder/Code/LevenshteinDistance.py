import sys

# Private method to calculate the Levenshtein distance using a naive approach
def naiveMain(string1, string2):
    # Initialize the distance matrix
    distanceMatrix = [[0 for j in range(len(string2) + 1)] for i in range(len(string1) + 1)]
    
    # Fill the distance matrix based on the Levenshtein distance algorithm
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            # Determine the cost of substitution
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            # Calculate the minimum cost for the current cell in the matrix
            distanceMatrix[i][j] = min(distanceMatrix[i - 1][j - 1] + cost, min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1))
    
    # Return the computed Levenshtein distance
    return distanceMatrix[len(string1)][len(string2)]

# Private method to calculate the Levenshtein distance using an optimized approach
def optimizedMain(string1, string2):
    # If the first string is empty, return the length of the second string
    if string1 == "":
        return len(string2)
    
    # Initialize the previous distance array
    previousDistance = [0 for i in range(len(string1) + 1)]
    
    # Iterate through each character of the second string
    for j in range(1, len(string2) + 1):
        # Store the cost of the previous substitution
        prevSubstitutionCost = previousDistance[0]
        # Update the first element of the previous distance array
        previousDistance[0] = j
        
        # Iterate through each character of the first string
        for i in range(1, len(string1) + 1):
            # Calculate costs for deletion, insertion, and substitution
            deletionCost = previousDistance[i] + 1
            insertionCost = previousDistance[i - 1] + 1
            substitutionCost = 0 if string1[i - 1] == string2[j - 1] else prevSubstitutionCost + 1
            
            # Update the previous substitution cost
            prevSubstitutionCost = previousDistance[i]
            
            # Update the current cell in the previous distance array with the minimum cost
            previousDistance[i] = min(deletionCost, min(insertionCost, substitutionCost))
    
    # Return the computed Levenshtein distance
    return previousDistance[len(string1)]

# Main method to execute the program
def main():
    # Read the first string from user input
    string1 = sys.stdin.readline().strip()
    # Read the second string from user input
    string2 = sys.stdin.readline().strip()
    # Read the method choice from user input
    method = int(sys.stdin.readline().strip())
    distance = 0
    
    # Choose the method to calculate distance based on user input
    if method == 1:
        distance = naiveMain(string1, string2)
    else:
        distance = optimizedMain(string1, string2)
    
    # Output the calculated Levenshtein distance
    print("The Levenshtein distance between the two strings is: " + str(distance))

# Entry point of the program
if __name__ == "__main__":
    main()

