# LRU (Least Recently Used) Cache 
It should support the following operations: get and put.
* get(key) – Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1. 
* put(key, value) – Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
The cache is always initialized with positive capacity.

My solution is to use  OrderedDict from collections module which keep order of insertion of keys and we can change that order if required. All operations have O(1) time complexity.

