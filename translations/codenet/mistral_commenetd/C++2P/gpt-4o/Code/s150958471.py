# Declare two lists to store the number of passengers in each train and bus
train = [0, 0]
bus = [0, 0]

# Read the number of passengers in each train from the user
train[0], train[1] = map(int, input().split())

# Comment: Read the number of passengers in the first and second train from the user

# Read the number of passengers in each bus from the user
bus[0], bus[1] = map(int, input().split())

# Comment: Read the number of passengers in the first and second bus from the user

# Calculate the total number of passengers
total_passengers = min(train[0], train[1]) + min(bus[0], bus[1])
print(total_passengers)

# Comment: Output the total number of passengers in both train and bus

# <END-OF-CODE>
