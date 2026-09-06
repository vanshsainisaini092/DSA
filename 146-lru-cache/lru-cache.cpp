class LRUCache {
public:
    vector<pair<int, int>> v;
    int n;
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {

        for (int i = 0; i < v.size(); i++) {
            if (key == v[i].first) {

                int value = v[i].second;

                v.erase(v.begin() +i);

                v.push_back({key, value});
                return value;
            }
        }
        return -1;
    }

    void put(int key, int value) {

        for (int i = 0; i < v.size(); i++) {

            if (key == v[i].first) {
                v.erase(v.begin() + i);
                v.push_back({key, value});
         return;   }
            
        }
        if (n == v.size()) {
            v.erase(v.begin());
           
        }
        v.push_back({key, value});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */