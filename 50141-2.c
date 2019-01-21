#include <stdio.h>
#include <stdlib.h>
#ifndef MERGE_H
#define MERGE_H
typedef struct node {
    int data;
    struct node *next;
}Node;
Node *merge(Node *list[], int K);
#endif
Node *merge(Node *list[], int K){
        Node *now[K];
        Node *temp;
        for(int i = 0; i < K; i++){
                now[i] = list[i];
        }
        int pre = -1;
        int start = 0;
        int count = 0;
        Node *head;
        while(count < K){
                for(int i = 0; i < K; i++){
                        if(now[i]!=NULL){
                                if(start == 0){
                                        head = now[i];
                                        pre = i;
                                        start = 1;
                                        continue;
                                }
                                else{
                                        if(pre == i){
                                                if(now[pre]->next == NULL){
                                                        count++;
                                                        continue;
                                                }
                                                else{
                                                        now[pre] = now[pre]->next;
                                                        continue;
                                                }
                                        }
                                        // if(now[pre]==NULL) printf("hi\n");
                                        temp = now[pre]->next;
                                        now[pre]->next = now[i];
                                        now[pre] = temp;
                                        pre = i;
                                }
                        }
                        else{
                                count++;
                        }
                }
                if(count == K){
                        break;
                }
                else{
                        printf("count1  = %d\n", count);
                        count = 0;
                }
                for(int i = K - 1; i >= 0; i--){
                        // printf("%dhi\n",i);
                        if(now[i] != NULL){
                                if(pre == i){
                                        if(now[pre]->next == NULL){
                                                count++;
                                                continue;
                                        }
                                        else{
                                        now[pre] = now[pre]->next;
                                        }
                                }
                                // else if(now[pre]==NULL) printf("need\n");
                                else{
                                        // if(now[pre]==NULL) printf("hello\n");
                                        temp = now[pre]->next;
                                        now[pre]->next = now[i];
                                        now[pre] = temp;
                                        pre = i;
                                }
                        }
                        else{
                                count++;
                        }
                }
                if(count == K){
                        break;
                }
                else{
                        printf("count = %d\n", count);
                        count = 0;
                }
        }
        return head;
}
int main () {
        int K;
        scanf("%d", &K);
        Node *list[K];
        for (int i = 0; i < K; i++) {
                int N;
                scanf("%d", &N);
                if (N == 0) {
                        list[i] = NULL;
                        continue;
                }
                list[i] = (Node *)malloc(sizeof(Node));
                scanf("%d", &(list[i]->data));
                list[i]->next = NULL;
                Node *previous = list[i];
                for (int j = 1; j < N; j++) {
                        previous->next = (Node *)malloc(sizeof(Node));
                        scanf("%d", &(previous->next->data));
                        previous->next->next = NULL;
                        previous = previous->next;
                }
        }
        Node *result = merge(list, K);
        while (result) {
                printf("%d", result->data);
                result = result->next;
                printf("%c", result ? ' ' : '\n');
        };
        return 0;
}
