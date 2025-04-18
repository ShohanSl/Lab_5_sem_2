#ifndef STACKFUNCS_H
#define STACKFUNCS_H

typedef struct StackElement{
    int data;
    struct StackElement* next;
}ELEMENT;

void addElement();

void addElementInDescending();

void addElementInAscending();

void showElements();

void maxNegInt();

int inpFirstStack();

int inpSecStack();

void createThirdStack();

void freeStack();

#endif