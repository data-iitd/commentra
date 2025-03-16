import java.util.*;
public class Main {
  public static void main(String[] args) {
    // Importing Scanner to read input from the user
    Scanner sc = new Scanner(System.in);
    // Reading the number of elements in the sequence
    int N = sc.nextInt();
    // Initializing counters to zero
    int count1 = 0; // Counts numbers divisible by 4
    int count2 = 0; // Counts numbers divisible by 2 but not by 4
    // Loop through each element in the sequence
    for(int i=0;i<N;i++){
      // Reading the current element
      int a = sc.nextInt();
      // Checking if the element is divisible by 4
      if(a%4==0){
        count1++;
      }else if(a%2==0 && (a/2)%2==1){ // Checking if the element is divisible by 2 but not by 4
        count2++;
      }
    }
    // Checking if the count of numbers divisible by 4 is at least half of N
    if(count1>=N/2){
      System.out.println("Yes");
    }else if(((N/2-count1)*2+N%2)==count2){ // Checking if the count of numbers divisible by 2 but not by 4 matches the specific condition
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
