import java.util.*; // Importing the utility package for collections and other utilities.

class calArea{ // Defining a class to calculate the area of a rectangle.
    int Area(int w, int h ){ // Method to calculate the area of a rectangle.
        int area = w * h; // Multiplying width and height to get the area.
        return area; // Returning the calculated area.
    }
}

public class Main { // Main class where the program execution begins.

    public static void main(String[] args) { // Main method where the program starts.
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the user.
        List<Integer> arr = new ArrayList<>(); // Creating an ArrayList to store input values.
        
        for(int i = 0; i < 4;i++){ // Loop to read four integer values from the user.
            arr.add(Integer.parseInt(sc.next())); // Parsing the input to an integer and adding it to the list.
        }
        
        calArea ab = new calArea(); // Creating an instance of the calArea class.
        int area1 = ab.Area(arr.get(0),arr.get(1)); // Calculating the area of the first rectangle.
        int area2 = ab.Area(arr.get(2),arr.get(3)); // Calculating the area of the second rectangle.
        
        if(area1 > area2){ // Checking if the area of the first rectangle is greater than the second.
            System.out.println(area1); // Printing the area of the first rectangle if it's greater.
        }else if(area1 < area2){ // Checking if the area of the first rectangle is less than the second.
            System.out.println(area2); // Printing the area of the second rectangle if it's greater.
        }else if(area1 == area2){ // Checking if the areas are equal.
            System.out.println(area1); // Printing either area if they are equal.
        }   
        
    }
    
}
