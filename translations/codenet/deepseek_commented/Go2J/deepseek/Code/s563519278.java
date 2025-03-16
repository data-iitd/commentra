public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt(); // Step 1: Reading the number of elements (N)
        int[] v = new int[N]; // Step 3: Initializing the array

        for (int i = 0; i < N - 1; i++) { // Step 4: Reading and counting elements
            int a = scanner.nextInt();
            v[a - 1]++;
        }

        java.io.BufferedWriter writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(System.out)); // Step 5: Writing the results
        try {
            for (int e : v) {
                writer.write(e + "\n");
            }
            writer.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
