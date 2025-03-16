def main():
    str_input, p = input().split()
    
    tmp = str_input
    str_combined = str_input + tmp
    
    slen = len(str_combined)
    plen = len(p)
    
    flag = False
    for i in range(slen - plen):
        if str_combined[i:i + plen] == p:
            flag = True
            break
    
    if flag:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
