def main():
    import sys
    
    # Initialize list for input
    str_list = []
    
    # Read input strings into the list
    for _ in range(4):
        str_list.append(input().strip())
    
    yes = 0
    
    # Compare characters in the list
    for u in range(3):
        for i in range(3):
            if ((str_list[u][i] == str_list[u][i + 1] and 
                 (str_list[u + 1][i] == str_list[u][i] or str_list[u + 1][i + 1] == str_list[u][i])) or 
                (str_list[u + 1][i] == str_list[u + 1][i + 1] and 
                 (str_list[u][i] == str_list[u + 1][i] or str_list[u][i + 1] == str_list[u + 1][i]))):
                yes = 1
                print("YES")
                break
        if yes == 1:
            break
    
    if yes == 0:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
