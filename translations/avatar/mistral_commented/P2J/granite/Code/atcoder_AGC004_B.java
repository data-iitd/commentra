
// Function to take input and convert it into list of integers
public static void main(String[] args) {
    // Take input of number of test cases and number of elements in each test case
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();

    // Initialize an empty list 'a' to store the given elements
    List<Integer> a = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        a.add(sc.nextInt());
    }

    // Initialize a 2D list 'b' of size n x n with null values
    List<List<Integer>> b = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        b.add(new ArrayList<>());
        for (int j = 0; j < n; j++) {
            b.get(i).add(null);
        }
    }

    // Iterate through each row of list 'a'
    for (int i = 0; i < n; i++) {
        // Initialize a variable'm' to store the minimum element in the current row
        int m = a.get(i);

        // Iterate through each column of list 'b'
        for (int j = 0; j < n; j++) {
            // Calculate the index 'k' based on the current row and column indices
            int k = i - j;

            // If the index 'k' is negative, add the size of list 'n' to make it positive
            if (k < 0) {
                k += n;
            }

            // Update the minimum value of'm' with the minimum value of 'a[k]'
            m = Math.min(m, a.get(k));

            // Update the corresponding cell in list 'b' with the minimum value of'm'
            b.get(j).set(i, m);
        }
    }

    // Initialize a variable'm' with a large value to keep track of the minimum sum
    long sum = Long.MAX_VALUE;

    // Iterate through each row of list 'b'
    for (int i = 0; i < n; i++) {
        // Calculate the sum of elements in the current row and add 'x * i' to it
        long sumRow = b.get(i).stream().mapToInt(Integer::intValue).sum() + (long) x * i;

        // Update the minimum value of'm' with the sum of the current row
        sum = Math.min(sum, sumRow);
    }

    // Print the minimum sum
    System.out.println(sum);
}

