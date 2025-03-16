public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize empty lists to store low and high values
        List<Integer> low = new ArrayList<>();
        List<Integer> high = new ArrayList<>();

        // Read low and high values for each test case and add to respective lists
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            low.add(a);
            high.add(b);
        }

        // Sort the low and high lists in ascending order
        Collections.sort(low);
        Collections.sort(high);

        // Check if the number of test cases is odd
        if (n % 2 == 1) {
            // If it is odd, print the difference between the middle low and middle high values
            System.out.println(high.get((n + 1) / 2 - 1) - low.get((n + 1) / 2 - 1) + 1);
        } else {
            // If it is even, calculate the average of middle low and middle high values
            double hh = (high.get(n / 2 - 1) + high.get(n / 2)) / 2.0;
            double ll = (low.get(n / 2 - 1) + low.get(n / 2)) / 2.0;

            // Print the result which is twice the difference between the averages
            System.out.println(Math.round((hh - ll) * 2) + 1);
        }
    }
}
