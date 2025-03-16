def str2list(s):
    v_arr_str = s.split(" ")
    ret = {}
    for key, val in enumerate(v_arr_str):
        ret[key] = int(val)
    return ret

def main():
    n = int(input())
    v_str = input()
    v_list = str2list(v_str)
    c_str = input()
    c_list = str2list(c_str)
    
    max_profit = 0
    for i in range(n):
        profit = v_list[i] - c_list[i]
        if profit > 0:
            max_profit += profit
            
    print(max_profit)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
