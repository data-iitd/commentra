
import sys

def naive_main(string1, string2):
    distance_matrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                        min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))
    return distance_matrix[len(string1)][len(string2)]

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
            substitution_cost = (string1[i - 1] == string2[j - 1]) * prev_substitution_cost + (1 - (string1[i - 1] == string2[j - 1]))
            prev_substitution_cost = previous_distance[i]
            previous_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))
    return previous_distance[len(string1)]

if __name__ == '__main__':
    string1 = sys.stdin.readline().strip()
    string2 = sys.stdin.readline().strip()
    method = int(sys.stdin.readline().strip())
    distance = naive_main(string1, string2) if method == 1 else optimized_main(string1, string2)
    print("The Levenshtein distance between the two strings is: " + str(distance))

