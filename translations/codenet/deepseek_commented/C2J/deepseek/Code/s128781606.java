public class Main {
  public static void main(String[] args) {
    int A, B, C, D, E, max;

    java.util.Scanner scanner = new java.util.Scanner(System.in);
    A = scanner.nextInt();
    B = scanner.nextInt();

    C = A + B;
    D = A - B;
    E = A * B;

    max = C;

    if (max < D) {
      max = D;
    }
    if (max < E) {
      max = E;
    }

    System.out.println(max);
  }
}
