public class Main {
    public static void main(String[] args) {
        // Declare a String to hold the input string with a maximum length of 100 characters
        String mes;

        // Read a string from standard input and store it in the 'mes' variable
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        mes = scanner.next();

        // Print the first character of the string, the length of the string minus 2, and the last character of the string
        System.out.println(mes.charAt(0) + "" + (mes.length() - 2) + "" + mes.charAt(mes.length() - 1));

        // Return 0 to indicate successful completion of the program
    }
}
