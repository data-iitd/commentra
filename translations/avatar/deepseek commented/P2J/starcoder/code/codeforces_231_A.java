// Take an integer input `n` which represents the number of lists to be provided as input.
int n = Integer.parseInt(sc.nextLine());

// Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
int c = 0;

// Loop `n` times to process each list of integers.
for (int i = 0; i < n; i++) {
    // Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
    String[] l1 = sc.nextLine().split(" ");
    int[] l1 = new int[l1.length];
    for (int j = 0; j < l1.length; j++) {
        l1[j] = Integer.parseInt(l1[j]);
    }

    // Calculate the sum of the elements in `l1`.
    // If the sum is greater than 1, increment the counter `c` by 1.
    if (Arrays.stream(l1).sum() > 1) {
        c++;
    }
}

// After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
System.out.println(c);

