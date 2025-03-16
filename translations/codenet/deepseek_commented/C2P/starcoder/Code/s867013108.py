# Maximum number of days
DAYS = 365

# Prices of tickets for each day
nyuyoku_ticket = [0] * DAYS
pool_ticket = [0] * DAYS

# Number of tickets each member will use for each day
nyuyoku_member = [0] * DAYS
pool_member = [0] * DAYS

# Costs and final costs for each day
seiki_ryoukin = [0] * DAYS
waribiki_ryoukin = [0] * DAYS
saiyasune = [0] * DAYS

# Read the number of days
n = int(input())

# Loop through each day
for i in range(n):
    # Read the ticket prices and usage counts for the day
    nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = map(int, input().split())

    # Check if the group qualifies for a discount
    if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
        # Calculate the cost with the maximum discount
        seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 / 10
        saiyasune[i] = seiki_ryoukin[i]
    elif nyuyoku_member[i] >= 5:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
        waribiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 / 10
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune[i] = waribiki_ryoukin[i]
        else:
            saiyasune[i] = seiki_ryoukin[i]
    elif pool_member[i] >= 2:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
        waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 / 10
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune[i] = waribiki_ryoukin[i]
        else:
            saiyasune[i] = seiki_ryoukin[i]
    else:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
        waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 / 10
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune[i] = waribiki_ryoukin[i]
        else:
            saiyasune[i] = seiki_ryoukin[i]

# Output the cheapest total cost for each day
for i in range(n):
    print(saiyasune[i])

# 