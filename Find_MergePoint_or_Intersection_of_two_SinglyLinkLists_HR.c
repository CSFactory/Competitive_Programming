#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int merge_point_value = -1;
    SinglyLinkedListNode* current1, *current2;
    current1=head1;
    current2=head2;
    int count1=0,count2=0;
    while(current1){
        current1 = current1->next;
        count1++;
    }
    while(current2){
        current2=current2->next;
        count2++;
    }
    int arr1[count1];
    int arr2[count2];
    for(int i=0;i<count1;i++){
        arr1[i] = head1->data;
        head1 = head1->next;
    }
    for(int j=0;j<count2;j++){
        arr2[j] = head2->data;
        head2 = head2->next;
    }
    int l,k;
    count1 = count1-1;
    count2 = count2-1;
    for(l=count1,k=count2;l>=0,k>=0;l--,k--){
        if(arr1[l]!=arr2[k]){
            merge_point_value = arr1[l+1];
            break;
        }
        else if ((arr1[l]==arr2[k]) && (l==0) && (k==0)) { //base case //when all values are equal.
            merge_point_value = arr1[l+1];
        }
    }
return merge_point_value;
}

int main()
