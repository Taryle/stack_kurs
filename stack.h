#include<iostream>

class Node {
public:
    Node(char value, Node *next);
    Node(char value);
    void setValue(char value);
    void setNext(Node *next);
    char getValue();
    Node* getNext();
private:
    char value;
    Node *next;
};
class Stack {
public:
    Stack(Node* head);
    Stack();
    char pop();
    void push(char element);
    char peek();
    void print();
    bool isEmpty();
private:
    Node* head;
};