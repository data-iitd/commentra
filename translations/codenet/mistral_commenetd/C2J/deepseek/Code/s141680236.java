import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (line.isEmpty()) {
                continue;
            }

            if (line.charAt(0) == '+') {
                int second = stack.pop();
                int first = stack.pop();
                stack.push(first + second);
            } else if (line.charAt(0) == '-') {
                int second = stack.pop();
                int first = stack.pop();
                stack.push(first - second);
            } else if (line.charAt(0) == '*') {
                int second = stack.pop();
                int first = stack.pop();
                stack.push(first * second);
            } else {
                stack.push(Integer.parseInt(line));
            }
        }

        System.out.println(stack.pop());
    }
}

