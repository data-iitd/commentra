<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    var (
        k, a, b int
    )
    fmt.Scanf("%d %d %d", &k, &a, &b)
    for i := a; i <= b; i++ {
        if i%k == 0 {
            fmt.Println("OK")
            return
        }
    }
    fmt.Println("NG")
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

*/
