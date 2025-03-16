public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Step 1: Read the input values
        String s = scanner.next(); // The string `s` is read from the standard input.
        int cnt = 0; // Step 2: Initialize a counter
        for (int i = 0; i < n; i++) { // Step 3: Iterate through the string
            cnt++; // Increment the counter for each distinct character
            int j = i + 1;
            for (; j < n; j++) { // Step 4: Count distinct characters
                if (s.charAt(i) != s.charAt(j)) { // Check if the current character is different from the next one
                    break; // If a different character is found, break the inner loop
                }
            }
            i = j - 1; // Step 5: Update the loop index
        }
        System.out.println(cnt); // Step 6: Output the result
    }
}
