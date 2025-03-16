DAYS = 365  # Maximum number of days

def main():
    n = int(input())
    nyuyoku_ticket = [0] * DAYS
    pool_ticket = [0] * DAYS
    nyuyoku_member = [0] * DAYS
    pool_member = [0] * DAYS
    seiki_ryoukin = [0] * DAYS
    waribiki_ryoukin = [0] * DAYS
    saiyasune = [0] * DAYS

    # Read the ticket prices and usage counts for each day
    for i in range(n):
        nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = map(int, input().split())

        # Check if the group qualifies for a discount
        if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
            # Calculate the cost with the maximum discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 // 10
            saiyasune[i] = seiki_ryoukin[i]
        elif nyuyoku_member[i] >= 5:
            # Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        elif pool_member[i] >= 2:
            # Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        else:
            # Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])

    # Output the cheapest total cost for each day
    for i in range(n):
        print(saiyasune[i])

if __name__ == "__main__":
    main()
