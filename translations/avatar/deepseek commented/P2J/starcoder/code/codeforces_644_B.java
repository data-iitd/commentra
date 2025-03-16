import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int b = sc.nextInt ( );
        Queue < Task > remaining = new PriorityQueue < > ( );
        boolean running = false;
        int finish_time = 0;
        Map < Integer, Integer > result = new HashMap < > ( );
        for ( int i = 0 ; i < n ; i ++ ) {
            int time = sc.nextInt ( );
            int duration = sc.nextInt ( );
            Task task = new Task ( time, duration, i );
            result.put ( i, 0 );
            if ( task.time > finish_time && remaining.isEmpty ( ) ) {
                running = true;
                finish_time = task.time + task.duration;
                result.put ( i, finish_time );
            } else {
                if ( task.time >= finish_time &&! remaining.isEmpty ( ) ) {
                    finish_time = runTask ( remaining, finish_time );
                }
                if ( remaining.size ( ) < b ) {
                    remaining.add ( task );
                } else {
                    result.put ( i, - 1 );
                }
            }
        }
        while (! remaining.isEmpty ( ) ) {
            finish_time = runTask ( remaining, finish_time );
        }
        for ( int key : result.keySet ( ) ) {
            System.out.println ( result.get ( key ) );
        }
    }
    public static int runTask ( Queue < Task > remaining, int finish_time ) {
        Task task_to_run = remaining.poll ( );
        finish_time = Math.max ( finish_time, task_to_run.time ) + task_to_run.duration;
        result.put ( task_to_run.index, finish_time );
        return finish_time;
    }
}
class Task implements Comparable < Task > {
    int time;
    int duration;
    int index;
    public Task ( int time, int duration, int index ) {
        this.time = time;
        this.duration = duration;
        this.index = index;
    }
    public int compareTo ( Task task ) {
        return this.time - task.time;
    }
}
// Define the Task class to represent a task with its starting time, duration, and index.

