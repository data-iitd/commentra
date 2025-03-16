import numpy as np

def naive_levenshtein(string1, string2):
    # Initialize the distance matrix
    distance_matrix = np.zeros((len(string1) + 1, len(string2) + 1), dtype=int)
    
    for i in range(len(string1) + 1):
        distance_matrix[i][0] = i
    for j in range(len(string2) + 1):
        distance_matrix[0][j] = j
    
    # Fill the distance matrix based on the Levenshtein distance algorithm
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,      # Deletion
                distance_matrix[i][j - 1] + 1,      # Insertion
                distance_matrix[i - 1][j - 1] + cost # Substitution
            )
    
    # Return the computed Levenshtein distance
    return distance_matrix[len(string1)][len(string2)]

def optimized_levenshtein(string1, string2):
    # If the first string is empty, return the length of the second string
    if not string1:
        return len(string2)
    
    # Initialize the previous distance array
    previous_distance = list(range(len(string1) + 1))
    
    # Iterate through each character of the second string
    for j in range(1, len(string2) + 1):
        prev_substitution_cost = previous_distance[0]
        previous_distance[0] = j
        
        # Iterate through each character of the first string
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = previous_distance[i - 1] + 1
            substitution_cost = prev_substitution_cost if string1[i - 1] == string2[j - 1] else prev_substitution_cost + 1
            
            prev_substitution_cost = previous_distance[i]
            previous_distance[i] = min(deletion_cost, insertion_cost, substitution_cost)
    
    # Return the computed Levenshtein distance
    return previous_distance[len(string1)]

def main():
    # Read the first string from user input
    string1 = input()
    # Read the second string from user input
    string2 = input()
    # Read the method choice from user input
    method = int(input())
    
    # Choose the method to calculate distance based on user input
    if method == 1:
        distance = naive_levenshtein(string1, string2)
    else:
        distance = optimized_levenshtein(string1, string2)
    
    # Output the calculated Levenshtein distance
    print(f"The Levenshtein distance between the two strings is: {distance}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
