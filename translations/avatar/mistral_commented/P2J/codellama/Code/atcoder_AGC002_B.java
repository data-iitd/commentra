#######
# Code
#######

// Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Define constants
class Code {
    static final int INF = 1000000007;
    static final int mod = 1000000007;
}

// Define class for a ball
class Ball {
    int weight;
    int position;

    public Ball(int weight, int position) {
        this.weight = weight;
        this.position = position;
    }
}

// Define class for a event
class Event {
    int x;
    int y;

    public Event(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Define function to calculate answer
    public int calculateAnswer() {
        // Initialize answer
        int ans = 0;

        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i].position != 0) {
                ans += 1;
            }
        }

        // Return answer
        return ans;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Define function to calculate answer
    public int calculateAnswer() {
        // Initialize answer
        int ans = 0;

        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i].position != 0) {
                ans += 1;
            }
        }

        // Return answer
        return ans;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Define function to calculate answer
    public int calculateAnswer() {
        // Initialize answer
        int ans = 0;

        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i].position != 0) {
                ans += 1;
            }
        }

        // Return answer
        return ans;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Define function to calculate answer
    public int calculateAnswer() {
        // Initialize answer
        int ans = 0;

        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i].position != 0) {
                ans += 1;
            }
        }

        // Return answer
        return ans;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Define function to calculate answer
    public int calculateAnswer() {
        // Initialize answer
        int ans = 0;

        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i].position != 0) {
                ans += 1;
            }
        }

        // Return answer
        return ans;
    }
}

// Define class for a solution
class Solution {
    // Define variables
    int N;
    int M;
    Ball[] balls;
    Event[] events;

    // Define constructor
    public Solution(int N, int M) {
        this.N = N;
        this.M = M;
        this.balls = new Ball[N];
        this.events = new Event[M];
    }

    // Define function to process each event
    public void processEvent(int i) {
        // Get x and y coordinates of the event
        int x = events[i].x;
        int y = events[i].y;

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ba