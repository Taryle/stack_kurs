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

Node* Stack::pop() {
    Node *el = head;
    if (head) {
        head = head->getNext();
    }
    return el;
}

void Stack::push(Node *element) {
    element->setNext(head);
    head = element;
}

void Stack::print() {
    Node *el = head;
    while(el) {
        std::cout << el->getValue() << " ";
        el = el->getNext();
    }
}

Node* Stack::peek() {
    return head;
}

bool Stack::isEmpty() {
    return !head;
}