#include "stack.h"
#include<iostream>

int compareSign(char sign)  {
    switch(sign) {
        case '-': return 1;
        case '+': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int main () {
    std::string line;
    std::cout << "Введите математическое выражение" << std::endl;
    std::cin >> line;
    
    bool isFirst = true; 
    int max = 0;
    for (int j = 0, i = 0; i < line.length(); i++) {
        if (line[i] == '(') {
            j++;
            continue;
        }
        if (line[i] == ')' && isFirst) {
            max = j;
            isFirst = false;
            j--;
        } else if (line[i] == ')') j--;
        if (j == 0) isFirst = true;
    }

    Stack operations[max + 1];
    for (int i = 0,j = max; i < line.length(); i++) {
        if (line[i] == '(') j--;
        if (line[i] == ')') j++;
        if (compareSign(line[i])) {
            if (operations[j].isEmpty()) {
                operations[j].push(new Node(line[i]));
            } else if (compareSign(line[i]) >= compareSign(operations[j].peek()->getValue())) {
                operations[j].push(new Node(line[i]));
            } else {
                Node* bufHead = operations[j].peek();
                Node* bufTail;
                while (!operations[j].isEmpty() && compareSign(line[i]) < compareSign(operations[j].peek()->getValue())) {
                    bufTail = operations[j].pop();
                }
                operations[j].push(new Node(line[i]));
                bufTail->setNext(operations[j].peek());
                operations[j] = Stack(bufHead);
            }
        }
    }

    for (Stack oper: operations) {
        oper.print();
    }
    return 0;
}