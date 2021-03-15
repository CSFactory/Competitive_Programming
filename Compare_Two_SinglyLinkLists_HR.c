#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
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

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode * current1, * current2;
    current1 = malloc(sizeof(SinglyLinkedListNode));
    current2 = malloc(sizeof(SinglyLinkedListNode));
    current1 = head1;
    current2 = head2;
    int flag = -1; //Initially flag value is invalid (means neither 0 nor 1)
    int count1=0;
    int count2=0;
    while(head1){ //Traversing 1st SLL
        count1++;
        head1=head1->next;
    }
    while (head2) { //Traversing 2nd SLL
        count2++;
        head2=head2->next;
    }
    if(count1!=count2){ //No: of nodes are not same, so not equal
        flag=0;
    }
    else if (count1==count2) { ///No: of nodes are same, Check for individual data element equality
            for(int i=0;i<count1;i++){
                if(current1->data==current2->data){
                    flag=1;
                    current1=current1->next;
                    current2=current2->next;
                }
                else if (current1->data!=current2->data) {
                    flag=0;
                    break;
                }   
        } 
    }

return flag;
}

int main()
