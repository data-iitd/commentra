import collections

def run(s, t):
    # Count the frequency of each character in string s and sort the frequencies
    ss = sorted(list(collections.Counter(s).values()))
    
    # Count the frequency of each character in string t and sort the frequencies
    tt = sorted(list(collections.Counter(t).values()))
    
    # Compare the sorted frequency lists of both strings
    if ss == tt:
        return 'Yes'  # Return 'Yes' if the frequency distributions are the same
    else:
        return 'No'   # Return 'No' if the frequency distributions are different

def main():
    # Read input strings s and t from the user
    s = input()
    t = input()
    
    # Print the result of the run function which checks the character frequency
    print(run(s, t))

# Entry point of the program
if __name__ == '__main__':
    main()
