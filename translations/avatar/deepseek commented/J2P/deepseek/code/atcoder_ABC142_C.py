def main():
    # Step 1: Read the input value N, which represents the number of elements.
    N = int(input())

    # Step 2: Create a map idorder to store the elements and their corresponding positions.
    idorder = {}

    # Step 3: Read each element and store its value and position in the map.
    elements = list(map(int, input().split()))
    for i, A in enumerate(elements, start=1):
        idorder[A] = i

    # Step 4: Print the positions of the elements in the order they were read.
    positions = [str(idorder[i]) for i in range(1, N+1)]
    print(' '.join(positions))

if __name__ == "__main__":
    main()
