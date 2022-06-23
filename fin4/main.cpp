#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class freqFile {
    private:
        string filename;
        int alphfreq[26] = {0};
        char store;
    public:
        freqFile(string name) {
            filename = name;
        }
    void readFile() {
        ifstream read;
        read.open(filename);
        while (!read.eof()) {
            read.get(store);
            if (store >= 'A' && store <= 'Z')
                store = store + ('a' - 'A');
            if (store >= 'a' && store <= 'z')
                alphfreq[store-'a']++;
        }
        read.close();
    }
    void showFreq() {
        store = 'a';
        for (int i = 0; i < 26; i++) {
            cout << '[' << store << "] = " << alphfreq[i] << endl;
            store++;
        }
        store = '\0';
    }
};

int main() {
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();
}
