import sys

def main():
    sec = int(input().strip())
    per_num = int(input().strip())
    max_sec = int(input().strip()) + 0.5
    ans_num = 0
    i = sec
    while i < max_sec:
        ans_num += per_num
        i += sec
    print(ans_num)

if __name__ == "__main__":
    main()
