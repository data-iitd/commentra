
a , b , t = map ( int , input ( ).split ( ) )
# Taking three inputs from the user: a, b, and t
cookie = 0
# Initializing the cookie count to 0
time = a
# Setting the initial time to the value of a
while time <= t + 0.5 :
    # The loop continues as long as time is less than or equal to t + 0.5
    cookie += b
    # Incrementing the cookie count by b
    time += a
    # Incrementing the time by a
print ( cookie )
# Printing the final cookie count after the loop finishes

