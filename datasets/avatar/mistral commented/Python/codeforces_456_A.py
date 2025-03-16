
n = int(input("Enter the number of tuples: "))
m = [ [ int(x) for x in input("Enter tuple {}: ".format(i+1)).split()] for i in range(n) ]
# We create a list 'm' of size 'n', where each element is a list of size 2, representing a tuple.

m.sort(reverse=True)
# We sort the list 'm' in descending order.

a = m[0]
# We initialize a variable 'a' with the first tuple in the sorted list.

for i in m[1:]:
    # We iterate through the remaining tuples in the list 'm' (starting from the second one).
    if i[1] > a[1]:
        print("Happy Alex")
        break
    # For each tuple 'i', we check if its second element (i[1]) is greater than the second element of the current tuple 'a'.
    a = i
# If we have gone through all the tuples without finding one whose second element is greater than the second element of the current tuple 'a', we print the message "Poor Alex".

else:
    print("Poor Alex")