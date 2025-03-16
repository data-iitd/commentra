from collections import Counter
import sys

def main():
    s = input().strip()
    targ = list(s)
    map_counter = Counter(targ)
    
    ok = True
    for value in map_counter.values():
        if value != 2:
            ok = False
            break
    
    if ok and len(map_counter) == 2:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
