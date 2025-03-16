import sys

def main():
    scList = []
    for line in sys.stdin:
        try:
            scList.append(line.strip())
        except Exception as e:
            break
    
    numlist = scList[0].split()
    Sheep = int(numlist[0])
    Wolf = int(numlist[1])
    
    if Wolf >= Sheep:
        print("unsafe")
    else:
        print("safe")

if __name__ == "__main__":
    main()
