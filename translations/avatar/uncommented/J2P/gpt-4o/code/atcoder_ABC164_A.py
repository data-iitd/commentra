def main():
    import sys
    
    sc_list = []
    
    # Read input until EOF
    for line in sys.stdin:
        sc_list.append(line.strip())
    
    numlist = sc_list[0].split(" ")
    sheep = int(numlist[0])
    wolve = int(numlist[1])
    
    if wolve >= sheep:
        print("unsafe")
    else:
        print("safe")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
