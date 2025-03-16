import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Scanner scanner = new Scanner(System.in);
        String s;
        int a, b;

        while (scanner.hasNext()) {
            s = scanner.next();
            if (s.equals("+") || s.equals("-") || s.equals("*")) {
                b = stack.pop();
                a = stack.pop();

                if (s.equals("+")) {
                    stack.push(a + b);
                } else if (s.equals("-")) {
                    stack.push(a - b);
                } else {
                    stack.push(a * b);
                }
            } else {
                stack.push(Integer.parseInt(s));
            }
        }

        System.out.println(stack.pop());
    }
}
