DAYS = 365  # Maximum number of days

def main():
    n = int(input())  # Number of days for which prices need to be calculated
    saiyasune = []  # List to store the calculated prices

    for _ in range(n):
        nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member = map(int, input().split())

        # Check if the discount condition for both tickets is met
        if nyuyoku_member >= 5 and pool_member >= 2:
            # Calculate the total price with discount
            seiki_ryoukin = ((nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)) * 0.8
            saiyasune.append(int(seiki_ryoukin))
        # Check if only the nyuyoku ticket discount condition is met
        elif nyuyoku_member >= 5:
            # Calculate the total price without discount
            seiki_ryoukin = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            # Calculate the price with discount for pool tickets
            waribiki_ryoukin = ((nyuyoku_ticket * nyuyoku_member) + (pool_ticket * 2)) * 0.8
            # Compare and store the cheaper option
            saiyasune.append(min(seiki_ryoukin, int(waribiki_ryoukin)))
        # Check if only the pool ticket discount condition is met
        elif pool_member >= 2:
            # Calculate the total price without discount
            seiki_ryoukin = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            # Calculate the price with discount for nyuyoku tickets
            waribiki_ryoukin = ((nyuyoku_ticket * 5) + (pool_ticket * pool_member)) * 0.8
            # Compare and store the cheaper option
            saiyasune.append(min(seiki_ryoukin, int(waribiki_ryoukin)))
        # If no discount conditions are met
        else:
            # Calculate the total price without discount
            seiki_ryoukin = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            # Calculate the price with discount for both tickets
            waribiki_ryoukin = ((nyuyoku_ticket * 5) + (pool_ticket * 2)) * 0.8
            # Compare and store the cheaper option
            saiyasune.append(min(seiki_ryoukin, int(waribiki_ryoukin)))

    # Output the cheapest total price for each day
    for price in saiyasune:
        print(price)

if __name__ == "__main__":
    main()
