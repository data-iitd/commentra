import java.util.*;

public class Stack {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Stack<Integer> stack = new Stack<Integer>();
        while (in.hasNext()) {
            String s = in.next();
            if (s.equals("+")) {
                int b = stack.pop();
                int a = stack.pop();
                stack.push(a + b);
            } else if (s.equals("-")) {
                int b = stack.pop();
                int a = stack.pop();
                stack.push(a - b);
            } else if (s.equals("*")) {
                int b = stack.pop();
                int a = stack.pop();
                stack.push(a * b);
            } else {
                stack.push(Integer.parseInt(s));
            }
        }
        System.out.println(stack.pop());
    }
}
