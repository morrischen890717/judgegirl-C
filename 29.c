#include <stdio.h>
int num(int row, int col, int now_r, int now_c){
    if(now_c == col - 1 && now_r == row - 1){
        return 1;
    }
    else if(now_c == col || now_r == row){
        return 0;
    }
    else{
        return (num(row, col, now_r + 1, now_c) + num(row, col, now_r, now_c + 1));
    }
}
int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    printf("%d\n", num(row , col, 0, 0));
    return 0;
}
