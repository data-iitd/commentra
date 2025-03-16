
def search_range(text, start, limit):
    middle = -1

    # Find the first index where the character is not 'R'
    for i in range(start, limit):
        if text[i]!= 'R':
            middle = i
            break

    end = limit

    # Find the first index after'middle' where the character is not 'L'
    for i in range(middle, limit):
        if text[i]!= 'L':
            end = i
            break

    # Return the start, middle, and end indices
    return start, middle, end

def answer():
    text = input()
    limit = len(text)

    start = 0
    middle = 0
    end = 0
    first_printed = False

    # Loop until the end of the text is reached
    while end < limit:
        # Get the range of indices for the current segment of 'R's and 'L's
        start, middle, end = search_range(text, start, limit)
        len1 = middle - start
        len2 = end - middle

        # Print '0's for the 'R' segment
        for i in range(start, middle-1):
            if first_printed:
                print(" ", end="")
            print("0", end="")
            first_printed = True

        # Calculate counts based on the lengths of the segments
        count1 = (len1+1)//2 + len2//2
        count2 = len1//2 + (len2+1)//2

        # Print the counts for the current segment
        if first_printed:
            print(" ", end="")
        print(count1, count2, end="")
        first_printed = True

        # Print '0's for the 'L' segment
        for i in range(middle + 1, end):
            if first_printed:
                print(" ", end="")
            print("0", end="")
            first_printed = True
        # Move to the next segment
        start = end
        first_printed = True

answer()

