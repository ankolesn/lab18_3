#include <iostream>
#include "lrucache.hpp"

using namespace std;

int main() {
    LRU_Cache lru(3);

    lru.has("111");
    lru.has("222");
    lru.has("333");
    lru.put("222");
    lru.put("111");
    cout << lru << endl;
}
