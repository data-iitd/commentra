public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // 1. Reading the input size `n`

        java.util.ArrayList<Long> a = new java.util.ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextLong()); // 2. Reading the array elements
        }

        java.util.ArrayList<Long> abs_a = new java.util.ArrayList<>(a); // 3. Creating a copy of the array with absolute values

        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) {
                abs_a.set(i, -abs_a.get(i));
            }
        }

        long ans = 0; // 4. Calculating the sum of absolute values
        long min = abs_a.get(0);
        for (long e : abs_a) {
            ans += e;
            if (min > e) {
                min = e;
            }
        }

        int num_negative = 0; // 5. Counting the number of negative elements
        for (long e : a) {
            if (e < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2 != 0) { // 6. Adjusting the sum based on the number of negative elements
            ans -= min * 2;
        }

        System.out.println(ans); // 7. Outputting the result
    }
}
