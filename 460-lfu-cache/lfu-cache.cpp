class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq; // counter->{key,value,counter}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostfrequentUse(int key) {
        auto& vc = *(
            mp[key]); //&->becouse direct freq map ka list wqale part ka access

        int value = vc[1]; // value
        int f = vc[2];     // counter->of inside a list
        freq[f].erase(mp[key]);

        if (freq[f].empty()) {
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        auto vec = *(mp[key]); // using this * in  freq->list where value store;
        int value = vec[1];
        makeMostfrequentUse(key);
        return value;
    }

    void put(int key, int value) {

        if (cap == 0) {
            return;
        }
        if (mp.find(key) != mp.end()) {

            auto& vc = (*(mp[key]));
            vc[1] = value;
            makeMostfrequentUse(key);
        } else if (size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        } else {

            auto& kon_sa_list = freq.begin()->second;

            int key_to_delete = (kon_sa_list.back())[0];

            kon_sa_list.pop_back();
            if (kon_sa_list.empty()) {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int>({key, value, 1}));
            // for deting in mp
            mp.erase(key_to_delete);

            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */