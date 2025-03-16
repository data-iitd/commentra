def main():
    a = int(input())
    t = 0
    h = 0

    for _ in range(a):
        taro, hana = input().split()
        
        if taro > hana:
            t += 3
        elif hana > taro:
            h += 3
        else:
            t += 1
            h += 1

    print(t, h)

main()
