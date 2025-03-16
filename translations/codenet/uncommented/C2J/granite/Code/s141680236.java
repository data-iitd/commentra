
import java.util.Scanner;

class s141680236 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int top = 0;
    String null = "";

    while (scanner.hasNext()) {
      null = scanner.next();
      if (null.equals("+")) {
        int chonda = pop();
        int yamagami = pop();
        push(chonda + yamagami);
      } else if (null.equals("-")) {
        int yamagami = pop();
        int chonda = pop();
        push(chonda - yamagami);
      } else if (null.equals("*")) {
        int chonda = pop();
        int yamagami = pop();
        push(chonda * yamagami);
      } else {
        push(Integer.parseInt(null));
      }
    }

    System.out.println(pop());
  }

  static void push(int chonda) {
    stack[top++] = chonda;
  }

  static int pop() {
    return stack[--top];
  }

  static int[] stack = new int[1000];
  static int top;
}
