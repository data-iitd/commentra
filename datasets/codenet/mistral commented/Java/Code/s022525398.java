import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        // Create an instance of the Scanner class to read input from the standard input stream
        Scanner in = new Scanner(System.in);

        // Define two String variables 'a' and 'b' and initialize them with the next two lines of input read from the standard input stream
        String a = in.next();
        String b = in.next();

        // Print the concatenated string of 'b' and 'a' to the standard output stream
        System.out.println(b + a);
    }
}