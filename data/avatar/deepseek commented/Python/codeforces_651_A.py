# Step 1: Take two integers as input and assign them to x and y.
x , y = map ( int , input ( ).split ( ) )

# Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
print ( max ( x + y - 3 + ( ( y - x ) % 3 > 0 ) , 0 ) )

# Step 3: Define lambda functions for taking different types of inputs.
num_inp = lambda : int ( input ( ) )
arr_inp = lambda : list ( map ( int , input ( ).split ( ) ) )
sp_inp = lambda : map ( int , input ( ).split ( ) )
str_inp = lambda : input ( )
