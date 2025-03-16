
import sys

def naive_main(string1, string2):
    # Initialize the distance matrix with dimensions (string1.length() + 1) x (string2.length() + 1)
    distance_matrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]

    # Fill the distance matrix based on the comparison of characters in the two strings
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            cost = 0 if string1[i - 1] == string2[j - 1] else 1
            distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                          min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))

    # Return the Levenshtein distance between the two strings
    return distance_matrix[len(string1)][len(string2)]

def optimized_main(string1, string2):
    # If the first string is empty, the distance is the length of the second string
    if len(string1) == 0:
        return len(string2)

    # Initialize the distance array with dimensions (string1.length() + 1)
    previous_distance = [0] * (len(string1) + 1)

    # Fill the distance array based on the comparison of characters in the two strings
    for j in range(1, len(string2) + 1):
        prev_substitution_cost = previous_distance[0]
        previous_distance[0] = j
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = previous_distance[i - 1] + 1
            substitution_cost = prev_substitution_cost + (1 if string1[i - 1]!= string2[j - 1] else 0)
            prev_substitution_cost = previous_distance[i]
            previous_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))

    # Return the Levenshtein distance between the two strings
    return previous_distance[len(string1)]

# Main method to read input, determine the method to use, and print the Levenshtein distance
def main():
    string1 = input()
    string2 = input()
    method = int(input())
    distance = naive_main(string1, string2) if method == 1 else optimized_main(string1, string2)
    print(f"The Levenshtein distance between the two strings is: {distance}")

if __name__ == "__main__":
    main()

