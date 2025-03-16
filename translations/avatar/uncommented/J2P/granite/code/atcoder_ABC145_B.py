
import sys
def cout(str):
    print(str)
def main():
    cin = sys.stdin
    n = int(cin.readline())
    str = cin.readline().strip()
    a = ""
    for i in range(n // 2):
        a += str[i]
    if str == a + a:
        cout("Yes")
    else:
        cout("No")
if __name__ == "__main__":
    main()
