#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct node{
    int number;
    struct node* nextNode;
};
void print_list(struct node** pointer){
    struct node* head = *pointer;
    struct node* temp = malloc(sizeof (struct node));
    temp->nextNode = head->nextNode;
    temp->number = head->number;
    if(head->nextNode == NULL){
        return;
    }
    while(temp->nextNode != NULL){
        printf("%d ",temp->number);
        temp = temp->nextNode;
    }
}
void insert_node(struct node** pointer, int data){
    struct node* head = *pointer;
    struct node* temp = malloc(sizeof (struct node));
    temp->nextNode = head->nextNode;
    temp->number = head->number;
    if(head->nextNode == NULL){
        head->nextNode = temp;
    }
    while(temp->nextNode != NULL){
        temp = temp->nextNode;
    }
    temp->number = data;
    struct node* nextN = malloc(sizeof (struct node));
    temp->nextNode = nextN;
    nextN->nextNode = NULL;
}
void delete_node(struct node** pointer, int data){
    struct node* head = *pointer;
    struct node* temp = malloc(sizeof (struct node));
    temp->nextNode = head->nextNode;
    temp->number = head->number;
    struct node* initial = temp->nextNode;
    while(temp->nextNode != NULL){
        if(temp->nextNode->number == data){
            temp->nextNode = temp->nextNode->nextNode;
            head->nextNode = initial;
            break;
        }
        temp = temp->nextNode;
    }
}
int main(){
    struct node* headPointer = malloc(sizeof (struct node));
    headPointer->nextNode = NULL;
    char word[100] = "";
    char *ptr;
    printf("Enter the data to fill the Linked list. At the end print\"exit\"\n");
    while (strcmp(word,"exit") != 0){
        scanf("%s",word);
        if (strcmp(word,"exit") != 0){
            int n = strtol(word,&ptr,10);
            insert_node(&headPointer, n);
        }
    }
    printf("Enter the data to delete from the Linked list. At the end print\"exit\"\n");
    word[1] = "2";
    while (strcmp(word,"exit") != 0){
        scanf("%s",word);
        if (strcmp(word,"exit") != 0){
            int n = strtol(word,&ptr,10);
            delete_node(&headPointer, n);
        }
    }
    print_list(&headPointer);
}
