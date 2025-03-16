import sys
import re

def main():
    # Your code here!
    str = "13:20"
    r = re.compile(r"(\d+):(\d+)")
    print(r.findall(str))

if __name__ == "__main__":
    main()
