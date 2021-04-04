#include"..\Headers\calculator.h"
#include"..\Headers\stack.h"

int get_priority(char ch){
    switch (ch) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':  
        return 2;
    case ')':
        return 3;
    }
}

