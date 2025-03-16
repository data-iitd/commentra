def is_leap(y):
    return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

def main():
    y = int(input())
    leap = is_leap(y)
    sum_days = 0
    
    i = y + 1
    while True:
        if is_leap(i):
            sum_days += 366
        else:
            sum_days += 365
        
        if sum_days % 7 == 0:
            if (is_leap(i) and leap) or (not is_leap(i) and not leap):
                print(i)
                return
            else:
                continue
        
        i += 1

if __name__ == "__main__":
    main()
