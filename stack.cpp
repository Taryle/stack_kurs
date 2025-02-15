#include<iostream>
#include "stack.h"

Node::Node(char value, Node *next) {
    this->value = value;
    this->next = next;
}

Node::Node(char value):Node(value, nullptr){}

void Node::setValue(char value) {
    this->value = value;
}

void Node::setNext(Node *next) {
    this->next = next;
}

char Node::getValue() {
    return value;
}

Node* Node::getNext() {
    return next;
}

Stack::Stack(Node * head) {
    this->head = head;
}

Stack::Stack() {
    head = nullptr;
}

char Stack::pop() {
    Node *el = head;
    if (head) {
        head = head->getNext();
        el->setNext(nullptr);
        return el->getValue();
    } else {
        std::cout << "Error, you can't pop empty stack" << std::endl;
        return '\0';
    }
}

void Stack::push(char element) {
    Node *node = new Node(element);
    node->setNext(head);
    head = node;
}

void Stack::print() {
    Node *el = head;
    while(el) {
        std::cout << el->getValue() << " ";
        el = el->getNext();
    }
}

char Stack::peek() {
    return head->getValue();
}

bool Stack::isEmpty() {
    return !head;
}