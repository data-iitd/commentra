import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();

    char[] arr1 = str1.toCharArray();
    char[] arr2 = str2.toCharArray();

    int loop = arr1.length > arr2.length ? arr2.length : arr1.length;
    boolean flag = false;

    for(int i = 0; loop > i; i++){
      char ch1 = arr1[i];
      char ch2 = arr2[i];

      if(ch1 == ch2){
        if(loop == i + 1 && arr1.length < arr2.length){
          flag = true;
          break;
        }else{
          continue;
        }
      }else{
        if(ch2 > ch1){
          flag = true;
          break;
        }else{
          break;
        }
      }
    }

    if(flag){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}

