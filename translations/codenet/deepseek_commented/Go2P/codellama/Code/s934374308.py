
import sys

def main():
    N, K, R, S, P = map(int, sys.stdin.readline().split())
    T = sys.stdin.readline().strip()

    # Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    dict = {"r": 0, "s": 0, "p": 0}
    # Initialize a string to store the current character
    char = ""
    # Initialize a boolean list to keep track of the availability of each choice for each player
    s = [True] * N
    # Initialize all elements of the list to true
    for i in range(N):
        s[i] = True
    # Create copies of the list for 'r', 'p'
    r = [True] * N
    p = [True] * N
    r[:] = s[:]
    p[:] = s[:]

    # Iterate over each character in the string T
    for i in range(len(T)):
        char = T[i]
        # Check if the current index is greater than or equal to K
        if i >= K:
            # Check if the last K characters are the same as the current character
            if char == T[i-K:i+1-K]:
                # Update the availability of the choice based on the current character
                if char == "s":
                    if s[i%K]:
                        s[i%K] = False
                        continue
                    else:
                        s[i%K] = True
                elif char == "r":
                    if r[i%K]:
                        r[i%K] = False
                        continue
                    else:
                        r[i%K] = True
                elif char == "p":
                    if p[i%K]:
                        p[i%K] = False
                        continue
                    else:
                        p[i%K] = True
            else:
                # Set the availability of the choice based on the current character
                if char == "s":
                    s[i%K] = True
                elif char == "r":
                    r[i%K] = True
                elif char == "p":
                    p[i%K] = True
        # Update the counts in the dictionary based on the current character
        if char == "s":
            dict["s"] = dict["s"] + 1
        elif char == "r":
            dict["r"] = dict["r"] + 1
        elif char == "p":
            dict["p"] = dict["p"] + 1

    # Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    res = P*dict["r"] + S*dict["p"] + R*dict["s"]
    # Print the result
    print(res)

if __name__ == "__main__":
    main()

