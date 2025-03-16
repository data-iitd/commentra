def str2list(s):
    values = list(map(int, s.split()))
    return {i: values[i] for i in range(len(values))}

def main():
    n = int(input().strip())
    v_str = input().strip()
    v_list = str2list(v_str)
    c_str = input().strip()
    c_list = str2list(c_str)
    max_profit = 0
    for i in range(n):
        profit = v_list[i] - c_list[i]
        if profit > 0:
            max_profit += profit
    print(max_profit)

if __name__ == "__main__":
    main()
