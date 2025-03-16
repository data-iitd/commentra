def naive_main(string1, string2):
    distance_matrix = [[0] * (len(string2) + 1) for _ in range(len(string1) + 1)]
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
    return distance_matrix[len(string1)][len(string2)]


def optimized_main(string1, string2):
    if len(string1) == 0:
        return len(string2)
    previous_distance = list(range(len(string1) + 1))
    for j in range(1, len(string2) + 1):
        current_distance = [0] * (len(string1) + 1)
        current_distance[0] = j
        for i in range(1, len(string1) + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = current_distance[i - 1] + 1
            substitution_cost = 0 if string1[i - 1] == string2[j - 1] else 1
            prev_substitution_cost = previous_distance[i]
            current_distance[i] = min(deletion_cost, min(insertion_cost, substitution_cost))
        previous_distance = current_distance
    return previous_distance[len(string1)]


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    string1 = data[0]
    string2 = data[1]
    method = int(data[2])
    distance = 0
    if method == 1:
        distance = naive_main(string1, string2)
    else:
        distance = optimized_main(string1, string2)
    print("The Levenshtein distance between the two strings is: " + str(distance))


main()
