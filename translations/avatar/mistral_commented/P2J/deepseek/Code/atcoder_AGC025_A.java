public class Main {
    public static void main(String[] args) {
        // Take an input from the user and assign it to the variable 'n'
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String n = scanner.nextLine();

        // Initialize a list 'a' with some strings representing numbers
        String[] a = { "10", "100", "1000", "10000", "100000" };

        // Convert each element of the input 'n' to an integer using the 'map' function
        // and then sum up all the integers using the 'sum' function and assign the result to the variable 'new'
        int new = 0;
        for (char c : n.toCharArray()) {
            new += Character.getNumericValue(c);
        }

        // Check if the input 'n' is present in the list 'a'
        boolean isPresent = false;
        for (String s : a) {
            if (s.equals(n)) {
                isPresent = true;
                break;
            }
        }

        // If the input 'n' is present in the list 'a', then print the number 10
        if (isPresent) {
            System.out.println(10);
        } else {
            // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
            System.out.println(new);
        }
    }
}
