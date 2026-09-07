class LRUCache {
public:
    // vector<pair<int, int>> v;
    int n;
    list<int> dll;

    map<int, pair<list<int>::iterator, int>> mp;

    LRUCache(int capacity) { n = capacity; }

    void makeMostRecent(int key) {

        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }
        makeMostRecent(key);
        return mp[key].second;
    }

    // for (int i = 0; i < v.size(); i++) {
    //     if (key == v[i].first) {

    //         int value = v[i].second;

    //         v.erase(v.begin() + i);

    //         v.push_back({key, value});
    //         return value;
    //     }
    // }
    // return -1;

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeMostRecent(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        // when size is over

        if (n < 0) {
            int keytoBEdelete = dll.back();
            mp.erase(keytoBEdelete);
            dll.pop_back();
            n++;
        }
  

//   brutforce approch is this 

        // for (int i = 0; i < v.size(); i++) {

        //     if (key == v[i].first) {
        //         v.erase(v.begin() + i);
        //         v.push_back({key, value});
        //         return;
        //     }
        // }
        // if (n == v.size()) {
        //     v.erase(v.begin());
        //     v.push_back({key, value});
        // } else {
        //     v.push_back({key, value});
        // }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */