import sys

INF = 0x5fffffff
a = [0] * 100002  # array to store input numbers
b = [0] * 100002  # array to store the minimum number of steps to reach from the start or end

# function to read an integer from the input
def getint():
    global p
    n = 0
    if p[0] == '-':  # check if the number is negative
        p = p[1:]
        while p and p[0].isdigit():
            n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)  # read the digits
            p = p[1:]
        return -n  # return the negative number
    while p and p[0].isdigit():
        n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)  # read the digits
        p = p[1:]
    return n  # return the number

def main():
    global p
    buf = sys.stdin.read().splitlines()
    p = buf[0]  # first line for number of elements
    w = getint()  # read the number of elements in the array 'a'

    p = buf[1]  # second line for the elements of array 'a'
    ans = 0
    f = 0
    close = 0

    for i in range(1, w + 1):
        k = getint()  # read an element of array 'a'
        if k == 0:
            f |= 1  # set flag 'f' if there is an element with zero value
            continue

        if k < 0:
            if f < 0 or close - (i - f) > -k:
                close = -k
                f = i
            if f < 0:
                f = -2

        ans += k  # update the 'ans' variable

    if ans == 0 or not (f & 1):
        print("0")  # print 0 if the condition is true
        return

    if not (f & 2):
        print(ans)  # print the answer
        return

    for i in range(w, 0, -1):
        if a[i] == 0:
            close = INF
            f = -1
            continue

        if a[i] < 0:
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i
        else:
            b[i] = INF
            if f >= 0:
                k = close - (f - i)  # calculate the minimum number of steps to reach from the start to the current index
                if k < 0:
                    k = 0  # if the number is negative, set it to zero
                b[i] = k  # update the 'b' array

    for i in range(1, w + 1):
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]

    print(ans)  # print the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
