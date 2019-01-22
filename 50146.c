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
        Node *head = NULL;
        Node *now;
        int count = 0;
        for(int i = 0; i < K; i++){
                if(list[i] == NULL){
                        count++;
                }
        }
#ifdef ZIGZAG
        while(count < K){
                for(int i = 0; i < K; i++){
                        if(list[i] == NULL){
                                continue;
                        }
                        else if(head == NULL){
                                head = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                        else{
                                now->next = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                }
                for(int i = K - 1; i >= 0; i--){
                        if(list[i] == NULL){
                                continue;
                        }
                        else{
                                now->next = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                }
        }
#endif
#ifdef TOPDOWN
        while(count < K){
                for(int i = 0; i < K; i++){
                        if(list[i] == NULL){
                                continue;
                        }
                        else if(head == NULL){
                                head = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                        else{
                                now->next = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                }
        }
#endif
#ifdef BOTTOMUP
        while(count < K){
                for(int i = K - 1; i >= 0; i--){
                        if(list[i] == NULL){
                                continue;
                        }
                        else if(head == NULL){
                                head = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                        else{
                                now->next = list[i];
                                now = list[i];
                                list[i] = list[i]->next;
                                if(list[i] == NULL){
                                        count++;
                                }
                        }
                }
        }
#endif
        now->next = NULL;
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
