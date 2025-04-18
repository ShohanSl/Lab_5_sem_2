// 1. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти
// максимальный отрицательный элемент стека.
// 2. Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
// стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных
// стеков сформировать третий стек упорядоченный по убыванию
// 3. В текстовом файле записаны строки – арифметические выражения. Числа – вещественные,
// знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения
// и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую
// позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»
// Шохан В.К.
// 14.04.2025
#include <stdio.h>
#include <stdlib.h>
#include "./headers/inputFuncs.h"
#include "./headers/stackFuncs.h"

void firstTask(){ // Первое задание
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
        else if (command==3){
            maxNegInt(top, currentLength);
            freeStack(top);
            return;
        }
        else if (command==0){
            freeStack(top);
            return;
        }
        else printf("\nUnknown command. Please try again\n");
    }
}

void secondTask(){  // Второе задание
    ELEMENT* firstTop = malloc(sizeof(ELEMENT));
    if (firstTop==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    firstTop->next=NULL;
    ELEMENT* secondTop = malloc(sizeof(ELEMENT));
    if (secondTop==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    secondTop->next=NULL;
    ELEMENT* thirdTop = malloc(sizeof(ELEMENT));
    if (thirdTop==NULL){
        printf("\nThere is any error with the memory\n");
        return;
    }
    thirdTop->next=NULL;
    int command, firstLength=0, secondLength=0;
    while(1){
        printf("\nMENU\n\nChoose operation:\n1 - input first stack\n2 - input second stack\
\n3 - show elements of first stack\n4 - show elements of second stack\n5 - create third stack\n0 - exit");
        command=positiveIntInput();
        if (command==1) firstLength=inpFirstStack(&firstTop, firstLength);
        else if (command==2) secondLength=inpSecStack(&secondTop, secondLength);
        else if (command==3) showElements(firstTop, firstLength);
        else if (command==4) showElements(secondTop, secondLength);
        else if (command==5){
            createThirdStack(firstTop, secondTop, &thirdTop, firstLength, secondLength);
            freeStack(firstTop);
            freeStack(secondTop);
            freeStack(thirdTop);
            return;
        }
        else if (command==0){
            freeStack(firstTop);
            freeStack(secondTop);
            freeStack(thirdTop);
            return;
        }
        else printf("\nUnknown command. Please try again\n");
    }
}

void thirdTask(){  // Третье задание

}

void main(){        // Меню
    int command;
    while(1){
        printf("\nMENU\n\nChoose operation:\n1 - first task\n2 - second task\
\n3 - third task\n0 - exit");
        command=positiveIntInput();
        if (command==1) firstTask();
        else if (command==2) secondTask();
        else if (command==3) thirdTask();
        else if (command==0) return;
        else printf("\nUnknown command. Please try again\n");
    }
}
