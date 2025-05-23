#include "stack.h"
#include<iostream>
#include<fstream>

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
    std::ifstream in("mathWord");
    if (in.is_open()) in >> line;
    in.close();
    
    // Цикл для подсчета глубины скобок
    int max = 0;
    int currentDepth = 0;
    for (char c : line) {
        if (c == '(') {
            currentDepth++;
            max = std::max(max, currentDepth);
        } else if (c == ')') {
            currentDepth--;
            if (currentDepth < 0) {
                currentDepth = 0;
            }
        }
    }

    Stack operations[max + 1]; // Используется массив Stack для каждой глубины
    for (int i = 0,j = max; i < line.length(); i++) { // Цикл для обхода каждой глубины
        if (line[i] == '(') j--; // Увеличение глубины при открытие скобок
        if (line[i] == ')') j++; // Уменьшение глубины при открытие скобок
        if (compareSign(line[i])) {
            if (operations[j].isEmpty()) { // Добавление первого оператора
                operations[j].push(line[i]);
            } else if (compareSign(line[i]) >= compareSign(operations[j].peek())) { // Добавление последующих операторов, если они больше или равных по приоритету
                operations[j].push(line[i]);
            } else {
                // Добавление последующих операторов, если они меньше по приоритету 
                Stack buf;
                while (!operations[j].isEmpty() && compareSign(line[i]) < compareSign(operations[j].peek())) {
                    buf.push(operations[j].pop());
                }
                operations[j].push(line[i]);
                while(!buf.isEmpty()) {
                    operations[j].push(buf.pop());
                }
            }
        }
    }

    std::cout << line << std::endl;
    for (Stack oper: operations) {
        oper.print();
    }
    return 0;
}