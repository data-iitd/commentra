def main():
    # Continuously read three integers until EOF is reached
    try:
        while True:
            c = list(map(int, input().split()))
            if len(c) != 3:
                break  # Exit if not exactly three integers are provided
            
            # Initialize a list to track the presence of cards
            card = [0] * 10
            count = 0  # Initialize count of valid card positions
            sum_cards = c[0] + c[1]  # Calculate the sum of the first two card values
            
            # Mark the positions of the cards in the card list
            for value in c:
                card[value - 1] = 1  # Set the position corresponding to the card value
            
            # Count how many card positions are available that do not exceed the total of 20
            for i in range(10):
                # Check if the card position is unoccupied and if adding it to the sum does not exceed 20
                if card[i] == 0 and sum_cards + (i + 1) <= 20:
                    count += 1  # Increment the count for each valid position
            
            # Determine if there are at least 4 valid positions available
            if count >= 4:
                print("YES")  # Output YES if there are enough valid positions
            else:
                print("NO")  # Output NO if there are not enough valid positions
    except EOFError:
        pass  # Handle end of input

if __name__ == "__main__":
    main()

# <END-OF-CODE>
