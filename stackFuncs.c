#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./headers/stackFuncs.h"
#include "./headers/inputFuncs.h"

void addElement(ELEMENT* top, int maxLength, int* currentLength){   // Добавление нового элемента стека
    if (*currentLength==maxLength){
        printf("\nIt's already a maximum number of elements\n");
        return;
    }
    int data;
    printf("\nInput an integer:\n");
    data=intInput();
    ELEMENT* newElement = malloc(sizeof(ELEMENT));
    if (newElement==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    newElement->next=top->next;
    newElement->data=data;
    top->next=newElement;
    (*currentLength)++;
    return;
}

void addElementInDescending(ELEMENT* top, int maxLength, int* currentLength){  // Добавление элемента по убыванию
    if (*currentLength==maxLength){
        printf("\nIt's already a maximum number of elements\n");
        return;
    }
    int data, lastData;
    if (top->next!=NULL){
        ELEMENT* lastElement = malloc(sizeof(ELEMENT));
        lastElement=top->next;
        lastData=lastElement->data;
    }
    else lastData=INT_MAX;
    while(1){
        printf("\nInput an integer:\n");
        data=intInput();
        if (data<=lastData) break;
        else printf("\nA new integer must be less than the last one\n");
    }
    ELEMENT* newElement = malloc(sizeof(ELEMENT));
    if (newElement==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    newElement->next=top->next;
    newElement->data=data;
    top->next=newElement;
    (*currentLength)++;
    return;
}

void addElementInAscending(ELEMENT* top, int maxLength, int* currentLength){  // Добавление элемента по возрастанию
    if (*currentLength==maxLength){
        printf("\nIt's already a maximum number of elements\n");
        return;
    }
    int data, lastData;
    if (top->next!=NULL){
        ELEMENT* lastElement = malloc(sizeof(ELEMENT));
        lastElement=top->next;
        lastData=lastElement->data;
    }
    else lastData=INT_MIN;
    while(1){
        printf("\nInput an integer:\n");
        data=intInput();
        if (data>=lastData) break;
        else printf("\nA new integer must be higher than the last one\n");
    }
    ELEMENT* newElement = malloc(sizeof(ELEMENT));
    if (newElement==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    newElement->next=top->next;
    newElement->data=data;
    top->next=newElement;
    (*currentLength)++;
    return;
}

void showElements(ELEMENT* top, int currentLength){     // Вывод на экран содержимого стека
    int i=0;
    ELEMENT* ptr = top->next;
    if (ptr==NULL){
        printf("\nThere are not elements in stack\n");
        return;
    }
    printf("\nElements of stack:\n\n");
    while(i<currentLength){
        printf("%d\n", ptr->data);
        ptr=ptr->next;
        i++;
    }
    return;
}

void maxNegInt(ELEMENT* top, int currentLength){    // Поиск наибольшего отрицательного числа
    ELEMENT* ptr=top;
    if (ptr->next==NULL){
        printf("\nThere are not elements in stack\n");
        return;
    }
    int i=0, max=0;
    for (i; i<currentLength; i++){
        ptr=ptr->next;
        if ((ptr->data<0)&&(ptr->data>max||max==0)) max=ptr->data;
    }
    if (max==0) printf("\nThere are not negative elements is stack\n");
    else printf("\nMaximum negative integer: %d\n", max);
    return;
}

int inpFirstStack(ELEMENT** firstTop, int firstLength){  // Ввод первого стека для второго задания
    if (firstLength!=0){
        printf("\nStack is already inputed\n");
        return firstLength;
    }
    int command, maxLength, currentLength=0;
    printf("\nEnter a maximum length of stack:\n");
    maxLength=positiveIntInput();
    while(1){
        printf("\nMENU\n\nChoose operation:\n1 - add new element\n2 - show added elements\
\n0 - exit");
        command=positiveIntInput();
        if (command==1) addElementInDescending(*firstTop, maxLength, &currentLength);
        else if (command==2) showElements(*firstTop, currentLength);
        else if (command==0){
            if (currentLength==maxLength) return currentLength;
            else printf("\nPlease finish stack elements inputing\n");
        }
        else printf("\nUnknown command. Please try again\n");
    }
}

int inpSecStack(ELEMENT** secondTop, int secondLength){  // Ввод второго стека для второго задания
    if (secondLength!=0){
        printf("\nStack is already inputed\n");
        return secondLength;
    }
    int command, maxLength, currentLength=0;
    printf("\nEnter a maximum length of stack:\n");
    maxLength=positiveIntInput();
    while(1){
        printf("\nMENU\n\nChoose operation:\n1 - add new element\n2 - show added elements\
\n0 - exit");
        command=positiveIntInput();
        if (command==1) addElementInAscending(*secondTop, maxLength, &currentLength);
        else if (command==2) showElements(*secondTop, currentLength);
        else if (command==0){
            if (currentLength==maxLength) return currentLength;
            else printf("\nPlease finish stack elements inputing\n");
        }
        else printf("\nUnknown command. Please try again\n");
    }
}

void createThirdStack(ELEMENT* firstTop, ELEMENT* secondTop, ELEMENT** thirdTop, int firstLength, int secondLength) {  // Создание третьего стека
    ELEMENT* firstPtr = firstTop->next;
    ELEMENT* secondPtr = secondTop->next;
    int thirdLength = 0;
    ELEMENT* tempSecondStack = NULL;
    ELEMENT* tempSecondTop = malloc(sizeof(ELEMENT));
    tempSecondTop->next = NULL;
    while (secondPtr != NULL) {
        ELEMENT* newElement = malloc(sizeof(ELEMENT));
        newElement->data = secondPtr->data;
        newElement->next = tempSecondTop->next;
        tempSecondTop->next = newElement;
        secondPtr = secondPtr->next;
    }
    secondPtr = tempSecondTop->next;
    while (firstPtr != NULL && secondPtr != NULL) {
        if (firstPtr->data <= secondPtr->data) {
            ELEMENT* newElement = malloc(sizeof(ELEMENT));
            newElement->data = firstPtr->data;
            newElement->next = (*thirdTop)->next;
            (*thirdTop)->next = newElement;
            firstPtr = firstPtr->next;
        } else {
            ELEMENT* newElement = malloc(sizeof(ELEMENT));
            newElement->data = secondPtr->data;
            newElement->next = (*thirdTop)->next;
            (*thirdTop)->next = newElement;
            secondPtr = secondPtr->next;
        }
        thirdLength++;
    }
    while (firstPtr != NULL) {
        ELEMENT* newElement = malloc(sizeof(ELEMENT));
        newElement->data = firstPtr->data;
        newElement->next = (*thirdTop)->next;
        (*thirdTop)->next = newElement;
        firstPtr = firstPtr->next;
        thirdLength++;
    }
    while (secondPtr != NULL) {
        ELEMENT* newElement = malloc(sizeof(ELEMENT));
        newElement->data = secondPtr->data;
        newElement->next = (*thirdTop)->next;
        (*thirdTop)->next = newElement;
        secondPtr = secondPtr->next;
        thirdLength++;
    }
    ELEMENT* tempPtr = tempSecondTop->next;
    while (tempPtr != NULL) {
        ELEMENT* toDelete = tempPtr;
        tempPtr = tempPtr->next;
        free(toDelete);
    }
    free(tempSecondTop);
    printf("\nThird stack created with %d elements\n", thirdLength);
    showElements(*thirdTop, thirdLength);
}

void freeStack(ELEMENT* top) {  // Освобождение памяти от стека
    ELEMENT* ptr = top;
    while (ptr != NULL) {
        ELEMENT* toDelete = ptr;
        ptr = ptr->next;
        free(toDelete);
    }
}
