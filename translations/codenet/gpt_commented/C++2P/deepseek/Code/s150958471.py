# Input the arrival times for the train
train = list(map(int, input().split()))
# Input the arrival times for the bus
bus = list(map(int, input().split()))

# Calculate the minimum arrival time between the two times for train and bus,
# and output the total minimum arrival time
min_train = min(train)
min_bus = min(bus)
total_min_arrival_time = min_train + min_bus

# Output the total minimum arrival time
print(total_min_arrival_time)

# End-of-code
