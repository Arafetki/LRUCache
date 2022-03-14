#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

class LRUcache{
private:
    unordered_map<int,int> cache;
    int Capacity;
    deque<int>dq;
public:
    LRUcache(int c):Capacity(c){
    }
    int get(int key) {
        // not found
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            // found
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            dq.erase(it);
            dq.push_front(key);

            return cache[key];
        }
    }
    void put(int key,int value){
        if(cache.find(key)==cache.end()){
            if (dq.size()==Capacity){

                int last=dq.back();
                dq.pop_back();
                cache.erase(last);
            }
        }
        else{
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            dq.erase(it);
            cache.erase(key);


        }
        dq.push_front(key);
        cache[key] = value;
    }


};



