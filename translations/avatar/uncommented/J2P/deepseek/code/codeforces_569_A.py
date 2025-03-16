import sys

def main():
    T = int(sys.stdin.readline().strip())
    S = int(sys.stdin.readline().strip())
    q = int(sys.stdin.readline().strip())
    previous = S
    answer = 0
    while previous < T:
        answer += 1
        previous *= q
    print(answer)

if __name__ == "__main__":
    main()
