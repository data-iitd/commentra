import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        int array[] = new int[10];
        Scanner in = new Scanner(System.in);
        for(int i = 0; i!= 10; i++)
            array[i] = in.nextInt();
        Arrays.sort(array, new Comparator<Integer>()
        {
            public int compare(Integer a, Integer b)
            {
                return b - a;
            }
        });
        for(int i = 0; i!= 3; i++)
            System.out.println(array[i]);
    }
}
