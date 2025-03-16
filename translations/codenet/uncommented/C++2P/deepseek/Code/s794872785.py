def solve():
    maxsize = 0
    maxcnt = 0
    ans_num = None
    ans_num2 = None
    str_v = []
    
    while True:
        try:
            inp = input()
        except EOFError:
            break
        str_v.append(inp)
        if maxsize < len(inp):
            maxsize = len(inp)
            ans_num = len(str_v) - 1
       
    for i in range(len(str_v)):
        cnt = 0
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]:
                cnt += 1
        if maxcnt < cnt:
            maxcnt = cnt
            ans_num2 = i
    
    print(str_v[ans_num2], str_v[ans_num])

solve()

