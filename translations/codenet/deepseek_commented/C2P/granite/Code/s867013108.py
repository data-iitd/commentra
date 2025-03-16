
# Read the number of days
n = int(input())

# Initialize lists to store ticket prices, usage counts, and final costs for each day
nyuyoku_ticket = []
pool_ticket = []
nyuyoku_member = []
pool_member = []
seiki_ryoukin = []
waribiki_ryoukin = []
saiyasune = []

# Loop through each day
for i in range(n):
    # Read the ticket prices and usage counts for the day
    nyuyoku_ticket.append(int(input()))
    pool_ticket.append(int(input()))
    nyuyoku_member.append(int(input()))
    pool_member.append(int(input()))

    # Check if the group qualifies for a discount
    if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
        # Calculate the cost with the maximum discount
        seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 / 10)
        saiyasune.append(seiki_ryoukin[i])
    elif nyuyoku_member[i] >= 5:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 / 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])
    elif pool_member[i] >= 2:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append((nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 / 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])
    else:
        # Calculate the normal cost and the discounted cost if applicable
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append((nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 / 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])

# Output the cheapest total cost for each day
for i in range(n):
    print(saiyasune[i])

