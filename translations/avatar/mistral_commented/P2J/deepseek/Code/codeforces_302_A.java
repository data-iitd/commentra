public class Main {
    public static void main(String[] args) {
        // Define the number of strings n and the number of operations m
        int n, m;
        String[] nm = System.console().readLine().split(" ");
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);

        // Calculate the number of '-' symbols in the input string
        String inputString = System.console().readLine();
        int sa = 0;
        for (char c : inputString.toCharArray()) {
            if (c == '-') {
                sa++;
            }
        }

        // Ensure the number of '-' symbols is valid
        sa = Math.min(n - sa, sa);

        // Initialize an empty list 'ss' to store the results of each operation
        StringBuilder ss = new StringBuilder();

        // Perform each operation as described in the problem statement
        for (int i = 0; i < m; i++) {
            // Read two integers a and b from the input
            String[] ab = System.console().readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);

            // Calculate the difference between b and a
            b -= a;

            // Check if the difference is valid based on the number of '-' symbols
            if (b % 2 == 0 || b > sa * 2) {
                // If the difference is valid, add '1' to the result list 'ss'
                ss.append("1\n");
            } else {
                // If the difference is not valid, add '0' to the result list 'ss'
                ss.append("0\n");
            }
        }

        // Print the final result by joining all the strings in the 'ss' list with an empty string as separator
        System.out.println(ss.toString());
    }
}
