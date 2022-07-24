//
// Created by ankolesn on 23.07.22.
//

#ifndef LAB18_3_LRUCACHE_HPP
#define LAB18_3_LRUCACHE_HPP
#include <fstream>
#include <map>
#include <string>
#include <list>

class LRU_Cache {
private:
    std::list<std::string> l;
    std::map<std::string, std::list<std::string>::iterator> mp;
    size_t m_size;

public:
    LRU_Cache(size_t size);

    void has(const std::string &address);

    bool put(const std::string &address); //возвращает true, если адрес найден в кэше

    friend std::ostream& operator << (std::ostream& out, const LRU_Cache& lru);

};


#endif //LAB18_3_LRUCACHE_HPP
