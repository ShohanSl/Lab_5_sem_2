// Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти
// максимальный отрицательный элемент стека.
// Шохан В.К.
// 14.04.2025
#include <stdio.h>
#include <stdlib.h>
#include "./headers/inputFuncs.h"
#include "./headers/stackFuncs.h"

void main(){        // Меню
    int command, maxLength, currentLength=0;
    printf("\nEnter a maximum length of stack:\n");
    maxLength=positiveIntInput();
    ELEMENT* top = malloc(sizeof(ELEMENT));
    if (top==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    top->next=NULL;
    while(1){
        printf("\nMENU\n\nChoose operation:\n1 - add new element\n2 - show added elements\
\n3 - find maximum negative integer\n0 - exit");
        command=positiveIntInput();
        if (command==1) addElement(top, maxLength, &currentLength);
        else if (command==2) showElements(top, currentLength);
        else if (command==3) maxNegInt(top, currentLength);
        else if (command==0) return;
        else printf("\nUnknown command. Please try again\n");
    }
}