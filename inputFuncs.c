#include <stdio.h>
#include <stdlib.h>
#include "./headers./inputFuncs.h"

int positiveIntInput(){  //Ввод положительного целого числа
    int res = 0, wrong = 0, isInputed = 0, noInput = 0;
    char inp;
    while(1){
        printf("\n\n>>");
        while(1){
            inp=getchar();
            if (inp=='\n'&&isInputed==0){
                noInput = 1;
                break;
            }
            else if (inp=='\n') break;
            else if (inp<48||inp>57){
                wrong = 1;
                break;
            }
            else{
                res = res*10+(inp-'0');
                isInputed = 1;
            }
        }
        if (wrong==0&&noInput==0){
            break;
        }
        else if (noInput==1){
            printf("\n\nInput error. Please try again\n\n");
            noInput = 0;
        }
        else{
            printf("\n\nInput error. Please try again\n\n");
            res = wrong = isInputed = 0;
            while(getchar()!='\n');
        }
    }
    return res;
}

int intInput(){     // Ввод любого целого числа
    int res = 0, wrong = 0, isInputed = 0, noInput = 0, negative = 0;
    char inp;
    while(1){
        printf("\n\n>>");
        while(1){
            inp=getchar();
            if (inp=='\n'&&isInputed==0){
                noInput = 1;
                break;
            }
            else if (inp=='\n') break;
            else if (inp=='-'&&negative==0) negative=1;
            else if (inp<48||inp>57){
                wrong = 1;
                break;
            }
            else{
                res = res*10+(inp-'0');
                isInputed = 1;
            }
        }
        if (wrong==0&&noInput==0){
            if (negative==1){
                res=-res;
            }
            break;
        }
        else if (noInput==1){
            printf("\n\nInput error. Please try again\n\n");
            noInput = negative = 0;
        }
        else{
            printf("\n\nInput error. Please try again\n\n");
            res = wrong = isInputed = negative = 0;
            while(getchar()!='\n');
        }
    }
    return res;
}

// void nameInput(char* name){  //Ввод текста в виде динамического массива
//     int i = 0;
//     char inp, txt=".txt";
//     while(1){
//         if (i==0){
//             printf("\n\n>>");
//         }
//         inp=getchar();
//         if (inp=='\n'&&i!=0){
//             break;
//         }
//         else if (inp=='\n'){
//             printf("\nInput error. Please try again");
//         }
//         else{
//             name[i]=inp;
//             i++;
//             name=(char*)realloc(name, (i+1)*sizeof(char));
//             if (!name) {
//                 printf("Memory allocation error\n");
//                 return;
//             }
//         }
//     }
//     name=(char*)realloc(name, (i+4)*sizeof(char));
//     for (int k=1; k<=3; k++){
//         name[i+k]=
//     }
// }
