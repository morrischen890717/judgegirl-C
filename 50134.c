#include <stdio.h>
int main(){
    int type;
    scanf("%d", &type);
    if(type){
        unsigned long long int input;
        char pattern_[5];
        while(scanf("%s", pattern_) != EOF){
            scanf("%llu", &input);
            int now = 0;
            unsigned int LONG_OUTPUT = 0;
            unsigned short SHORT_OUTPUT = 0;
            char a[2];
            char b;
            for(int i = 3; i >= 0; i--){
                switch(pattern_[i]){
                    case 'L':
                        LONG_OUTPUT |= input;
                        input >>= 32;
                        break;
                    case 'S':
                        SHORT_OUTPUT |= input;
                        input >>= 16;
                        break;
                    case 'C':
                        b = 0;
                        b |= input;
                        input >>= 8;
                        a[now] = b;
                        now++;
                        break;
                }
            }
            printf("%u %hu %c%c\n", LONG_OUTPUT, SHORT_OUTPUT, a[1], a[0]);
        }
    }
    else{
        unsigned long long int output = 0;
        char pattern[5];
        unsigned int  LONG_INPUT;
        unsigned short SHORT_INPUT;
        char CHAR_INPUT[3];
        while(scanf("%s", pattern) != EOF){
            scanf("%u%hu%s", &LONG_INPUT, &SHORT_INPUT, CHAR_INPUT);
            int now_char = 0;
            for(int i = 0; i < 4; i++){
                switch(pattern[i]){
                    case 'L':
                        output <<= 32;
                        output |= LONG_INPUT;
                        break;
                    case 'S':
                        output <<= 16;
                        output |= SHORT_INPUT;
                        break;
                    case 'C':
                        output <<= 8;
                        output |= CHAR_INPUT[now_char];
                        now_char++;
                        break;
                }
            }
            printf("%llu\n", output);
        }
    }
    return 0;
}
