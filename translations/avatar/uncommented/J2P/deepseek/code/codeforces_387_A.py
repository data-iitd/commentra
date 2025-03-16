import time
from datetime import datetime

def main():
    s = input().split(":")
    t = input().split(":")
    x = datetime.strptime(s[0] + ":" + s[1], "%H:%M")
    y = datetime.strptime(t[0] + ":" + t[1], "%H:%M")
    diff = y - x
    print(diff)

if __name__ == "__main__":
    main()
