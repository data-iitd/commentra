#ABC111C
import collections

def main():
    # Step 3: Reading input
    n = int(input())  # Read the number of elements
    v = list(map(int, input().split()))  # Read the list of integers

    # Step 4: Separating even and odd indexed elements
    ve = []  # List to store elements at even indices
    vo = []  # List to store elements at odd indices
    for i in range(n // 2):
        ve.append(v[2 * i])  # Append element at even index
        vo.append(v[2 * i + 1])  # Append element at odd index

    # Step 5: Counting the frequency of elements
    ce = collections.Counter(ve)  # Counter for even indexed elements
    co = collections.Counter(vo)  # Counter for odd indexed elements

    # Step 6: Calculating the answer
    ans = n  # Initialize ans with the value of n
    if ce.most_common()[0][0] != co.most_common()[0][0]:
        # Step 7: Update ans if the most common elements are different
        ans = n - ce.most_common()[0][1] - co.most_common()[0][1]
    elif len(ce) == 1 and len(co) == 1:
        # Step 8: Update ans if there is only one unique element in each list
        ans = n - ce.most_common()[0][1]
    elif len(ce) == 1:
        # Step 9: Update ans if there is only one unique element in ve
        ans = n - ce.most_common()[0][1] - co.most_common()[1][1]
    elif len(co) == 1:
        # Step 10: Update ans if there is only one unique element in vo
        ans = n - ce.most_common()[1][1] - co.most_common()[0][1]
    else:
        # Step 11: Update ans if there are multiple unique elements in both lists
        ans = min(n - ce.most_common()[0][1] - co.most_common()[1][1], n - ce.most_common()[1][1] - co.most_common()[0][1])

    # Step 7: Printing the result
    print(ans)  # Print the final value of ans

if __name__ == "__main__":
    # Step 8: Running the main function
    main()
