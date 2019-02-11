#include <stdio.h>
int array[1001][1001];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
        }
    }
    int max = 0;
    int count;
    for(int i = 0; i < N; i++){
        count = 0;
        for(int j = 0; j < N; j++){
            if(array[i][j] == 1){
                count++;
            }
            else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
        }
        if(count > max){
            max = count;
        }
    }
    for(int j = 0; j < N; j++){
        count = 0;
        for(int i = 0; i < N; i++){
            if(array[i][j] == 1){
                count++;
            }
            else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
        }
        if(count > max){
            max = count;
        }
    }
    int m, k;
    for(int i = 0; i < N; i++){
        count = 0;
        k = i;
        m = 0;
        for(int j = 0; j <= N - i; j++){
            if(array[m][k] == 1){
                count++;
            }
            else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
            m++;
            k++;
        }
        if(count > max){
            max = count;
        }
    }
    for(int i = 1; i < N; i++){
        count = 0;
        m = i;
        k = 0;
        for(int j = 0; j <= N - i; j++){
            if(array[m][k] == 1){
                count++;
            }
            else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
            m++;
            k++;
        }
        if(count > max){
            max = count;
        }
    }
    printf("%d\n", max);
    return 0;
}
