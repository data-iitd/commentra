public class Main {
    static int top;
    static int[] kinbo = new int[1000];

    public static void main(String[] args) {
        int chonda, yamagami;
        top = 0;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String nullString;

        while (scanner.hasNext()) {
            nullString = scanner.next();
            if (nullString.charAt(0) == '+') {
                chonda = pop();
                yamagami = pop();
                push(chonda + yamagami);
            } else if (nullString.charAt(0) == '-') {
                yamagami = pop();
                chonda = pop();
                push(chonda - yamagami);
            } else if (nullString.charAt(0) == '*') {
                chonda = pop();
                yamagami = pop();
                push(chonda * yamagami);
            } else {
                push(Integer.parseInt(nullString));
            }
        }

        System.out.println(pop());
    }

    static void push(int chonda) {
        kinbo[++top] = chonda;
    }

    static int pop() {
        return kinbo[top--];
    }
}
