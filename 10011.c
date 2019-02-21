#include <stdio.h>
int main(){
    int n;
    int arr;
    int count = 0;
    scanf("%d", &n);
    int first = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr);
        if(arr){
            if(!first) {
                printf("%d", arr);
                first = 1;
            }
            else {
                printf(" %d", arr);
            }
        }
        else{
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        printf(" 0");
    }
    return 0;
}
