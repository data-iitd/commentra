def main():
    n = int(input())  # Read the number of rounds
    taro_scores = []
    hanako_scores = []

    # Loop through each round
    for _ in range(n):
        taro_word = input()  # Read Tarō's word
        hanako_word = input()  # Read Hanako's word
        if taro_word < hanako_word:
            hanako_scores.append(3)  # Increment Hanako's score by 3
        elif taro_word > hanako_word:
            taro_scores.append(3)  # Increment Tarō's score by 3
        else:
            taro_scores.append(1)  # Increment Tarō's score by 1
            hanako_scores.append(1)  # Increment Hanako's score by 1

    # Calculate the total scores
    taro_total = sum(taro_scores)
    hanako_total = sum(hanako_scores)

    # Print the final scores
    print(taro_total, hanako_total)


main()
