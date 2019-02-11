#include <stdio.h>
int count, x, y;
int next_x(int x, int a, int b, int c);
int next_y(int y, int d, int e, int f);
int next_x(int x, int a, int b, int c){
    return ((a * x + b) % c);
}
int next_y(int y, int d, int e, int f){
    return ((d * y + e) % f);
}
void play(int m, int n, int a, int b, int c, int d, int e, int f);
void play(int m, int n, int a, int b, int c, int d, int e, int f){
    if(m == 0 && n == 0 || m == 1 && n == 1 || m == 2 && n == 2){
        count++;
        x = next_x(x, a, b, c);
        y = next_y(y, d, e, f);
        play(x % 3, y % 3, a, b, c, d, e, f);
    }
    else if(m == 0 && n == 1 || m == 1 && n == 2 || m == 2 && n == 0){
        printf("1 %d\n", count);
    }
    else{
        printf("0 %d\n", count);
    }
    return;
}
int main(){
    int a, b, c, d, e, f, round;
    scanf("%d%d%d%d%d%d%d%d%d", &x, &a, &b, &c, &y, &d, &e, &f, &round);
    for(int i = 0; i < round; i++){
        count = 1;
        play(x % 3, y % 3, a, b, c, d, e, f);
        x = next_x(x, a, b, c);
        y = next_y(y, d, e, f);
    }
    return 0;
}
