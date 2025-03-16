import java.util.*;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read an integer N from the input, which will be used for shifting characters
        int N = sc.nextInt();
        
        // Read a string from the input and convert it to a character array
        char c[] = sc.next().toCharArray();
        
        // Loop through each character in the array
        for (int i = 0; i < c.length; i++) {
            // Shift the character by N positions in the alphabet, wrapping around using modulo
            c[i] = (char)((c[i] - 'A' + N) % 26 + 'A');
        }
        
        // Print the modified character array as a string
        System.out.println(c);
    }
}
