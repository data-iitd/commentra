public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String mes = scanner.next(); // Read a string from the standard input and store it in 'mes' variable

        // Logic starts here

        System.out.println(mes.charAt(0) + "" + (mes.length() - 2) + mes.charAt(mes.length() - 1)); // Print the first character, length - 2 and last character of the input string
    }
}
