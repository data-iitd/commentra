public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String mes = scanner.next(); // Read a string input from the user and store it in 'mes'

        // Calculate the length of the string excluding the first and last character
        int length = mes.length() - 2;

        // Print the first character, the calculated length, and the last character of the string
        System.out.println(mes.charAt(0) + "" + length + mes.charAt(mes.length() - 1));
    }
}
