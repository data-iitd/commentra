# Read four integers from the standard input
m1, d1, m2, d2 = map(int, input().split())

# Check if the first two months are equal or not
if m1 != m2:
    # If the months are not equal, print "1" to the standard output
    print("1")
else:
    # If the months are equal, print "0" to the standard output
    print("0")

# <END-OF-CODE>
