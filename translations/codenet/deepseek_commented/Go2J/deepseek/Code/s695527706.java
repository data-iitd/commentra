public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Reading the number of inputs
        String s = scanner.next(); // Reading the input string
        int count = 0; // Initializing a counter to count occurrences of "ABC"
        for (int i = 0; i <= s.length() - 3; i++) { // Looping through the string
            if (s.substring(i, i + 3).equals("ABC")) { // Checking if the substring is "ABC"
                count++; // Incrementing the counter if "ABC" is found
            }
        }
        System.out.println(count); // Printing the count of "ABC" occurrences
    }
}
