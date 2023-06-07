#include <iostream>
#include <string>
using namespace std;
int main() {
    string word;
    string key;
    cin>>word;
    cin>>key;
    char vigenereAnel[26][26];
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            vigenereAnel[i][j] = 'A' + (i + j) % 26;
        }
    }

    string encryptedWord;
    int wordLen = word.length();
    int keyLen = key.length();

    for (int i = 0; i < wordLen; ++i) {
        char wordChar = word[i];
        char keyChar = key[i % keyLen];
        if (!isalpha(wordChar)) {
            encryptedWord += wordChar;
            continue;
        }
        char base = islower(wordChar) ? 'a' : 'A';
        char encryptedChar = vigenereAnel[toupper(keyChar) - 'A'][toupper(wordChar) - 'A'];
        encryptedWord += encryptedChar;
    }

    cout<<encryptedWord<<endl;

    return 0;
}ss