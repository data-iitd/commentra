

public class s760945395{
  public static void main(String[] args) {
    for (int i = 0; i < 5; i++) {
      int a = 0;
      System.out.println("Enter a number: ");
      Scanner scanner = new Scanner(System.in);
      a = scanner.nextInt();
      if (a == 0) {
        System.out.println(i + 1);
      }
    }
  }
}

