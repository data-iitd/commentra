

n = int ( input ( ) ) ; # Reading the number of test cases

FfriendPerDay = [ 0 ] * 367 ; # Initializing a list of size 367 to store the number of friends of type F for each day
MfriendPerDay = [ 0 ] * 367 ; # Initializing a list of size 367 to store the number of friends of type M for each day
answer = 0 ; # Initializing an integer variable to store the maximum difference between the number of friends of type F and M for any day

for i in range ( n ) : # Iterating through each test case
    c = input ( ) [ 0 ] ; # Reading the character representing the gender of the friend
    a = int ( input ( ) ) ; # Reading the starting day of the range
    b = int ( input ( ) ) ; # Reading the ending day of the range

    for j in range ( a, b + 1 ) : # Iterating through each day in the range
        if ( c == 'M' ) MfriendPerDay [ j ] += 1 ; # Incrementing the counter in the MfriendPerDay list for the day if the friend is of type M
        else FfriendPerDay [ j ] += 1 ; # Incrementing the counter in the FfriendPerDay list for the day if the friend is of type F

        if ( MfriendPerDay [ j ] < FfriendPerDay [ j ] ) : # Checking if the number of friends of type M is less than the number of friends of type F for the current day
            if ( MfriendPerDay [ j ] > answer ) answer = MfriendPerDay [ j ] ; # Updating the value of answer if the current difference is greater than the previous maximum difference
        else : # Repeating the same check for the number of friends of type F
            if ( FfriendPerDay [ j ] > answer ) answer = FfriendPerDay [ j ] ;

print ( answer * 2 ) ; # Printing the answer, which is twice the maximum difference between the number of friends of type F and M for any day.

