
import sys

def searchRange(text, start, limit):
    middle = -1

    for i in range(start, limit):
        if text[i] != 'R':
            middle = i
            break

    end = limit

    for i in range(middle, limit):
        if text[i] != 'L':
            end = i
            break

    return start, middle, end

def answer():
    text = sys.stdin.readline().strip()
    limit = len(text)

    start = 0
    middle = 0
    end = 0
    firstPrinted = False

    for end in range(limit):
        start, middle, end = searchRange(text, start, limit)
        len1 = middle - start
        len2 = end - middle

        for i in range(start, middle-1):
            if firstPrinted:
                print(" ", end="")
            print("0", end="")
            firstPrinted = True

        count1 = (len1+1)//2 + len2//2
        count2 = len1//2 + (len2+1)//2

        if firstPrinted:
            print(" ", end="")
        print(count1, count2, end="")
        firstPrinted = True

        for i in range(middle + 1, end):
            if firstPrinted:
                print(" ", end="")
            print("0", end="")
            firstPrinted = True
        start = end
        firstPrinted = True
    print()

answer()

