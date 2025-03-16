
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int hh = sc.nextInt();
    int ww = sc.nextInt();
    int difference_h = h - hh;
    int difference_w = w - ww;
    System.out.println("The area of the rectangle is: " + difference_h * difference_w);
  }
}

