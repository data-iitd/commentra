public class Main {
    public static void main(String[] args) {
        java.util.Map<Integer, Integer> m = new java.util.HashMap<>();
        for (int i = 0; i * 200 < 5001; i++) { // Loop through possible values of i
            for (int j = 0; j * 300 < 5001; j++) { // Loop through possible values of j
                for (int k = 0; k * 500 < 5001; k++) { // Loop through possible values of k
                    int w = i * 200 + j * 300 + k * 500; // Calculate the weight
                    int p = i / 5 * 5 * 380 * 0.8 + i % 5 * 380 // Calculate the price for i
                            + j / 4 * 4 * 550 * 0.85 + j % 4 * 550 // Calculate the price for j
                            + k / 3 * 3 * 850 * 0.88 + k % 3 * 850; // Calculate the price for k
                    if (m.containsKey(w)) {
                        m.put(w, Math.min(m.get(w), p)); // Update the map with the minimum price
                    } else {
                        m.put(w, p); // Add new weight and price to the map
                    }
                }
            }
        }
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n;
        while ((n = scanner.nextInt()) != 0) { // Read input until a zero is entered
            System.out.println(m.getOrDefault(n, 0)); // Output the minimum price for the given weight
        }
    }
}
