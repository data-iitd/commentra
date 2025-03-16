def main():
    line = input()
    list = line.split()
    x = int(list[0])
    a = int(list[1])
    y = int(list[2])
    h = "NO"
    
    if x in (5, 7) or a in (5, 7) or y in (5, 7):
        if x + y + a == 17:
            h = "YES"
    
    print(h)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
