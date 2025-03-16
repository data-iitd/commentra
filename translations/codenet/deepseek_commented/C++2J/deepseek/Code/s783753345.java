public class Main {
    public static void main(String[] args) {
        // Declare variables to store integers and a character
        int a, b;
        char S;
        
        // Infinite loop to continuously take input and perform operations
        while (true) {
            // Take input in the format a S b
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            String input = scanner.nextLine();
            java.util.StringTokenizer tokenizer = new java.util.StringTokenizer(input);
            
            a = Integer.parseInt(tokenizer.nextToken());
            S = tokenizer.nextToken().charAt(0);
            b = Integer.parseInt(tokenizer.nextToken());
            
            // Perform operations based on the value of S
            if (S == '+') System.out.println(a + b);
            if (S == '-') System.out.println(a - b);
            if (S == '*') System.out.println(a * b);
            if (S == '/') System.out.println(a / b);
            
            // Break the loop if S is '?'
            if (S == '?') break;
        }
    }
}
