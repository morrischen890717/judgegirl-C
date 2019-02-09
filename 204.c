#include <stdio.h>
int main(){
    int W, D;
    scanf("%d%d", &W, &D);
    int a[D][W];
    for(int i = 0; i < D; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int new_dir[4] = {3, 2, 1, 0};//up, down, left, right;
    for(int i = 0; i < W; i++){
        int now_r = D - 1;
        int now_c = i;
        int direction = 0;
        while(now_r < D && now_r >= 0 && now_c < W && now_c >= 0){
            if(a[now_r][now_c] == 1){
                direction = new_dir[direction];
            }
            switch(direction){
                case 0:
                    now_r--;
                    break;
                case 1:
                    now_r++;
                    break;
                case 2:
                    now_c--;
                    break;
                case 3:
                    now_c++;
                    break;
            }
        }
        if (now_r >= D){
            printf("%d\n", now_c);
        }
        else if(now_c >= W){
            printf("%d\n", W - 1 + D - now_r);
        }
        else if(now_r == -1){
            printf("%d\n", W + D - 1 + W - now_c);
        }
        else if(now_c == -1){
            printf("%d\n", 2 * W + D - 1 + now_r + 1);
        }
    }
    for(int i = D - 1; i >= 0; i--){
        int now_r = i;
        int now_c = W - 1;
        int direction = 2;
        while(now_r < D && now_r >= 0 && now_c < W && now_c >= 0){
            if(a[now_r][now_c] == 1){
                direction = new_dir[direction];
            }
            switch(direction){
                case 0:
                    now_r--;
                    break;
                case 1:
                    now_r++;
                    break;
                case 2:
                    now_c--;
                    break;
                case 3:
                    now_c++;
                    break;
            }
        }
        if (now_r >= D){
            printf("%d\n", now_c);
        }
        else if(now_c >= W){
            printf("%d\n", W - 1 + D - now_r);
        }
        else if(now_r == -1){
            printf("%d\n", W + D - 1 + W - now_c);
        }
        else if(now_c == -1){
            printf("%d\n", 2 * W + D - 1 + now_r + 1);
        }
    }
    for(int i = W - 1; i >= 0; i--){
        int now_r = 0;
        int now_c = i;
        int direction = 1;
        while(now_r < D && now_r >= 0 && now_c < W && now_c >= 0){
            if(a[now_r][now_c] == 1){
                direction = new_dir[direction];
            }
            switch(direction){
                case 0:
                    now_r--;
                    break;
                case 1:
                    now_r++;
                    break;
                case 2:
                    now_c--;
                    break;
                case 3:
                    now_c++;
                    break;
            }
        }
        if (now_r >= D){
            printf("%d\n", now_c);
        }
        else if(now_c >= W){
            printf("%d\n", W - 1 + D - now_r);
        }
        else if(now_r == -1){
            printf("%d\n", W + D - 1 + W - now_c);
        }
        else if(now_c == -1){
            printf("%d\n", 2 * W + D - 1 + now_r + 1);
        }
    }
    for(int i = 0; i < D; i++){
        int now_r = i;
        int now_c = 0;
        int direction = 3;
        while(now_r < D && now_r >= 0 && now_c < W && now_c >= 0){
            if(a[now_r][now_c] == 1){
                direction = new_dir[direction];
            }
            switch(direction){
                case 0:
                    now_r--;
                    break;
                case 1:
                    now_r++;
                    break;
                case 2:
                    now_c--;
                    break;
                case 3:
                    now_c++;
                    break;
            }
        }
        if (now_r >= D){
            printf("%d\n", now_c);
        }
        else if(now_c >= W){
            printf("%d\n", W - 1 + D - now_r);
        }
        else if(now_r == -1){
            printf("%d\n", W + D - 1 + W - now_c);
        }
        else if(now_c == -1){
            printf("%d\n", 2 * W + D - 1 + now_r + 1);
        }
    }
    return 0;
}
