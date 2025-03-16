def bubbleSort(cards):
    # Get the number of cards
    n = len(cards)
    # Perform bubble sort
    for i in range(0, n):
        for j in range(n-1, i, -1):
            if int(cards[j][1]) < int(cards[j-1][1]):
                # Swap if the current card is smaller than the previous card
                cards[j], cards[j-1] = cards[j-1], cards[j]
    # Print the sorted cards
    print(" ".join(map(str, cards)))

def selectionSort(cards):
    # Get the number of cards
    n = len(cards)
    # Perform selection sort
    for i in range(0, n):
        mini = i
        for j in range(i, n):
            if int(cards[j][1]) < int(cards[mini][1]):
                mini = j
        if mini != i:
            # Swap if a smaller card is found
            cards[i], cards[mini] = cards[mini], cards[i]
    # Print the sorted cards
    print(" ".join(map(str, cards)))

# Read the number of cards and the list of cards from the input
n = int(input())
cards = input().split(" ")
cards2 = list(cards)

# Apply bubble sort and print the sorted list
bubbleSort(cards)
print("Stable")

# Apply selection sort and print the sorted list
selectionSort(cards2)

# Check if the sorted list from selection sort is the same as the sorted list from bubble sort
if " ".join(map(str, cards2)) == " ".join(map(str, cards)):
    print("Stable")
else:
    print("Not stable")
