import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Map<Integer,Integer>m=new HashMap<Integer,Integer>();
        for(int i=0;i*200<5001;i++){ // Loop through possible values of i
            for(int j=0;j*300<5001;j++){ // Loop through possible values of j
                for(int k=0;k*500<5001;k++){ // Loop through possible values of k
                    int w=i*200+j*300+k*500; // Calculate the weight
                    int p=i/5*5*380*0.8+i%5*380 // Calculate the price for i
                         +j/4*4*550*0.85+j%4*550 // Calculate the price for j
                         +k/3*3*850*0.88+k%3*850; // Calculate the price for k
                    if(m.containsKey(w))m.put(w,Math.min(m.get(w),p)); // Update the map with the minimum price
                    else m.put(w,p); // Add new weight and price to the map
                }
            }
        }
        while(true){
            int n=sc.nextInt();
            if(n==0)break; // Break if a zero is entered
            System.out.println(m.get(n)); // Output the minimum price for the given weight
        }
    }
}
