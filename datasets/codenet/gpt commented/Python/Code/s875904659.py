def bubbleSort(cards):
    # Get the number of cards
    n = len(cards)
    
    # Outer loop for each card position
    for i in range(0, n):
        # Inner loop for comparing adjacent cards
        for j in range(n - 1, i, -1):
            # If the current card is less than the previous card, swap them
            if int(cards[j][1]) < int(cards[j - 1][1]):
                cards[j], cards[j - 1] = cards[j - 1], cards[j]
    
    # Print the sorted cards as a space-separated string
    print(" ".join(map(str, cards)))

def selectionSort(cards):
    # Get the number of cards
    n = len(cards)
    
    # Outer loop for each card position
    for i in range(0, n):
        # Assume the minimum is the current position
        mini = i
        
        # Inner loop to find the index of the minimum card
        for j in range(i, n):
            # Update mini if a smaller card is found
            if int(cards[j][1]) < int(cards[mini][1]):
                mini = j
        
        # If a new minimum is found, swap it with the current position
        if mini != i:
            cards[i], cards[mini] = cards[mini], cards[i]

    # Print the sorted cards as a space-separated string
    print(" ".join(map(str, cards)))

# Read the number of cards from input
n = int(input())

# Read the cards from input and split them into a list
cards = input().split(" ")

# Create a copy of the original cards for the selection sort
cards2 = list(cards)

# Sort the cards using bubble sort
bubbleSort(cards)

# Print "Stable" to indicate the sorting method used
print("Stable")

# Sort the copied cards using selection sort
selectionSort(cards2)

# Check if the output of selection sort is the same as bubble sort
if " ".join(map(str, cards2)) == " ".join(map(str, cards)):
    print("Stable")  # If they are the same, the sorting is stable
else:
    print("Not stable")  # If they differ, the sorting is not stable
