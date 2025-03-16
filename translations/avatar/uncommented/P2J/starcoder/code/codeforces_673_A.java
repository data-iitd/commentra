n = Integer.parseInt(sc.nextLine());
arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
if(arr[0]>15) System.out.println(15);
else{
    for(int i=1;i<arr.length;i++){
        if(arr[i]-arr[i-1]>15) {
            System.out.println(arr[i-1]+15);
            break;
        }
    }
    if(arr[arr.length-1]==90 || arr[arr.length-1]+15>=90) System.out.println(90);
    else System.out.println(arr[arr.length-1]+15);
}

