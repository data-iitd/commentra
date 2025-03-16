from datetime import time

def main():
    s = input().split(":")
    t = input().split(":")
    
    x = time(int(s[0]), int(s[1]))
    y = time(int(t[0]), int(t[1]))
    
    # Calculate the difference in hours and minutes
    hours_diff = x.hour - y.hour
    minutes_diff = x.minute - y.minute
    
    # Adjust if minutes_diff is negative
    if minutes_diff < 0:
        minutes_diff += 60
        hours_diff -= 1
    
    print(f"{hours_diff}:{minutes_diff:02d}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
