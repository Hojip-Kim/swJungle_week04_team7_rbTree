#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
}Node;

int sizeOf(Node *node){
    int cnt = 0;
    Node *cur = node->next; // 첫번째 노드 = head이므로, cur = 0번 인덱스

    while(cur != NULL){
        cur = cur->next; 
        cnt++; 
    }
    
    return cnt;
}

void Add(Node *node, int data){
    Node *newNode = malloc(sizeof(Node));
    if(sizeOf(node) == 0){

        newNode->next = NULL;
        newNode->prev = node;
        newNode->data = data;
        node->next = newNode;

    }else{

        Node *cur = node; // 헤드
        while(cur->next != NULL){
            cur = cur->next;
        }
        //cur->next가 null인상태로 왔음. 즉 cur의 next로 무언가 올 수 있다는것임.
        newNode->next = NULL;
        newNode->prev = cur;
        newNode->data = data;
        cur->next = newNode;

    }
}


int Get(Node *node, int idx){
    if(idx <= sizeOf(node)-1 && idx >= 0){ // index의 위치가 정상적으로 node의 length범위내에 들어와있다면, index가 음수가 아니라면
        if((float)(sizeOf(node)-1)/2 >= idx){ // idx가 중앙보다 왼쪽에있거나 같다면
            Node *cur = node->next;
            while(idx >= 0){
                cur = cur->next;
                idx--;
        }
        else{
            Node *cur = node->prev;
        }
    }
}

void Set(Node *node, int idx, int data){

}

void Delete(Node *node, int idx){

}

int main(){
    Node *list = malloc(sizeof(Node));
    list->next = NULL;
    list->prev = NULL;

    Add(list, 1);
    Add(list, 2);
    Add(list, 3);
    printf("%d\n", sizeOf(list));

    return 0;
}
