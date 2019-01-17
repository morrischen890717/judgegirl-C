#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int sol[3];
    int k = 0;
    long long int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    for(long long int i = 100000; i >= -100000 && k < 3; i--){
        if(i == 0 || c % i == 0){
            if(i * i * i + a * i * i + b * i + c == 0LL){
                sol[k++] = i;
                if(3 * i * i + 2 * a * i + b == 0LL){
                    sol[k++] = i;
                    if(6 * i + 2 * a == 0LL){
                        sol[k++] = i;
                    }
                }
            }
        }
    }
    printf("%d %d %d", -sol[0], -sol[1], -sol[2]);
#ifdef r
    g = a - d;
    if(c == 0){
        h = b;
    }
    else{
        h = c / d;
    }
    e = (-g + (g * g - 4 * h)^(1/2))/ 2;
    f = (-g - (g * g - 4 * h)^(1/2))/ 2;
    printf("%d %d %d", d, -e, -f);
#endif
    return 0;
}
