#######
# Code
#######

// Define input variables
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
int K = scanner.nextInt();

// Initialize list 'A' with input values
List<Integer> A = new ArrayList<>();
for (int i = 0; i < N; i++) {
    A.add(scanner.nextInt());
}

// Sort list 'A' in ascending order
Collections.sort(A);

// Initialize variables for binary search
int ll = -1000000000 - 1;
int rr = 1000000000 + 1;

// Perform binary search until 'll + 1' is less than 'rr'
while (ll + 1 < rr) {
    // Calculate mid value for binary search
    int x = (ll + rr) / 2;

    // Initialize variable 'tot' to store total count of elements
    int tot = 0;

    // Iterate through list 'A' and calculate total count of elements that satisfy the condition
    for (int i = 0; i < N; i++) {
        // Check if current element 'A[i]' is negative
        if (A.get(i) < 0) {
            // Initialize variables 'l' and 'r' for binary search in the range of indices
            int l = 0;
            int r = N;

            // Perform binary search to find the index 'c' such that A[i] * A[c] >= x
            while (l + 1 < r) {
                int c = (l + r) / 2;
                if (A.get(i) * A.get(c) < x) {
                    l = c;
                } else {
                    r = c;
                }
            }

            // Update 'tot' with the number of elements greater than 'c'
            tot += N - r;
        }

        // If current element 'A[i]' is positive, perform similar binary search and update 'tot' accordingly
        else {
            int l = 0;
            int r = N;
            while (l + 1 < r) {
                int c = (l + r) / 2;
                if (A.get(i) * A.get(c) < x) {
                    l = c;
                } else {
                    r = c;
                }
            }
            tot += r;
        }

        // Update 'tot' with the contribution of current element 'A[i]'
        if (A.get(i) * A.get(i) < x) {
            tot -= 1;
        }
    }

    // Check if total count of elements is greater than or equal to 'K'
    if (tot >= K) {
        // Update 'll' if condition is satisfied
        ll = x;
    } else {
        // Update 'rr' if condition is not satisfied
        rr = x;
    }
}

// Print the final answer
System.out.println(ll);

