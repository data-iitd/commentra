import sys

def main():
    # Reading the number of seconds from standard input
    sec = int(sys.stdin.readline().strip())
    
    # Reading the number of items per interval from standard input
    per_num = int(sys.stdin.readline().strip())
    
    # Reading the maximum time limit, adding 0.5 to ensure proper rounding
    max_sec = float(sys.stdin.readline().strip()) + 0.5
    
    # Initializing a variable to hold the total count of items
    ans_num = 0
    
    # Looping from 'sec' to 'max_sec' in increments of 'sec'
    i = sec
    while i < max_sec:
        # Accumulating the total number of items produced
        ans_num += per_num
        i += sec
    
    # Outputting the total number of items produced
    print(ans_num)

if __name__ == "__main__":
    main()
