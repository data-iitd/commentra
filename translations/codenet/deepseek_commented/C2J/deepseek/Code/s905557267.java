public class ChainRemoval {

    // Function to return the smaller of two integers
    public static int min(int a, int b) {
        if (a <= b) {
            return a;
        }
        return b;
    }

    // Function to remove chains of four or more consecutive identical elements
    public static int Chain(int[] b, int n) {
        int[] a = new int[10000];
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }

        for (int i = 0; i < n - 3; i++) {
            if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
                int count = 0;
                int color = a[i];

                for (int j = i; a[j] == color; j++) {
                    a[j] = 0;
                    count++;
                }

                for (int j = i; j + count < n; j++) {
                    a[j] = a[j + count];
                    a[j + count] = 0;
                }

                return Chain(a, n);
            }
        }

        int count = 0;
        while (count < n && a[count] != 0) {
            count++;
        }

        return count;
    }

    // Main function to read input, process it, and print the result
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            if (n == 0) {
                break;
            }

            int[] a = new int[10000];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            int ans = n;

            for (int i = 0; i < n - 3; i++) {
                int[] count = new int[3];
                for (int j = i; j < i + 4; j++) {
                    if (a[j] - 1 >= 0) {
                        count[a[j] - 1]++;
                    }
                }

                int color = 0;
                for (int j = 0; j < 3; j++) {
                    if (count[j] >= 3) {
                        color = j + 1;
                        break;
                    }
                }

                if (color != 0) {
                    for (int j = i; j < i + 4; j++) {
                        int temp = a[j];
                        a[j] = color;
                        ans = min(ans, Chain(a, n));
                        a[j] = temp;
                    }
                }
            }

            System.out.println(ans);
        }
    }
}
