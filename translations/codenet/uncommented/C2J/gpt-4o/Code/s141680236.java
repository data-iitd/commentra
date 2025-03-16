import java.util.Scanner;
import java.util.Stack;

public class Main {
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input;

        while (scanner.hasNext()) {
            input = scanner.next();

            switch (input) {
                case "+":
                    int add1 = pop();
                    int add2 = pop();
                    push(add1 + add2);
                    break;
                case "-":
                    int sub1 = pop();
                    int sub2 = pop();
                    push(sub1 - sub2);
                    break;
                case "*":
                    int mul1 = pop();
                    int mul2 = pop();
                    push(mul1 * mul2);
                    break;
                default:
                    push(Integer.parseInt(input));
                    break;
            }
        }

        System.out.println(pop());
        scanner.close();
    }

    static void push(int value) {
        stack.push(value);
    }

    static int pop() {
        return stack.pop();
    }
}

// <END-OF-CODE>
