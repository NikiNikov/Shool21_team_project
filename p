#include <stdio.h>
#include <string.h>

#define MAX_X 81
#define MAX_Y 25

void infixNotationToReversePolishNotation(char *in);

void ReversePolishNotationToValue(char *rpn, float currentValue);

void init_screen(char screen[MAX_Y][MAX_X]);

int main() {
    

    char screen[MAX_Y][MAX_X];
    init_screen(screen);
    
return 0;
}
    


void ReversePolishNotationToValue(char *rpn, float currentValue) {
//    stack<int> stk;
//    string str = "";
    
    for (int i = 0; i < strlen(rpn); ++i) {
        
        if ((rpn[i] > 47 && rpn[i] < 58) || rpn[i] == 'x') {
//           ; rpn.push(rpn[i] - 48);
        } else if ( rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/' || rpn[i] == '^') {
            float a, b;
            
            a = stk.top();
            if (a == 78)
                a = currentValue;
            stk.pop();
            b = stk.top();
            if (b == 78)
                a = currentValue;
            stk.pop();
            
            if (rpn[i] == '+')
                a = b + a;
            else if (rpn)
        }
    }
}
