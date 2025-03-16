class Main:
    def run(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the number of switches (N) and the number of lights (M)
        index = 0
        N = int(data[index])
        index += 1
        M = int(data[index])
        index += 1

        # Initialize a list of integers with N elements, all set to 0
        a = [0] * N

        # Read M groups of integers, where each group represents a switch and its corresponding states
        for i in range(M):
            k = int(data[index])
            index += 1
            for j in range(k):
                s = int(data[index]) - 1  # Convert to 0-based index
                index += 1
                a[s] |= (1 << i)

        # Read the final state of each light
        p = 0
        for i in range(M):
            x = int(data[index])
            index += 1
            p |= (x << i)

        # Calculate the number of possible configurations of switch states that match the final state of the lights
        ans = 0
        for s in range(1 << N):
            t = 0
            for i in range(N):
                if (s >> i) & 1:
                    t ^= a[i]
            if p == t:
                ans += 1

        # Print the result
        print(ans)

if __name__ == "__main__":
    main = Main()
    main.run()

# <END-OF-CODE>
