
# Read the number of passengers in each train from the user
train_1 = int(input())
train_2 = int(input())

# Read the number of passengers in each bus from the user
bus_1 = int(input())
bus_2 = int(input())

# Calculate the total number of passengers
total_passengers = min(train_1, train_2) + min(bus_1, bus_2)

# Output the total number of passengers in both train and bus
print(total_passengers)

