import sys

def naive_main(string1, string2):
    # Initialize the distance matrix
    distance_matrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]
    
    # Fill the distance matrix based on the Levenshtein distance algorithm
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            # Determine the cost of substitution
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            # Calculate the minimum cost for the current cell in the matrix
            distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                        min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))
    
    # Return the computed Levenshtein distance
    return distance_matrix[len(string1)][len(string2)]

def optimized_main(string1, string2):
    # If the first string is empty, return the length of the second string
    if not string1:
        return len(string2)
    
    # Initialize the previous distance array
    previous_distance = [0] * (len(string1) + 1)
    
    # Iterate through each character of the second string
    for j in range(1, len(string2) + 1):
        # Store the cost of the previous substitution
        prev_substitution_cost = previous_distance[0]
        # Update the first element of the previous distance array
        previous_distance[0] = j
        
        # Iterate through each character of the first string
        for i in range(1, len(string1) + 1):
            # Calculate costs for deletion, insertion, and substitution
            deletion_cost = previous_distance[i] + 1
            insertion_cost = previous_distance[i - 1] + 1
            substitution_cost = prev_substitution_cost + (0 if string1[i - 1] == string2[j - 1] else 1)
            
            # Update the previous substitution cost
            prev_substitution_cost = previous_distance[i]
            
            # Update the current cell in the previous distance array with the minimum cost
            previous_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))
    
    # Return the computed Levenshtein distance
    return previous_distance[len(string1)]

if __name__ == "__main__":
    # Read the first string from user input
    string1 = sys.stdin.readline().strip()
    # Read the second string from user input
    string2 = sys.stdin.readline().strip()
    # Read the method choice from user input
    method = int(sys.stdin.readline().strip())
    distance = 0
    
    # Choose the method to calculate distance based on user input
    if method == 1:
        distance = naive_main(string1, string2)
    else:
        distance = optimized_main(string1, string2)
    
    # Output the calculated Levenshtein distance
    print("The Levenshtein distance between the two strings is: " + str(distance))

