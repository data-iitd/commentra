#include<stdio.h>
#include<stdlib.h>

type Node struct{
  right *Node
  left *Node
  parent *Node
  key int
}
var root *Node

func treeMinimum(x *Node) *Node{
  for x.left != nil{
    x = x.left
  }
  return x

}

func treeMaximum(x *Node) *Node{
  for x.right != nil{
    x = x.right
  }
  return x

}

func treeSearch(u *Node, k int) *Node{
  if u == nil || k == u.key{
    return u
  }

  if k < u.key{
    return treeSearch(u.left,k)
  }else{
    return treeSearch(u.right,k)
  }

}

func treeSuccessor(x *Node) *Node{
  y := x
  if x.right != nil{
    return treeMinimum(x.right)
  }

  y = x.parent
  for y != nil && x == y.right{
    x = y
    y = y.parent
  }
  return y

}

func treeDelete(z *Node){
  y := z
  x := z
  if z.left == nil || z.right == nil{
    y = z
  }else{
    y = treeSuccessor(z)
  }

  if y.left != nil{
    x = y.left
  }else{
    x = y.right
  }

  if x != nil{
    x.parent = y.parent
  }

  if y.parent == nil{
    root = x
  }else if y == y.parent.left{
    y.parent.left = x
  }else{
    y.parent.right = x
  }

  if y != z{
    z.key = y.key
  }

}

func insert(k int){
  y := nil
  x := root
  z := &Node{}
  z.key = k
  z.left = nil
  z.right = nil

  for x != nil{
    y = x
    if z.key < x.key{
      x = x.left
    }else{
      x = x.right
    }
  }
  z.parent = y
  if y == nil{
    root = z
  }else if z.key < y.key{
    y.left = z
  }else{
    y.right = z
  }
}

func inorder(u *Node){
  if u == nil{
    return
  }
  inorder(u.left)
  fmt.Printf(" %d",u.key)
  inorder(u.right)
}
func preorder(u *Node){
  if u == nil{
    return
  }
  fmt.Printf(" %d",u.key)
  preorder(u.left)
  preorder(u.right)
}


func main(){
  var n, i, x int
  var com [20]byte
  fmt.Scanf("%d", &n)

  for i = 0; i < n; i++{
    fmt.Scanf("%s", com)
    if com[0] == 'f'{
      fmt.Scanf("%d", &x)
      t := treeSearch(root, x)
      if t != nil{
        fmt.Println("yes")
      }else{
        fmt.Println("no")
      }
    }else if com[0] == 'i'{
      fmt.Scanf("%d", &x)
      insert(x)
    }else if com[0] == 'p'{
      inorder(root)
      fmt.Println()
      preorder(root)
      fmt.Println()
    }else if com[0] == 'd'{
      fmt.Scanf("%d", &x)
      treeDelete(treeSearch(root, x))
    }
  }

}

