def main():
    # Declare variables to hold scores and lengths
    a, t, h = 0, 0, 0
    lt, lh, tt, hh, l = 0, 0, 0, 0, 0

    # Read the number of rounds
    a = int(input())

    # Loop through each round
    for i in range(a):
        # Read the names of the players for the current round
        taro, hana = input().split()

        # Get the lengths of the names
        lt = len(taro)
        lh = len(hana)

        # Determine the longer name length
        if lt > lh:
            l = lt  # Taro's name is longer
        else:
            l = lh  # Hana's name is longer or they are equal

        # Initialize scores for this round
        tt = 0
        hh = 0

        # Compare the names and update scores based on the comparison
        if taro > hana:
            t += 3  # Taro wins this round
        elif hana > taro:
            h += 3  # Hana wins this round
        elif taro == hana:
            t += 1  # Tie: both get 1 point
            h += 1  # Tie: both get 1 point

    # Output the final scores of Taro and Hana
    print(t, h)


# Call the main function
main()

