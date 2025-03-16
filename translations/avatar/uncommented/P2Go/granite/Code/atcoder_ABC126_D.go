
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type Node struct {
    val   int
    color bool
    a     []*Node
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    nodes := make([]*Node, n)
    for i := 0; i < n; i++ {
        nodes[i] = &Node{}
    }
    for i := 0; i < n-1; i++ {
        u, _ := strconv.Atoi(readLine(reader))
        v, _ := strconv.Atoi(readLine(reader))
        w, _ := strconv.Atoi(readLine(reader))
        u--
        v--
        nodes[u].a = append(nodes[u].a, &Node{val: v, color: false, a: []*Node{}})
        nodes[v].a = append(nodes[v].a, &Node{val: u, color: false, a: []*Node{}})
    }
    root := nodes[0]
    root.color = true
    nodeSet := make(map[*Node]bool)
    traverse(root, 0, nodeSet)
    for i := 0; i < n; i++ {
        if nodes[i].color {
            fmt.Println(1)
        } else {
            fmt.Println(0)
        }
    }
}

func traverse(node *Node, distance int, nodeSet map[*Node]bool) {
    if nodeSet[node] {
        return
    }
    nodeSet[node] = true
    for _, pair := range node.a {
        adjNode := pair[0]
        dis := pair[1]
        if (distance+dis)%2 == 0 {
            adjNode.color = root.color
        } else {
            adjNode.color =!root.color
        }
        traverse(adjNode, distance+dis, nodeSet)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

