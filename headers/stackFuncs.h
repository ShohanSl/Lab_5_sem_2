#ifndef STACKFUNCS_H
#define STACKFUNCS_H

typedef struct StackElement{
    int data;
    struct StackElement* next;
}ELEMENT;

void addElement();

void showElements();

void maxNegInt();

#endif