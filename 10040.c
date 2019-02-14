#include <stdio.h>
#include <string.h>
int main(){
    int n, q;
    scanf("%d", &n);
    char str[n][51];
    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
    scanf("%d", &q);
    char str1[51];
    int count = 0;
    for(int i = 0; i < q; i++){
        scanf("%s", str1);
        count = 0;
        for(int j = 0; j < n; j++){
            if(strstr(str[j], str1) != NULL){
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
