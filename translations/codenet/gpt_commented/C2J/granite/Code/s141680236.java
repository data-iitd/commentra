
import java.util.Scanner;

public class s141680236{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int top = 0;
        int[] stack = new int[1000];

        while (scanner.hasNext()) {
            String input = scanner.next();
            if (input.equals("+")) {
                int num2 = stack[top--];
                int num1 = stack[top--];
                stack[++top] = num1 + num2;
            } else if (input.equals("-")) {
                int num2 = stack[top--];
                int num1 = stack[top--];
                stack[++top] = num1 - num2;
            } else if (input.equals("*")) {
                int num2 = stack[top--];
                int num1 = stack[top--];
                stack[++top] = num1 * num2;
            } else {
                stack[++top] = Integer.parseInt(input);
            }
        }

        System.out.println(stack[top]);
    }
}
