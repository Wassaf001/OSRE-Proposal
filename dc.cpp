#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string compressStaticDictionary(const string& input) {
    unordered_map<char, int> dictionary;
    string compressed;
    int index = 1;
    
    for (char c : input) {
        if (dictionary.find(c) == dictionary.end()) {
            dictionary[c] = index++;
        }
        compressed += to_string(dictionary[c]) + " ";
    }
    
    return compressed;
}

string decompressStaticDictionary(const string& input) {
    unordered_map<int, char> dictionary;
    string decompressed;
    int num = 0;
    bool isNum = true;
    
    for (char c : input) {
        if (c == ' ') {
            if (isNum) {
                decompressed += dictionary[num];
            } else {
                num = 0;
            }
            isNum = !isNum;
        } else {
            if (isNum) {
                num = num * 10 + (c - '0');
            } else {
                dictionary[num] = c;
            }
        }
    }
    
    return decompressed;
}

int main() {
    string original;
    
    cout << "Enter the string: ";
    cin >> original;
    
    string compressed = compressStaticDictionary(original);
    string decompressed = decompressStaticDictionary(compressed);

    cout << "Original: " << original << endl;
    cout << "Compressed: " << compressed << endl;
    cout << "Decompressed: " << decompressed << endl;

    return 0;
}
