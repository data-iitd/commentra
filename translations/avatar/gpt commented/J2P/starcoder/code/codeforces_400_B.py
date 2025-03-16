import java.util.HashMap; 
import java.util.HashSet; 
import java.util.Scanner; 

def main():
    # Create a Scanner object to read input from the console
    sc = Scanner(System.in); 
    
    # Read the number of strings (n) and the number of queries (m)
    n = sc.nextInt(); 
    m = sc.nextInt(); 
    
    # Initialize an array to store the strings
    arrs = [0] * n; 
    
    # Read n strings from the input
    for i in range(n):
        arrs[i] = sc.next(); 
    
    # Initialize an array to store the lengths of segments between 'G' and 'S'
    length = [0] * n; 
    index = 0; 
    returnDex = 0; 
    
    # Iterate through each string to find the indices of 'G' and 'S'
    for tmp in arrs:
        dexG = tmp.indexOf("G"); # Find the index of 'G'
        dexS = tmp.indexOf("S"); # Find the index of 'S'
        
        # If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS):
            returnDex = -1; 
        
        # Calculate the length between 'G' and 'S' and store it in the length array
        length[index++] = dexS - dexG; 
    
    # Use a HashSet to store unique lengths
    set = HashSet(); 
    
    # Add each length to the HashSet to ensure uniqueness
    for len in length:
        set.add(len); 
    
    # Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1):
        print(returnDex); # Print -1 if 'G' is after 'S' in any string
    else:
        print(set.size()); # Print the number of unique lengths

if __name__ == "__main__":
    main()

