MAX_SIZE = 200000

# Declare the arrays and variables
a = [0] * MAX_SIZE
tmpa = [0] * MAX_SIZE
light = [0] * (MAX_SIZE + 10)

def main():
    # Declare variables for input
    n, k = map(int, input().split())

    # Read n integers from standard input and store them in array a
    a[:n] = list(map(int, input().split()))

    # Initialize the light array based on the initial positions of the lights
    for i in range(n):
        r = i - a[i]
        l = i + a[i]
        light[max(0, r)] += 1
        light[min(n, l + 1)] -= 1

    # Apply the lights k times
    for _ in range(k):
        sum_light = 0
        # Update array a based on the light array
        for j in range(n):
            tmpa[j] = a[j]
            sum_light += light[j]
            a[j] = sum_light

        # Adjust the light array based on the new state of array a
        for j in range(n):
            r = j - tmpa[j]
            l = j + tmpa[j]
            light[max(0, r)] -= 1
            light[min(n, l + 1)] += 1
            r = j - a[j]
            l = j + a[j]
            light[max(0, r)] += 1
            light[min(n, l + 1)] -= 1

        # Check if the array a has become stable
        is_same = all(a[i] == a[i + 1] for i in range(n - 1))

        # Check if the array a is stable and the first element is n
        if is_same and a[0] == n:
            break

    # Print the final state of array a
    print(" ".join(map(str, a[:n])))

main()
