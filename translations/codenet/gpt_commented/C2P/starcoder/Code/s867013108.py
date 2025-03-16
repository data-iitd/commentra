# <START-OF-CODE>

# 1. Input the number of days for which prices need to be calculated
n = int( input() )

# 2. Declare variables for number of days and loop index
i = 0

# 3. Declare arrays to store ticket prices for each day
nyuyoku_ticket = [ 0 for i in range(DAYS) ]
pool_ticket = [ 0 for i in range(DAYS) ]

# 4. Declare arrays to store the number of tickets used for each day
nyuyoku_member = [ 0 for i in range(DAYS) ]
pool_member = [ 0 for i in range(DAYS) ]

# 5. Declare arrays to store calculated prices
seiki_ryoukin = [ 0 for i in range(DAYS) ]
waribiki_ryoukin = [ 0 for i in range(DAYS) ]
saiyasune = [ 0 for i in range(DAYS) ]

# 6. Input ticket prices and the number of tickets used for the current day
for i in range(n):
	nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = map( int, input().split() )

# 7. Check if the discount condition for both tickets is met
for i in range(n):
	if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
		# Calculate the total price with discount
		seiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10
		saiyasune[i] = seiki_ryoukin[i] # Store the discounted price
	# Check if only the nyuyoku ticket discount condition is met
	elif nyuyoku_member[i] >= 5:
		# Calculate the total price without discount
		seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
		# Calculate the price with discount for pool tickets
		waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * 2 ) ) * 8 ) / 10
		# Compare and store the cheaper option
		if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
			saiyasune[i] = waribiki_ryoukin[i]
		else:
			saiyasune[i] = seiki_ryoukin[i]
	# Check if only the pool ticket discount condition is met
	elif pool_member[i] >= 2:
		# Calculate the total price without discount
		seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
		# Calculate the price with discount for nyuyoku tickets
		waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10
		# Compare and store the cheaper option
		if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
			saiyasune[i] = waribiki_ryoukin[i]
		else:
			saiyasune[i] = seiki_ryoukin[i]
	# If no discount conditions are met
	else:
		# Calculate the total price without discount
		seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
		# Calculate the price with discount for both tickets
		waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * 2 ) ) * 8 ) / 10
		# Compare and store the cheaper option
		if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
			saiyasune[i] = waribiki_ryoukin[i]
		else:
			saiyasune[i] = seiki_ryoukin[i]

# 8. Output the cheapest total price for each day
for i in range(n):
	print( saiyasune[i] )

# 