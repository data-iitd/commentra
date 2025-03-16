def main():
    s = input().strip()

    count = 0
    counter = []

    if s == "":
        return

    counter.append(0)
    
    for char in s:
        if char in "ACGT":
            count += 1
        else:
            counter.append(count)
            count = 0

    counter.append(count)
    counter.sort()
    print(counter[-1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
