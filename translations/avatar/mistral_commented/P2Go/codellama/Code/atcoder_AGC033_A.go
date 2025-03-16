// Importing the NumPy library for numerical computations
import "github.com/sbinet/npy"

// Taking input dimensions of the graph
h, w := npy.Ints(input())

// Initializing the graph as a 2D NumPy array with initial values
graph := npy.ArrayOf(npy.Float64, h, w)
for i := 0; i < h; i++ {
    for j := 0; j < w; j++ {
        if input() == "#" {
            graph.Set(i, j, 0)
        } else {
            graph.Set(i, j, math.Inf(1))
        }
    }
}

// Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
for x := 0; x < w-1; x++ {
    for i := 0; i < h; i++ {
        graph.Set(i, x, math.Min(graph.Get(i, x)+1, graph.Get(i, x+1)))
    }
}

// Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
for x := w - 1; x > 0; x-- {
    for i := 0; i < h; i++ {
        graph.Set(i, x, math.Min(graph.Get(i, x)+1, graph.Get(i, x-1)))
    }
}

// Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
for y := 0; y < h-1; y++ {
    for i := 0; i < w; i++ {
        graph.Set(y, i, math.Min(graph.Get(y, i)+1, graph.Get(y+1, i)))
    }
}

// Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
for y := h - 1; y > 0; y-- {
    for i := 0; i < w; i++ {
        graph.Set(y, i, math.Min(graph.Get(y, i)+1, graph.Get(y-1, i)))
    }
}

// Finding and printing the maximum shortest path distance in the graph
fmt.Println(int(math.Max(graph.Get(0, 0), graph.Get(h-1, w-1))))

