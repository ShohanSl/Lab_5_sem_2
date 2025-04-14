#include <stdio.h>
#include <stdlib.h>
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
