/**
    Question: The task is to design and implement methods of an LRU(least recently used) cache. 
    The class has two methods get() and set() which are defined as follows. get(x): Gets the value 
    of the key x if the key exists in the cache otherwise returns -1. set(x,y): Inserts the value 
    if the key x is not already present. If the cache reaches its capacity it should invalidate the 
    least recently used item before inserting the new item. In the constructor of the class, the 
    size of the cache should be initialized
*/

#include<bits/stdc++.h>

using namespace std;

class LRUCache {
private:
    int cacheCapacity;
    map<int, pair<int, int>> cache; // <Key, <Value, TimeStamp> >
    int timestamp;

    int getKeyWithLowestTimestamp() {
        int lowestTimestamp = INT_MAX;
        int lowestTimeKey = -1;
        for(auto it: cache) {
            if(it.second.second < lowestTimestamp) {
                lowestTimestamp = it.second.second;
                lowestTimeKey = it.first;
            }
        }

        return lowestTimeKey;
    }

public:
    LRUCache(int capacity) {
        this->cacheCapacity = capacity;
        // cache.clear();
        timestamp = 0;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        return cache[key].first;
    }

    void set(int key, int value) {
        timestamp++;
        if(cache.size() < cacheCapacity) {
            cache[key] = { value, timestamp };
        } else {
            int lowestTimeKey = getKeyWithLowestTimestamp();
            cache.erase(lowestTimeKey);
            cache[key] = { value, timestamp };
        }
    }

    void displayCache() {
        cout<<"===========Cache==========="<<endl;
        for(auto it: cache) {
            cout<<" Key: " <<it.first
                <<" Value: "<<it.second.first
                <<" Timstamp: "<<it.second.second
                <<endl;
        }
        cout<<"==========================="<<endl;
    }

};

int main() {
    int val;
    int cacheCapacity = 3;
    LRUCache lru(cacheCapacity);

    lru.set(8, 800);
    lru.set(5, 500);
    lru.set(2, 200);
    lru.displayCache();
    cout<<"get(5): "<<lru.get(5)<<endl;
    cout<<"get(9): "<<lru.get(9)<<endl;

    lru.set(6, 600);
    lru.set(4, 400);
    lru.displayCache();

    return 0;
}