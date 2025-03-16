# Read the number of passengers in each train from the user
train = list(map(int, input().split()))

# Read the number of passengers in each bus from the user
bus = list(map(int, input().split()))

# Calculate the total number of passengers
total_passengers = min(train[0], train[1]) + min(bus[0], bus[1])

# Output the total number of passengers in both train and bus
print(total_passengers)

