#include <stdio.h>
int main(){
    int n;
    int input;
    scanf("%d", &n);
    int check[n];
    for(int i = 0; i < n; i++){
        check[i] = 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        if(check[input] == 1){
            printf("%d", input);
            break;
        }
        else{
            check[input] = 1;
        }
    }
    return 0;
}
