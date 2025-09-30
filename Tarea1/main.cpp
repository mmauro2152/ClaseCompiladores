#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "HashMap.h"

int main() {
    std::cout << "=== STACK TEST ===\n";
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top: " << stack.top() << "\n"; // 30
    stack.pop();
    std::cout << "Top after pop: " << stack.top() << "\n"; // 20
    std::cout << "Stack size: " << stack.size() << "\n\n"; // 2

    std::cout << "=== QUEUE TEST ===\n";
    Queue<std::string> queue;
    queue.enqueue("apple");
    queue.enqueue("banana");
    queue.enqueue("orange");

    std::cout << "Front: " << queue.front() << "\n"; // apple
    std::cout << "Back: " << queue.back() << "\n"; // orange
    queue.dequeue();
    std::cout << "Front after dequeue: " << queue.front() << "\n"; // banana
    std::cout << "Queue size: " << queue.size() << "\n\n"; // 2

    std::cout << "=== HASHMAP TEST ===\n";
    HashMap<std::string, int> map;

    map.put("apple", 3);
    map.put("banana", 5);
    map.put("orange", 2);

    std::cout << "apple: " << map.get("apple") << "\n"; // 3
    std::cout << "banana: " << map.get("banana") << "\n"; // 5

    map.remove("apple");

    std::cout << "Contains apple? " << (map.contains("apple") ? "Yes" : "No") << "\n"; // No
    std::cout << "HashMap size: " << map.size() << "\n";

    return 0;
}
