import sys 

def main(): 
    # Read the number of strings
    n = int(sys.stdin.readline()) 
    ss = [] 
    
    # Read each string and convert it to a character array
    for i in range(n): 
        s = sys.stdin.readline().strip() 
        ss.append(list(s)) 
    
    # Read the character array to be modified
    cc = list(sys.stdin.readline().strip()) 
    m = len(cc) 
    
    # Read the character to be replaced
    c = sys.stdin.readline().strip()[0] 
    c_ = c.upper() 
    
    # Determine the character to replace with
    a = 'b' if c == 'a' else 'a' 
    a_ = a.upper() 
    
    # Array to track positions that can be marked as lucky
    lucky = [False] * m 
    
    # Loop through each position in the character array
    for j in range(m): 
        for i in range(n): 
            l = len(ss[i]) 
            # Check if the substring matches and mark lucky positions
            if m - j >= l and ss[i] == cc[j:j + l]: 
                for h in range(l): 
                    lucky[j + h] = True 
    
    # Replace characters in the original array based on lucky positions
    for j in range(m): 
        if lucky[j]: 
            # Replace with the determined character based on case
            if cc[j].islower(): 
                cc[j] = a if cc[j] == c else c_ 
            else: 
                cc[j] = a_ if cc[j] == c else c_ 
    
    # Print the modified character array
    print(''.join(cc)) 


if __name__ == '__main__': 
    main() 

