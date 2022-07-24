//
// Created by ankolesn on 23.07.22.
//

#include "lrucache.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

LRU_Cache::LRU_Cache(size_t size) {
    m_size = size;

}

bool LRU_Cache::put(const std::string &address) {
    auto it = mp.find(address);
    if (it != mp.end()) {
        auto list_it = it->second;
        l.splice(l.end(), l, list_it);
        return false;
    }
    if (l.size() == m_size) {
        auto last = l.front();
        mp.erase(last);
        l.front() = address;
        l.splice(l.end(), l, l.begin());
        mp[address] =--l.end();
    } else {
        mp[address] = l.insert(l.end(), address);
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const LRU_Cache &lru) {
    for (auto &i: lru.l) {
        out << "Value: " << i << std::endl;
    }
    return out;
}

void LRU_Cache::has(const std::string &address) {
    if (l.size() == m_size) {
        auto last = l.front();
        mp.erase(last);
        l.front() = address;
        l.splice(l.end(), l, l.begin());
        mp[address] =--l.end();
    } else {
        mp[address] = l.insert(l.end(), address);
    }
}
