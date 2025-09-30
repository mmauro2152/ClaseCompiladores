#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> data;

public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const T& value) {
        data.push_back(value);
    }

    void dequeue() {
        if (data.empty()) {
            throw std::out_of_range("Queue underflow: dequeue on empty queue");
        }
        data.erase(data.begin());
    }

    T& front() {
        if (data.empty()) {
            throw std::out_of_range("Queue underflow: front on empty queue");
        }
        return data.front();
    }

    const T& front() const {
        if (data.empty()) {
            throw std::out_of_range("Queue underflow: front on empty queue");
        }
        return data.front();
    }

    T& back() {
        if (data.empty()) {
            throw std::out_of_range("Queue underflow: back on empty queue");
        }
        return data.back();
    }

    const T& back() const {
        if (data.empty()) {
            throw std::out_of_range("Queue underflow: back on empty queue");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

#endif // QUEUE_H
