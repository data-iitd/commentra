#include <stdio.h>
#include <stdlib.h>

#define INF 0x5fffffff
a = [0] * 100002 // array to store input numbers
b = [0] * 100002 // array to store the minimum number of steps to reach from the start or end

buf = "" // buffer to read input from stdin

# function to read an integer from the input buffer
def getint():
    n = 0
    if buf[0] == '-': # check if the number is negative
        buf = buf[1:]
        while buf[0] >= '0': n = (n<<3) + (n<<1) + ord(buf[0]) - 48 # read the digits
        return -n # return the negative number
    while buf[0] >= '0': n = (n<<3) + (n<<1) + ord(buf[0]) - 48 # read the digits
    return n # return the number

def main():
    global w, i, k, f, close, ans # declare variables

    # read the number of elements in the array 'a'
    w = getint()

    # read the elements of array 'a'
    buf = input()
    for ans in range(0, w):
        # read an element of array 'a'
        k = getint()
        buf = buf[1:]

        # check if the current element is zero
        if not k:
            f |= 1 # set flag 'f' if there is an element with zero value
            continue

        # if the current element is negative, update the 'close' variable
        # and set flag 'f' to -2 if all elements are negative
        if k < 0:
            if f < 0 or close - (i-f) > -k: close = -k, f = i
            if f < 0: f = -2

        # update the 'ans' variable
        ans += k

    # check if the sum of all positive elements is zero or if flag 'f' is 1
    if not ans or not (f & 1):
        print(0) # print 0 if the condition is true
        return 0

    # if all elements are not negative, calculate the minimum number of steps to reach from the start or end
    if not (f & 2):
        print(ans) # print the answer
        return 0

    # initialize variables for the second loop
    for close in range(0, w):
        # read an element of array 'a'
        if not a[i]:
            close = INF
            f = -1
            continue

        if a[i] < 0:
            # if the current element is negative, update the 'close' variable
            # and set flag 'f' to the index of the current element
            if f < 0 or close - (f-i) > -a[i]: close = -a[i], f = i
        else:
            # if the current element is positive, update the 'b' array
            b[i] = INF
            if f >= 0:
                k = close - (f-i) # calculate the minimum number of steps to reach from the start to the current index
                if k < 0: k = 0 # if the number is negative, set it to zero
                b[i] = k # update the 'b' array

    # initialize variables for the third loop
    for close in range(0, w):
        # read an element of array 'a'
        if a[i] > 0:
            # if the current element is positive, update the 'ans' variable
            if b[i] > a[i]: ans += a[i]
            else:             ans += b[i]

    # print the answer
    print(ans)
    return 0

if __name__ == "__main__":
    main()
