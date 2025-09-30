#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    Stack() = default;
    ~Stack() = default;

    void push(const T& value);
    void pop();                  
    T& top();                    
    const T& top() const;        

    bool empty() const;         
    size_t size() const;
};



template <typename T>
void Stack<T>::push(const T& value) {
    data.push_back(value);
}

template <typename T>
void Stack<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("Stack underflow: pop on empty stack");
    }
    data.pop_back();
}

template <typename T>
T& Stack<T>::top() {
    if (data.empty()) {
        throw std::out_of_range("Stack underflow: top on empty stack");
    }
    return data.back();
}

template <typename T>
const T& Stack<T>::top() const {
    if (data.empty()) {
        throw std::out_of_range("Stack underflow: top on empty stack");
    }
    return data.back();
}

template <typename T>
bool Stack<T>::empty() const {
    return data.empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return data.size();
}

#endif // STACK_H
