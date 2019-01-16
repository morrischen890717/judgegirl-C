#include <stdio.h>
int main(){
    int a, b;
    int change = 0;
    int divide;
    int remainder;
    int k;
    int t;
    int output_a, output_b;
    while(~scanf("%d%d", &a, &b)){
        change = 0;
        if(a < b){
            int temp = a;
            a = b;
            b = temp;
            change = 1;
        }
        if(b == 0){
            printf("0\n");
            continue;
        }
        divide = b;
        remainder = a % b;
        k = b;
        while(remainder != 0){
            k = remainder;
            remainder = divide % remainder;
            divide = k;
        }
        if(change == 1){
            output_a = b / k;
            output_b = a / k;
        }
        else{
            output_a = a / k;
            output_b = b / k;
        }
        printf("%d / %d\n", output_a, output_b);
    }
    return 0;
}
