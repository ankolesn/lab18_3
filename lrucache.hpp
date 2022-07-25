//
// Created by ankolesn on 23.07.22.
//

#ifndef LAB18_3_LRUCACHE_HPP
#define LAB18_3_LRUCACHE_HPP
#include <fstream>
#include <unordered_map>
#include <string>
#include <list>

template<typename T>
class LRU_Cache {
private:
    std::list<T> l;
    std::unordered_map<T, typename std::list<T>::iterator> mp;
    size_t m_size;

public:
    explicit LRU_Cache(size_t size);

    void has(const T &address);

    bool put(const T &address);


    friend std::ostream& operator << (std::ostream& out, const LRU_Cache<T> & lru){
        for (auto &i: lru.l) {
            out << "Value: " << i << std::endl;
        }
        return out;
    }

};

template<typename T>
inline LRU_Cache<T>::LRU_Cache(size_t size) {
    m_size = size;
}

template<typename T>
inline bool LRU_Cache<T>::put(const T &address) {
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

template<typename T>
inline void LRU_Cache<T>::has(const T &address) {
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



#endif //LAB18_3_LRUCACHE_HPP
