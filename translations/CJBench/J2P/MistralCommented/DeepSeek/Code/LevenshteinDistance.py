def naive_main(string1, string2):
    # Initialize the distance matrix
    rows = len(string1) + 1
    columns = len(string2) + 1
    distance_matrix = [[0] * columns for _ in range(rows)]
    
    # Populate the distance matrix with costs
    for i in range(rows):
        for j in range(columns):
            if i == 0:
                distance_matrix[i][j] = j
            elif j == 0:
                distance_matrix[i][j] = i
            else:
                cost = 0 if string1[i - 1] == string2[j - 1] else 1
                distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost, distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1)
    
    # Return the final distance
    return distance_matrix[-1][-1]

def optimized_main(string1, string2):
    if len(string1) == 0:
        return len(string2)
    
    # Initialize previous distances array
    previous_distance = list(range(len(string1) + 1))
    
    for j in range(1, len(string2) + 1):
        current_distance = [j] * (len(string1) + 1)
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = current_distance[i - 1] + 1
            substitution_cost = 0 if string1[i - 1] == string2[j - 1] else 1
            current_distance[i] = min(deletion_cost, insertion_cost, previous_distance[i - 1] + substitution_cost)
        previous_distance = current_distance
    
    # Return the final distance
    return previous_distance[-1]

# Main function to read input and call the appropriate method
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    string1 = data[0]
    string2 = data[1]
    method = int(data[2])
    
    if method == 1:
        distance = naive_main(string1, string2)
    else:
        distance = optimized_main(string1, string2)
    
    print("The Levenshtein distance between the two strings is:", distance)

if __name__ == "__main__":
    main()
