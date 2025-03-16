import java.util.*; 				// Importing necessary utility packages
import java.io.*;
import java.math.*;

public class Main {
	// Custom InputIterator class to read input from standard input
	static class InputIterator{
		// Initializing an ArrayList to store input lines
		ArrayList<String> inputLine = new ArrayList<String>(1024);
		int index = 0; 				// Index to keep track of current input line
		int max; 						// Maximum number of input lines
		String read; 				// Temporary string to read a line

		// Constructor to initialize InputIterator
		InputIterator(){
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			try{
				// Reading all input lines and storing them in ArrayList
				while((read = br.readLine()) != null){
					inputLine.add(read);
				}
			}catch(IOException e){}
			max = inputLine.size();
		}

		// Check if there is next input line
		boolean hasNext(){return (index < max);}

		// Read and return next input line
		String next(){
			if(hasNext()){
				return inputLine.get(index++);
			}else{
				throw new IndexOutOfBoundsException("There is no more input");
			}
		}
	}

	// A HashMap to store conversion strings
	static HashMap<Integer, String> CONVSTR = new HashMap<Integer, String>();

	// Initializing InputIterator and PrintWriter
	static InputIterator ii = new InputIterator();
	static PrintWriter out = new PrintWriter(System.out);
	static void flush(){out.flush();}
	static void myout(Object t){out.println(t);}
	static void myerr(Object t){System.err.print("debug:");System.err.println(t);}

	// Helper methods to read different types of input
	static String next(){return ii.next();}
	static boolean hasNext(){return ii.hasNext();}
	static int nextInt(){return Integer.parseInt(next());}
	static long nextLong(){return Long.parseLong(next());}
	static double nextDouble(){return Double.parseDouble(next());}
	static ArrayList<String> nextStrArray(){return myconv(next(), 8);}
	static ArrayList<String> nextCharArray(){return myconv(next(), 0);}
	static ArrayList<Integer> nextIntArray(){
		ArrayList<String> input = nextStrArray();
		ArrayList<Integer> ret = new ArrayList<Integer>(input.size());
		for(int i = 0; i < input.size(); i++){
			ret.add(Integer.parseInt(input.get(i)));
		}
		return ret;
	}
	static ArrayList<Long> nextLongArray(){
		ArrayList<String> input = nextStrArray();
		ArrayList<Long> ret = new ArrayList<Long>(input.size());
		for(int i = 0; i < input.size(); i++){
			ret.add(Long.parseLong(input.get(i)));
		}
		return ret;
	}

	// A utility method to join or split strings based on the given conversion string
	static String myconv(Object list, int no){
		String joinString = CONVSTR.get(no);
		if(list instanceof String[]){
			// Joining String arrays using the given joinString
			return String.join(joinString, (String[])list);
		}else if(list instanceof ArrayList){
			// Joining ArrayLists using the given joinString
			return String.join(joinString, (ArrayList)list);
		}else{
			// Throwing an exception when trying to join other types of objects
			throw new ClassCastException("Don't join");
		}
	}

	static ArrayList<String> myconv(String str, int no){
		// Splitting a given string using the given splitString
		String splitString = CONVSTR.get(no);
		return new ArrayList<String>(Arrays.asList(str.split(splitString)));
	}

	// Main function to solve the problem
	public static void main(String[] args){
		// Initializing the conversion string HashMap
		CONVSTR.put(8, " "); CONVSTR.put(9, "\n"); CONVSTR.put(0, "");

		// Calling the solve method to find the solution
		solve();
		flush();
	}

	// Main logic to find the solution
	static void solve(){
		// Reading the number of test cases (N)
		int N = nextInt();

		// Reading an ArrayList of integers as input
		ArrayList<Integer> list = nextIntArray();

		// Initializing variables
		int max = 0;
		int output = 0;

		// Iterating through the ArrayList to find the maximum number and its occurrences
		for(int i = 0; i < N; i++){
			if(max <= list.get(i)){
				max = list.get(i);
				output++;
			}
		}

		// Printing the output
		myout(output);
	}
}
