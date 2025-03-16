
import java.util.Scanner;

public class s201004620{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String S = scanner.nextLine();
    switch (S) {
      case "Sunny":
        System.out.println("Cloudy");
        break;
      case "Cloudy":
        System.out.println("Rainy");
        break;
      case "Rainy":
        System.out.println("Sunny");
        break;
    }
  }
}
