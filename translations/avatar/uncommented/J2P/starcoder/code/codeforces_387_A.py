
# <START-OF-CODE>
import datetime

def main():
    s = input().split(':')
    t = input().split(':')
    x = datetime.time(int(s[0]), int(s[1]))
    y = datetime.time(int(t[0]), int(t[1]))
    print(x - y)

if __name__ == '__main__':
    main()
# 