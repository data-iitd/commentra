<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
<<<<<<< HEAD
	key  int
	next *Node
	prev *Node
=======
	Key  int
	Next *Node
	Prev *Node
>>>>>>> 98c87cb78a (data updated)
}

var nil = &Node{0, nil, nil}

func listSearch(key int) *Node {
<<<<<<< HEAD
	cur := nil.next
	for cur!= nil && cur.key!= key {
		cur = cur.next
=======
	cur := nil.Next
	for cur!= nil && cur.Key!= key {
		cur = cur.Next
>>>>>>> 98c87cb78a (data updated)
	}
	return cur
}

func init() {
<<<<<<< HEAD
	nil.next = nil
	nil.prev = nil
}

func printList() {
	cur := nil.next
	isf := true
	for cur!= nil {
		if isf == false {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		isf = false
=======
	nil.Next = nil
	nil.Prev = nil
}

func printList() {
	cur := nil.Next
	isFirst := true
	for cur!= nil {
		if isFirst {
			isFirst = false
		} else {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.Key)
		cur = cur.Next
>>>>>>> 98c87cb78a (data updated)
	}
	fmt.Printf("\n")
}

func deleteNode(t *Node) {
<<<<<<< HEAD
	t.prev.next = t.next
	t.next.prev = t.prev
=======
	t.Prev.Next = t.Next
	t.Next.Prev = t.Prev
>>>>>>> 98c87cb78a (data updated)
	free(t)
}

func deleteFirst() {
<<<<<<< HEAD
	t := nil.next
=======
	t := nil.Next
>>>>>>> 98c87cb78a (data updated)
	if t == nil {
		return
	}
	deleteNode(t)
}

func deleteLast() {
<<<<<<< HEAD
	t := nil.prev
=======
	t := nil.Prev
>>>>>>> 98c87cb78a (data updated)
	if t == nil {
		return
	}
	deleteNode(t)
}

func delete(key int) {
	t := listSearch(key)
	if t == nil {
		return
	}
	deleteNode(t)
}

func insert(key int) {
<<<<<<< HEAD
	x := new(Node)
	x.key = key
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

func main() {
	var key, n, i int
	var com string
	var np, nd int
	var size int

	fmt.Scanf("%d", &n)

	init()

	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				delete(key)
				nd++
			}
			size--
		}
	}

	printList()
}

=======
	x := &Node{key, nil, nil}
	x.Next = nil.Next
	nil.Next.Prev = x
	nil.Next = x
	x.Prev = nil
}

func main() {
	var key int
	var n int
	var i int
	var size int
	var com string
	var np int
	var nd int
	var coms []string
	var com0 string
	var com1 string
	var com2 string
	var com3 string
	var com4 string
	var com5 string
	var com6 string
	var com7 string
	var com8 string
	var com9 string
	var com10 string
	var com11 string
	var com12 string
	var com13 string
	var com14 string
	var com15 string
	var com16 string
	var com17 string
	var com18 string
	var com19 string
	var com20 string
	var com21 string
	var com22 string
	var com23 string
	var com24 string
	var com25 string
	var com26 string
	var com27 string
	var com28 string
	var com29 string
	var com30 string
	var com31 string
	var com32 string
	var com33 string
	var com34 string
	var com35 string
	var com36 string
	var com37 string
	var com38 string
	var com39 string
	var com40 string
	var com41 string
	var com42 string
	var com43 string
	var com44 string
	var com45 string
	var com46 string
	var com47 string
	var com48 string
	var com49 string
	var com50 string
	var com51 string
	var com52 string
	var com53 string
	var com54 string
	var com55 string
	var com56 string
	var com57 string
	var com58 string
	var com59 string
	var com60 string
	var com61 string
	var com62 string
	var com63 string
	var com64 string
	var com65 string
	var com66 string
	var com67 string
	var com68 string
	var com69 string
	var com70 string
	var com71 string
	var com72 string
	var com73 string
	var com74 string
	var com75 string
	var com76 string
	var com77 string
	var com78 string
	var com79 string
	var com80 string
	var com81 string
	var com82 string
	var com83 string
	var com84 string
	var com85 string
	var com86 string
	var com87 string
	var com88 string
	var com89 string
	var com90 string
	var com91 string
	var com92 string
	var com93 string
	var com94 string
	var com95 string
	var com96 string
	var com97 string
	var com98 string
	var com99 string
	var com100 string
	var com101 string
	var com102 string
	var com103 string
	var com104 string
	var com105 string
	var com106 string
	var com107 string
	var com108 string
	var com109 string
	var com110 string
	var com111 string
	var com112 string
	var com113 string
	var com114 string
	var com115 string
	var com116 string
	var com117 string
	var com118 string
	var com119 string
	var com120 string
	var com121 string
	var com122 string
	var com123 string
	var com124 string
	var com125 string
	var com126 string
	var com127 string
	var com128 string
	var com129 string
	var com130 string
	var com131 string
	var com132 string
	var com133 string
	var com134 string
	var com135 string
	var com136 string
	var com137 string
	var com138 string
	var com139 string
	var com140 string
	var com141 string
	var com142 string
	var com143 string
	var com144 string
	var com145 string
	var com146 string
	var com147 string
	var com148 string
	var com149 string
	var com150 string
	var com151 string
	var com152 string
	var com153 string
	var com154 string
	var com155 string
	var com156 string
	var com157 string
	var com158 string
	var com159 string
	var com160 string
	var com161 string
	var com162 string
	var com163 string
	var com164 string
	var com165 string
	var com166 string
	var com167 string
	var com168 string
	var com169 string
	var com170 string
	var com171 string
	var com172 string
	var com173 string
	var com174 string
	var com175 string
	var com176 string
	var com177 string
	var com178 string
	var com179 string
	var com180 string
	var com181 string
	var com182 string
	var com183 string
	var com184 string
	var com185 string
	var com186 string
	var com187 string
	var com188 string
	var com189 string
	var com190 string
	var com191 string
	var com192 string
	var com193 string
	var com194 string
	var com195 string
	var com196 string
	var com197 string
	var com198 string
	var com199 string
	var com200 string
	var com201 string
	var com202 string
	var com203 string
	var com204 string
	var com205 string
	var com206 string
	var com207 string
	var com208 string
	var com209 string
	var com210 string
	var com211 string
	var com212 string
	var com213 string
	var com214 string
	var com215 string
	var com216 string
	var com217 string
	var com218 string
	var com219 string
	var com220 string
	var com221 string
	var com222 string
	var com223 string
	var com224 string
	var com225 string
	var com226 string
	var com227 string
	var com228 string
	var com229 string
	var com230 string
	var com231 string
	var com232 string
	var com233 string
	var com234 string
	var com235 string
	var com236 string
	var com237 string
	var com238 string
	var com239 string
	var com240 string
	var com241 string
	var com242 string
	var com243 string
	var com244 string
	var com245 string
	var com246 string
	var com247 string
	var com248 string
	var com249 string
	var com250 string
	var com251 string
	var com252 string
	var com253 string
	var com254 string
	var com255 string
	var com256 string
	var com257 string
	var com258 string
	var com259 string
	var com260 string
	var com261 string
	var com262 string
	var com263 string
	var com264 string
	var com265 string
	var com266 string
	var com267 string
	var com268 string
	var com269 string
	var com270 string
	var com271 string
	var com272 string
	var com273 string
	var com274 string
	var com275 string
	var com276 string
	var com277 string
	var com278 string
	var com279 string
	var com280 string
	var com281 string
	var com282 string
	var com283 string
	var com284 string
	var com285 string
	var com286 string
	var com287 string
	var com288 string
	var com289 string
	var com290 string
	var com291 string
	var com292 string
	var com293 string
	var com294 string
	var com295 string
	var com296 string
	var com297 string
	var com298 string
	var com299 string
	var com300 string
	var com301 string
	var com302 string
	var com303 string
	var com304 string
	var com305 string
	var com306 string
	var com307 string
	var com308 string
	var com309 string
	var com310 string
	var com311 string
	var com312 string
	var com313 string
	var com314 string
	var com315 string
	var com316 string
	var com317 string
	var com318 string
	var com319 string
	var com320 string
	var com321 string
	var com322 string
	var com323 string
	var com324 string
	var com325 string
	var com326 string
	var com327 string
	var com328 string
	var com329 string
	var com330 string
	var com331 string
	var com332 string
	var com333 string
	var com334 string
	var com335 string
	var com336 string
	var com337 string
	var com338 string
	var com339 string
	var com340 string
	var com341 string
	var com342 string
	var com343 string
	var com344 string
	var com345 string
	var com346 string
	var com347 string
	var com348 string
	var com349 string
	var com350 string
	var com351 string
	var com352 string
	var com353 string
	var com354 string
	var com355 string
	var com356 string
	var com357 string
	var com358 string
	var com359 string
	var com360 string
	var com361 string
	var com362 string
	var com363 string
	var com364 string
	var com365 string
	var com366 string
	var com367 string
	var com368 string
	var com369 string
	var com370 string
	var com371 string
	var com372 string
	var com373 string
	var com374 string
	var com375 string
	var com376 string
	var com377 string
	var com378 string
	var com379 string
	var com380 string
	var com381 string
	var com382 string
	var com383 string
	var com384 string
	var com385 string
	var com386 string
	var com387 string
	var com388 string
	var com389 string
	var com390 string
	var com391 string
	var com392 string
	var com393 string
	var com394 string
	var com395 string
	var com396 string
	var com397 string
	var com398 string
	var com399 string
	var com400 string
	var com401 string
	var com402 string
	var com403 string
	var com404 string
	var com405 string
	var com406 string
	var com407 string
	var com408 string
	var com409 string
	var com410 string
	var com411 string
	var com412 string
	var com413 string
	var com414 string
	var com415 string
	var com416 string
	var com417 string
	var com418 string
	var com419 string
	var com420 string
	var com421 string
	var com422 string
	var com423 string
	var com424 string
	var com425 string
	var com426 string
	var com427 string
	var com428 string
	var com429 string
	var com430 string
	var com431 string
	var com432 string
	var com433 string
	var com434 string
	var com435 string
	var com436 string
	var com437 string
	var com438 string
	var com439 string
	var com440 string
	var com441 string
	var com442 string
	var com443 string
	var com444 string
	var com445 string
	var com446 string
	var com447 string
	var com448 string
	var com449 string
	var com450 string
	var com451 string
	var com452 string
	var com453 string
	var com454 string
	var com455 string
	var com456 string
	var com457 string
	var com458 string
	var com459 string
	var com460 string
	var com461 string
	var com462 string
	var com463 string
	var com464 string
	var com465 string
	var com466 string
	var com467 string
	var com468 string
	var com469 string
	var com470 string
	var com471 string
	var com472 string
	var com473 string
	var co
>>>>>>> 98c87cb78a (data updated)
