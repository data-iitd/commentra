def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read input n and k
    n = int(data[0])
    k = int(data[1])
    
    # Read input array a
    a = list(map(int, data[2:n+2]))
    
    # Initialize light array based on initial a array
    light = [0] * (n + 2)
    for i in range(n):
        r = i - a[i]
        l = i + a[i]
        light[max(0, r)] += 1
        if l + 1 <= n:
            light[l + 1] -= 1
    
    # Perform k iterations
    for _ in range(k):
        # Initialize temporary array tmpa
        tmpa = a[:]
        sum_light = 0
        for j in range(n):
            sum_light += light[j]
            a[j] = sum_light
        
        # Update light array based on new a array
        for j in range(n):
            r = j - a[j]
            l = j + a[j]
            light[max(0, r)] -= 1
            if l + 1 <= n:
                light[l + 1] += 1
            
            r = j - a[j]
            l = j + a[j]
            light[max(0, r)] += 1
            if l + 1 <= n:
                light[l + 1] -= 1
        
        # Check if a array is the same for all elements except the first one,
        # and if the first element is equal to the size of the array
        is_same = all(a[j] == a[j + 1] for j in range(n - 1))
        if is_same and a[0] == n:
            break
    
    # Print out updated a array
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
