
public class Main {
  public static void main(String[] args) {
    int i, N, x;
    x = 0;
    N = Integer.parseInt(args[0]);
    for(i = 1; i <= N; i++)
      x += i;
    System.out.println(x);
  }
}

