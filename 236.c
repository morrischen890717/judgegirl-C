#include <stdio.h>


int gcd(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int output = b;
    while(a % b != 0){
        output = a % b;
        a = b;
        b =  output;
    }
    return output;
}

int main(){
    int a, b;
    int lcm;
    scanf("%d%d", &a, &b);
    lcm = (a * b) / gcd(a, b);
    int c;
    while(~scanf("%d", &c)){
        lcm = (lcm * c) / gcd(lcm, c);
    }
    printf("%d", lcm);
    return 0;
}
