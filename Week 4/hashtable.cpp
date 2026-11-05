#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct HashTable{
    int size;
    vector<list<int>> table;
    HashTable(int s):size(s),table(s){}
    int hashFunc(int key){
        return (key%size+size)%size;
    }
    void insert(int key){
        table[hashFunc(key)].push_back(key);
    }
    void remove(int key){
        table[hashFunc(key)].remove(key);
    }
    bool search(int key){
        for(int x:table[hashFunc(key)]) if(x==key) return true;
        return false;
    }
};
int main(){
    int s, n;
    if(!(cin>>s>>n)) return 0;
    HashTable ht(s);
    while(n--){
        int type, key;
        cin>>type>>key;
        if(type==1) ht.insert(key);
        else if(type==2) ht.remove(key);
        else if(type==3) cout<<(ht.search(key)?"1\n":"0\n");
    }
    return 0;
}
// DO PHUC TAP: O(S+M) S LA KICH CO BANG, M LA PHAN TU TRONG DSACH 