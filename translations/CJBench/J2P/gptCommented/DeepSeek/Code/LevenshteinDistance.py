def naive_main(string1, string2):
    # Initialize the distance matrix
    distance_matrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]
    
    # Fill the distance matrix based on the Levenshtein distance algorithm
    for i in range(len(string1) + 1):
        for j in range(len(string2) + 1):
            if i == 0:
                distance_matrix[i][j] = j
            elif j == 0:
                distance_matrix[i][j] = i
            else:
                cost = 0 if string1[i - 1] == string2[j - 1] else 1
                distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                            min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))
    
    # Return the computed Levenshtein distance
    return distance_matrix[len(string1)][len(string2)]


def optimized_main(string1, string2):
    # If the first string is empty, return the length of the second string
    if not string1:
        return len(string2)
    
    # Initialize the previous distance array
    previous_distance = list(range(len(string1) + 1))
    
    # Iterate through each character of the second string
    for j in range(1, len(string2) + 1):
        current_distance = [0] * (len(string1) + 1)
        current_distance[0] = j
        
        # Iterate through each character of the first string
        for i in range(1, len(string1) + 1):
            deletion_cost = current_distance[i - 1] + 1
            insertion_cost = previous_distance[i] + 1
            substitution_cost = 0 if string1[i - 1] == string2[j - 1] else 1
            substitution_cost += previous_distance[i - 1]
            
            # Update the current cell in the current distance array with the minimum cost
            current_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))
        
        # Update the previous distance array with the current distance array
        previous_distance = current_distance
    
    # Return the computed Levenshtein distance
    return previous_distance[len(string1)]


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    string1 = data[0]
    string2 = data[1]
    method = int(data[2])
    distance = 0
    
    # Choose the method to calculate distance based on user input
    if method == 1:
        distance = naive_main(string1, string2)
    else:
        distance = optimized_main(string1, string2)
    
    # Output the calculated Levenshtein distance
    print("The Levenshtein distance between the two strings is: {}".format(distance))


if __name__ == "__main__":
    main()
