#include <stdio.h>
void swap(int *a, int *b);
void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
    return;
}
void permutation(int *num, int now, int n);
void permutation(int *num, int now, int n){
    if(now == n - 1){
        for(int i = 0; i < n - 1; i++){
            printf("%d ", *(num + i));
        }
        printf("%d\n", *(num + n - 1));
    }
    else{
        for(int i = now; i < n; i++){
            int temp = *(num + i);
            int k, a;
            a = *(num + now);
            for(int j = now; j < i; j++){
                k = a;
                a = *(num + j + 1);
                *(num + j + 1) = k;
            }
            *(num + now) = temp;
            permutation(num, now + 1, n);
            for(int j = now; j < i; j++){
                *(num + j) = *(num + j + 1);
            }
            *(num + i) = temp;
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(num[i] > num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    permutation(num, 0, n);
    return 0;
}
