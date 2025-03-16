public class Main {
    public static void main(String[] args) {
        java.util.Stack<Integer> stack = new java.util.Stack<>();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s;
        int a, b;

        while (scanner.hasNext()) {
            s = scanner.next();
            if (s.equals("+")) {
                b = stack.pop();
                a = stack.pop();
                stack.push(a + b);
            } else if (s.equals("-")) {
                b = stack.pop();
                a = stack.pop();
                stack.push(a - b);
            } else if (s.equals("*")) {
                b = stack.pop();
                a = stack.pop();
                stack.push(a * b);
            } else {
                stack.push(Integer.parseInt(s));
            }
        }
        System.out.println(stack.pop());
    }
}
