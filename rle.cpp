#include <iostream>
#include <string>

using namespace std;

string compressRLE(const string& input) {
    string compressed;
    int count = 1;
    
    for (int i = 0; i < input.length(); ++i) {
        if (i + 1 < input.length() && input[i] == input[i + 1]) {
            count++;
        } else {
            compressed += to_string(count) + input[i];
            count = 1;
        }
    }
    
    return compressed;
}   

string decompressRLE(const string& input) {
    string decompressed;
    
    for (int i = 0; i < input.length(); i += 2) {
        int count = input[i] - '0';
        decompressed.append(count, input[i + 1]);
    }
    
    return decompressed;
}

int main() {
    string original;
    
    cout << "Enter the string: ";
    cin >> original;
    
    string compressed = compressRLE(original);
    string decompressed = decompressRLE(compressed);

    cout << "Original: " << original << endl;
    cout << "Compressed: " << compressed << endl;
    cout << "Decompressed: " << decompressed << endl;

    return 0;
}
