/*
Created by Phome Myint Thu on 3/18/2024.
Assignment 10
 1) header file for link list and stack

*/

#ifndef DDSA_MYHEADER_H
#define DDSA_MYHEADER_H


#include "stdio.h"
#include "stdlib.h"


#define size 10

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head =NULL;
int data[size];
int total_data = 0;
int new_insert_data = 0;

struct Stack{
    int items[size];
    int top;

};

//for link list

void menu();
struct Node* createNode(int newData);
void insertAtBeginning(struct Node** head,int newData);
void append(struct Node** head, int newData);
void allData(struct Node* node);
void show_forward_data(struct Node* node);
void show_backward_data(struct Node* node);
void get_data_from_user();
void add_data_to_doubleLL();
void deleteNode(struct Node** head , int key);


//for stack

void initialize(struct Stack *stack);
int isFull(struct Stack*stack);
int isEmpty(struct Stack*stack);
void push(struct Stack*stack, int value);
int pop(struct Stack*stack);
int peek(struct Stack*stack);

struct Node* createNode(int newData){

    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node) );
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head,int newData){

    struct Node* newNode = createNode(newData);
    newNode->next=*head;
    if(*head != NULL){

        (*head)->prev = newNode;

    }
    *head = newNode;
}

void append(struct Node** head, int newData){

    struct Node* newNode = createNode(newData);
    struct Node* last = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newNode;

    newNode->prev = last;

}

void allData(struct Node* node){
    int choice=0;
    struct Node* last = node;
    printf("\nHow do you want to display?\nPress 1: Display Forward\nPress 2: Display Backward\nEnter: ");
    scanf("%d",&choice);
    if (choice==1) {
        show_forward_data(head);
    } if (choice==2){
        show_backward_data(head);

    }

}

void show_forward_data(struct Node* node){
    if (node == NULL) {
        return;
    }
    while (node != NULL) {
        printf("Data : %d\n", node->data);
        node = node->next;
    }

}

void show_backward_data(struct Node* node){
    struct Node* last = node;
    if (node == NULL) {
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }

    while (last != NULL) {

        printf("Data : %d\n", last->data);
        last = last->prev;
    }

}

void get_data_from_user(){
    new_insert_data = 0;
    printf("\nHow many integer you want to add in double linked list.\nEnter: ");
    scanf("%d",&new_insert_data);
    int total = total_data + new_insert_data;
    if (total > size){
        printf("\nYour intergers are over loaded! Please type below %d integers\n",total_data);
        get_data_from_user();
    }
    for (int i=0; i<new_insert_data; i++){
        printf("Enter %d number: ",i+1);
        scanf("%d",&data[i]);
    }


}

void add_data_to_doubleLL(){
    int choice = 0;
    choice:
    printf("Please choice which type you want to add data.\nPress 1 for insert at the beginning.\nPress 2 for insert to append.\nEnter:");
    scanf("%d",&choice);
    if (choice == 1){
        get_data_from_user();
        for (int i=0; i<new_insert_data; i++){
            insertAtBeginning(&head,data[i]);
            total_data++;
        }


    } else if (choice == 2){
        get_data_from_user();
        for (int i=0; i<new_insert_data; i++){
            append(&head,data[i]);
            total_data++;
        }

    } else {

        printf("\nWrong number! Please choose again.\n");
        goto choice;
    }


}

void deleteNode(struct Node** head , int key){

    struct Node* temp =*head , *prev = NULL, *next = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next ;
        (*head)->prev = NULL;
        free(temp);
        total_data--;
        return;

    }

    while (temp !=NULL && temp->data != key){

        prev = temp ;
        temp = temp->next;
        next = temp->next;

    }

    if(temp==NULL)return;
    if (temp->next!=NULL) {

        prev->next = temp->next;
        next->prev = prev;

    } else {
        prev->next = NULL;

    }


    free(temp);
    total_data--;

}


void initialize(struct Stack *stack){
    stack->top = -1;

}

int isFull(struct Stack*stack){
    return (stack->top == size-1);

}

int isEmpty(struct Stack*stack){

    return (stack->top==-1);

}

void push(struct Stack*stack, int value){

    if (isFull(stack)){
        printf ("StackoverFlow!\n");
        exit ( 1);

    } else {
        stack->items[++stack->top]=value;
        printf("Value inserted to place->%d : Value = %d\n", stack->top, stack->items[stack->top]);

    }


}

int pop(struct Stack*stack){
    if(isEmpty(stack)){
        printf("StackunderFlow!\n");
        exit( 1);

    } else {

        return stack->items[stack->top--];

    }

}

int peek(struct Stack*stack){
    if(isEmpty(stack)){
        printf("Stack have no data!\n");
        return -1;

    } else {

        return stack->items[stack->top];

    }

}

void print_stack(struct Stack*stack){
    for (int i=0; i<size; i++){
        if(isEmpty(stack)) {
            exit( 1);
        } else {
            printf("Value inserted to place->%d : Value = %d\n", stack->top, stack->items[--stack->top]);

        }

    }

}

#endif //DDSA_MYHEADER_H
