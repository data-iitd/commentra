
import sys

def naive_main(string1, string2):
    distance_matrix = initialize_distance_matrix(string1, string2)
    populate_distance_matrix(distance_matrix, string1, string2)
    return get_distance(distance_matrix)

def initialize_distance_matrix(string1, string2):
    rows = len(string1) + 1
    columns = len(string2) + 1
    distance_matrix = [[0 for _ in range(columns)] for _ in range(rows)]
    for i in range(1, rows):
        for j in range(1, columns):
            if i == 0:
                distance_matrix[i][j] = j
            elif j == 0:
                distance_matrix[i][j] = i
            else:
                distance_matrix[i][j] = 0
    return distance_matrix

def populate_distance_matrix(distance_matrix, string1, string2):
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 1 if string1[i - 1] != string2[j - 1] else 0
            set_distance(distance_matrix, i, j, cost)

def set_distance(distance_matrix, i, j, cost):
    distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost, min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))

def get_distance(distance_matrix):
    return distance_matrix[-1][-1]

def optimized_main(string1, string2):
    if not string1:
        return len(string2)
    previous_distance = [0] * (len(string1) + 1)
    for j in range(1, len(string2) + 1):
        prev_substitution_cost = previous_distance[0]
        previous_distance[0] = j
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = previous_distance[i - 1] + 1
            substitution_cost = prev_substitution_cost + (1 if string1[i - 1] != string2[j - 1] else 0)
            update_previous_distance(previous_distance, i, j, deletion_cost, insertion_cost, substitution_cost)
    return previous_distance[-1]

def update_previous_distance(previous_distance, i, j, deletion_cost, insertion_cost, substitution_cost):
    previous_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))

if __name__ == "__main__":
    string1 = sys.stdin.readline().strip()
    string2 = sys.stdin.readline().strip()
    method = int(sys.stdin.readline().strip())
    distance = naive_main(string1, string2) if method == 1 else optimized_main(string1, string2)
    print("The Levenshtein distance between the two strings is: " + str(distance))

