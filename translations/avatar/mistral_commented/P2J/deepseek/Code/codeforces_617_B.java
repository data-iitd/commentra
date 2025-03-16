public class Main {
    public static void main(String[] args) {
        // Read the input from the standard input
        String a = System.console().readLine();

        // Check if the string contains any '1' character
        if (!a.contains("1")) {
            // If it doesn't, print 0 and exit the program
            System.out.println(0);
            return;
        }

        // If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
        String[] segments = a.split("1");
        int productOfZeros = 1;
        for (String segment : segments) {
            productOfZeros *= (segment.length() + 1);
        }

        // Finally, print the result
        System.out.println(productOfZeros);
    }
}
