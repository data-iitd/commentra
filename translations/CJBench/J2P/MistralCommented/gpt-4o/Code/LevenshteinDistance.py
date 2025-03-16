def naive_main(string1, string2):
    distance_matrix = initialize_distance_matrix(string1, string2)  # Initialize the distance matrix
    populate_distance_matrix(distance_matrix, string1, string2)  # Populate the distance matrix with costs
    return get_distance(distance_matrix)  # Return the final distance

def initialize_distance_matrix(string1, string2):
    rows = len(string1) + 1
    columns = len(string2) + 1
    return [[j if i == 0 else i if j == 0 else 0 for j in range(columns)] for i in range(rows)]

def populate_distance_matrix(distance_matrix, string1, string2):
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            set_distance(distance_matrix, i, j, cost)

def set_distance(distance_matrix, i, j, cost):
    distance_matrix[i][j] = calculate_minimum_distance(
        distance_matrix[i - 1][j - 1],
        distance_matrix[i][j - 1],
        distance_matrix[i - 1][j],
        cost
    )

def calculate_minimum_distance(a, b, c, cost):
    return min(a + cost, min(b + 1, c + 1))

def optimized_main(string1, string2):
    if not string1:
        return len(string2)
    
    previous_distance = [0] * (len(string1) + 1)  # Initialize previous distances array
    for j in range(1, len(string2) + 1):
        prev_substitution_cost = previous_distance[0]
        previous_distance[0] = j
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = previous_distance[i - 1] + 1
            substitution_cost = prev_substitution_cost if string1[i - 1] == string2[j - 1] else prev_substitution_cost + 1
            update_previous_distance(previous_distance, i, deletion_cost, insertion_cost, substitution_cost)
            prev_substitution_cost = previous_distance[i - 1]  # Update for next iteration

    return previous_distance[len(string1)]

def update_previous_distance(previous_distance, i, deletion_cost, insertion_cost, substitution_cost):
    previous_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))

def main():
    string1 = input()  # Read the first string from the input
    string2 = input()  # Read the second string from the input
    method = int(input())  # Read the method number from the input
    distance = 0
    if method == 1:
        distance = naive_main(string1, string2)  # Call the naive method if method number is 1
    else:
        distance = optimized_main(string1, string2)  # Call the optimized method if method number is other than 1
    print(f"The Levenshtein distance between the two strings is: {distance}")  # Print the result to the console

if __name__ == "__main__":
    main()

# <END-OF-CODE>
