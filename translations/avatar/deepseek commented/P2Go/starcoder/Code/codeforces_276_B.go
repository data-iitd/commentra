s := strings.Split(fmt.Scanf("%s\n", &s), "")
x := true
dt := make(map[string]int)

for i := range s {
    if dt[s[i]] > 0 {
        dt[s[i]] += 1
    } else {
        dt[s[i]] = 1
    }
}

cnt := 0
x = true

for key, value := range dt {
    if value % 2!= 0 && cnt < 1 {
        cnt += 1
    } else if value % 2!= 0 && cnt >= 1 {
        x = false
        break
    }
}

if x {
    fmt.Println("First")
} else if!x && len(s) % 2 == 0 {
    fmt.Println("Second")
} else if!x && len(s) % 2!= 0 {
    fmt.Println("First")
}

