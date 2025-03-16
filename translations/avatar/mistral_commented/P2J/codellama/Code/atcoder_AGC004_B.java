public class Main {
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

        // Initialize a 2D list 'b' of size n x n with None values
        List<List<Integer>> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(null);
            }
            b.add(row);
        }

        // Iterate through each row of list 'a'
        for (int i = 0; i < n; i++) {
            // Initialize a variable 'm' to store the minimum element in the current row
            int m = a.get(i);

            // Iterate through each column of list 'b'
            for (int j = 0; j < n; j++) {
                // Calculate the index 'k' based on the current row and column indices
                int k = i - j;

                // If the index 'k' is negative, add the size of list 'n' to make it positive
                if (k < 0) {
                    k += n;
                }

                // Update the minimum value of 'm' with the minimum value of 'a[k]'
                m = Math.min(m, a.get(k));

                // Update the corresponding cell in list 'b' with the minimum value of 'm'
                b.get(j).set(i, m);
            }
        }

        // Initialize a variable 'm' with a large value to keep track of the minimum sum
        int m = 1000000000;

        // Iterate through each row of list 'b'
        for (int i = 0; i < n; i++) {
            // Calculate the sum of elements in the current row and add 'x * i' to it
            int sum_row = b.get(i).stream().mapToInt(Integer::intValue).sum() + x * i;

            // Update the minimum value of 'm' with the sum of the current row
            m = Math.min(m, sum_row);
        }

        // Print the minimum sum
        System.out.println(m);
    }
}

