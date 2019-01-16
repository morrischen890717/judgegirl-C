#include <stdio.h>
#include <stdlib.h>
int compare(const void *data1, const void *data2){
    int *ptr1 = (int *)data1;
    int *ptr2 = (int *)data2;
    if(*ptr1 < *ptr2){
        return -1;
    }
    else if(*ptr1 > *ptr2){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int square[n];
    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        square[i] = x * x + y * y;
    }
    qsort(square, n, sizeof(int), compare);
    int max_times = 0;
    int max_number = 0;
    int times = 0;
    int number;
    number = square[0];
    for(int i = 0; i < n; i++){
        if(square[i] == number){
            times++;
        }
        else{
            if(times > max_times){
                max_times = times;
                max_number = number;
            }
            else if(times == max_times){
                if(number > max_number){
                    max_number = number;
                }
            }
            times = 1;
            number = square[i];
        }
    }
    if(times > max_times){
                max_times = times;
                max_number = number;
            }
            else if(times == max_times){
                if(number > max_number){
                    max_number = number;
                }
            }
    printf("%d", max_number);
    return 0;
}
