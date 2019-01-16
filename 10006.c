#include <stdio.h>
int main(){
    int x, sum;
    sum = 0;
    while(~scanf("%d", &x)){
        sum += x;
    }
    printf("%d", sum);
    return 0;
}
