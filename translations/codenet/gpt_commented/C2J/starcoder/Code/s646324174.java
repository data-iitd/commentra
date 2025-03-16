import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<Integer>();
        int a, b;
        String s;
        while(sc.hasNext()) {
            s = sc.next();
            if(s.charAt(0) == '+') {
                b = stack.pop();
                a = stack.pop();
                stack.push(a + b);
            } else if(s.charAt(0) == '-') {
                b = stack.pop();
                a = stack.pop();
                stack.push(a - b);
            } else if(s.charAt(0) == '*') {
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
