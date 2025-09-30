#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <utility>  // for std::pair
#include <stdexcept>
#include <functional> // for std::hash

template <typename Key, typename Value>
class HashMap {
private:
    static const size_t DEFAULT_BUCKETS = 16;

    using Pair = std::pair<Key, Value>;
    using Bucket = std::list<Pair>;

    std::vector<Bucket> buckets;
    size_t num_elements;

    size_t hash(const Key& key) const {
        return std::hash<Key>{}(key) % buckets.size();
    }

public:
    HashMap(size_t bucket_count = DEFAULT_BUCKETS) : buckets(bucket_count), num_elements(0) {}

    void put(const Key& key, const Value& value) {
        size_t index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value; // update existing key
                return;
            }
        }
        buckets[index].emplace_back(key, value); // insert new key
        num_elements++;
    }

    Value& get(const Key& key) {
        size_t index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    const Value& get(const Key& key) const {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(const Key& key) const {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    void remove(const Key& key) {
        size_t index = hash(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                num_elements--;
                return;
            }
        }
        throw std::out_of_range("Key not found");
    }

    size_t size() const {
        return num_elements;
    }

    bool empty() const {
        return num_elements == 0;
    }
};

#endif // HASHMAP_H
