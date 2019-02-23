#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
Node *construct(Node *root, char instruction[]){
    int length;
    length = strlen(instruction);
    Node *current;
    current = root;
    if(current == NULL){
            Node *ptr = malloc(sizeof(Node));
            current = ptr;
            current->data = 1;
            current->left = NULL;
            current->right = NULL;
            root = current;
    }
    else{
        current->data++;
    }
    for(int i = 0; i < length; i++){
        switch(instruction[i]){
            case 'R':
                if(current->right == NULL){
                    Node *ptr = malloc(sizeof(Node));
                    assert(ptr != NULL);
                    current->right = ptr;
                    current = current->right;
                    current->data = 1;
                    current->right = NULL;
                    current->left = NULL;
                }
                else{
                    current = current->right;
                    current->data++;
                }
                break;
            case 'L':
                if(current->left == NULL){
                    Node *ptr = malloc(sizeof(Node));
                    current->left = ptr;
                    current = current->left;
                    current->data = 1;
                    current->right = NULL;
                    current->left = NULL;
                }
                else{
                    current = current->left;
                    current->data++;
                }
                break;
        }
    }
    return root;
}
int query(Node *root, char instruction[]){
    Node *current = malloc(sizeof(Node));
    assert(current != NULL);
    current = root;
    int length = strlen(instruction);
    for(int i = 0; i < length; i++){
        if(current == NULL){
            return 0;
        }
        else{
            switch(instruction[i]){
                case 'R':
                    current = current->right;
                    break;
                case 'L':
                    current = current->left;
                    break;
            }
        }
    }
    if(current == NULL){
        return 0;
    }
    else{
        return current->data;
    }
}
