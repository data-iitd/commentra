public class Main {
  public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    String s = scanner.nextLine();
    
    String ans = "No";
    int firstC = s.indexOf("C");
    int lastF = s.lastIndexOf("F");
    
    if (firstC >= 0 && firstC < lastF) {
      ans = "Yes";
    }
    
    System.out.println(ans);
  }
}
