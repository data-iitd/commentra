import numpy as np

class LevenshteinDistance:
    @staticmethod
    def naive_main(string1, string2):
        distance_matrix = np.zeros((len(string1) + 1, len(string2) + 1), dtype=int)

        for i in range(len(string1) + 1):
            for j in range(len(string2) + 1):
                if i == 0:
                    distance_matrix[i][j] = j
                elif j == 0:
                    distance_matrix[i][j] = i
                else:
                    cost = 0 if string1[i - 1] == string2[j - 1] else 1
                    distance_matrix[i][j] = min(
                        distance_matrix[i - 1][j] + 1,      # Deletion
                        distance_matrix[i][j - 1] + 1,      # Insertion
                        distance_matrix[i - 1][j - 1] + cost  # Substitution
                    )

        return distance_matrix[len(string1)][len(string2)]

    @staticmethod
    def optimized_main(string1, string2):
        if not string1:
            return len(string2)

        previous_distance = list(range(len(string1) + 1))

        for j in range(1, len(string2) + 1):
            prev_substitution_cost = previous_distance[0]
            previous_distance[0] = j

            for i in range(1, len(string1) + 1):
                deletion_cost = previous_distance[i] + 1
                insertion_cost = previous_distance[i - 1] + 1
                substitution_cost = prev_substitution_cost if string1[i - 1] == string2[j - 1] else prev_substitution_cost + 1
                prev_substitution_cost = previous_distance[i]
                previous_distance[i] = min(deletion_cost, insertion_cost, substitution_cost)

        return previous_distance[len(string1)]

if __name__ == "__main__":
    string1 = input()
    string2 = input()
    method = int(input())

    if method == 1:
        distance = LevenshteinDistance.naive_main(string1, string2)
    else:
        distance = LevenshteinDistance.optimized_main(string1, string2)

    print(f"The Levenshtein distance between the two strings is: {distance}")

# <END-OF-CODE>
