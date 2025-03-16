package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter the number of rows and columns")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    row, _ := strconv.Atoi(input)
    col, _ := strconv.Atoi(input)

    fmt.Println("Enter the number of mines")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    mine, _ := strconv.Atoi(input)

    fmt.Println("Enter the mine locations")
    mine_loc := make([][]int, mine)
    for i := 0; i < mine; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        mine_loc[i] = make([]int, 2)
        mine_loc[i][0], mine_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of moves")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    move, _ := strconv.Atoi(input)

    fmt.Println("Enter the move locations")
    move_loc := make([][]int, move)
    for i := 0; i < move; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        move_loc[i] = make([]int, 2)
        move_loc[i][0], move_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of questions")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    question, _ := strconv.Atoi(input)

    fmt.Println("Enter the question locations")
    question_loc := make([][]int, question)
    for i := 0; i < question; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        question_loc[i] = make([]int, 2)
        question_loc[i][0], question_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of answers")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    answer, _ := strconv.Atoi(input)

    fmt.Println("Enter the answer locations")
    answer_loc := make([][]int, answer)
    for i := 0; i < answer; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        answer_loc[i] = make([]int, 2)
        answer_loc[i][0], answer_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of hints")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    hint, _ := strconv.Atoi(input)

    fmt.Println("Enter the hint locations")
    hint_loc := make([][]int, hint)
    for i := 0; i < hint; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        hint_loc[i] = make([]int, 2)
        hint_loc[i][0], hint_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of guesses")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    guess, _ := strconv.Atoi(input)

    fmt.Println("Enter the guess locations")
    guess_loc := make([][]int, guess)
    for i := 0; i < guess; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        guess_loc[i] = make([]int, 2)
        guess_loc[i][0], guess_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of flags")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    flag, _ := strconv.Atoi(input)

    fmt.Println("Enter the flag locations")
    flag_loc := make([][]int, flag)
    for i := 0; i < flag; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        flag_loc[i] = make([]int, 2)
        flag_loc[i][0], flag_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of mines")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    mine, _ := strconv.Atoi(input)

    fmt.Println("Enter the mine locations")
    mine_loc := make([][]int, mine)
    for i := 0; i < mine; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        mine_loc[i] = make([]int, 2)
        mine_loc[i][0], mine_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of moves")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    move, _ := strconv.Atoi(input)

    fmt.Println("Enter the move locations")
    move_loc := make([][]int, move)
    for i := 0; i < move; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        move_loc[i] = make([]int, 2)
        move_loc[i][0], move_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of questions")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    question, _ := strconv.Atoi(input)

    fmt.Println("Enter the question locations")
    question_loc := make([][]int, question)
    for i := 0; i < question; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        question_loc[i] = make([]int, 2)
        question_loc[i][0], question_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of answers")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    answer, _ := strconv.Atoi(input)

    fmt.Println("Enter the answer locations")
    answer_loc := make([][]int, answer)
    for i := 0; i < answer; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        answer_loc[i] = make([]int, 2)
        answer_loc[i][0], answer_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of hints")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    hint, _ := strconv.Atoi(input)

    fmt.Println("Enter the hint locations")
    hint_loc := make([][]int, hint)
    for i := 0; i < hint; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        hint_loc[i] = make([]int, 2)
        hint_loc[i][0], hint_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of guesses")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    guess, _ := strconv.Atoi(input)

    fmt.Println("Enter the guess locations")
    guess_loc := make([][]int, guess)
    for i := 0; i < guess; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        guess_loc[i] = make([]int, 2)
        guess_loc[i][0], guess_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of flags")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    flag, _ := strconv.Atoi(input)

    fmt.Println("Enter the flag locations")
    flag_loc := make([][]int, flag)
    for i := 0; i < flag; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        flag_loc[i] = make([]int, 2)
        flag_loc[i][0], flag_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of mines")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    mine, _ := strconv.Atoi(input)

    fmt.Println("Enter the mine locations")
    mine_loc := make([][]int, mine)
    for i := 0; i < mine; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        mine_loc[i] = make([]int, 2)
        mine_loc[i][0], mine_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of moves")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    move, _ := strconv.Atoi(input)

    fmt.Println("Enter the move locations")
    move_loc := make([][]int, move)
    for i := 0; i < move; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        move_loc[i] = make([]int, 2)
        move_loc[i][0], move_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of questions")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    question, _ := strconv.Atoi(input)

    fmt.Println("Enter the question locations")
    question_loc := make([][]int, question)
    for i := 0; i < question; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        question_loc[i] = make([]int, 2)
        question_loc[i][0], question_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of answers")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    answer, _ := strconv.Atoi(input)

    fmt.Println("Enter the answer locations")
    answer_loc := make([][]int, answer)
    for i := 0; i < answer; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        answer_loc[i] = make([]int, 2)
        answer_loc[i][0], answer_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of hints")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    hint, _ := strconv.Atoi(input)

    fmt.Println("Enter the hint locations")
    hint_loc := make([][]int, hint)
    for i := 0; i < hint; i++ {
        input, _ = reader.ReadString('\n')
        input = strings.TrimSpace(input)
        hint_loc[i] = make([]int, 2)
        hint_loc[i][0], hint_loc[i][1] = strconv.Atoi(input[:2]), strconv.Atoi(input[2:])
    }

    fmt.Println("Enter the number of guesses")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    guess, _ := strconv.Atoi(input)

    fmt.Println("Enter the guess locations")
 