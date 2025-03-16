# Define the maximum number of days
DAYS = 365

def main():
    n = int(input())  # Input the number of days for which prices need to be calculated
    nyuyoku_ticket = [0] * DAYS  # Array to store ticket prices for each day
    pool_ticket = [0] * DAYS
    nyuyoku_member = [0] * DAYS
    pool_member = [0] * DAYS
    seiki_ryoukin = [0] * DAYS
    waribiki_ryoukin = [0] * DAYS
    saiyasune = [0] * DAYS

    for i in range(n):
        # Input ticket prices and the number of tickets used for the current day
        nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = map(int, input().split())

        # Check if the discount condition for both tickets is met
        if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
            # Calculate the total price with discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 // 10
            saiyasune[i] = seiki_ryoukin[i]  # Store the discounted price
        # Check if only the nyuyoku ticket discount condition is met
        elif nyuyoku_member[i] >= 5:
            # Calculate the total price without discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
            # Calculate the price with discount for pool tickets
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 // 10
            # Compare and store the cheaper option
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        # Check if only the pool ticket discount condition is met
        elif pool_member[i] >= 2:
            # Calculate the total price without discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
            # Calculate the price with discount for nyuyoku tickets
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 // 10
            # Compare and store the cheaper option
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        # If no discount conditions are met
        else:
            # Calculate the total price without discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
            # Calculate the price with discount for both tickets
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 // 10
            # Compare and store the cheaper option
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])

    # Output the cheapest total price for each day
    for i in range(n):
        print(saiyasune[i])

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
