#include <iostream>
#include <cmath>

void toUppers(char* lang, int size){
    for(size_t i = 0; i < size; i++){
        if((int)lang[i] >= 97 && (int)lang[i] <= 122){
            lang[i] = lang[i] - 32;
        }
    }
}

void print(char* lang, int size){
    for(size_t i = 0; i < size; i++){
        //std::cout.width(3);
        std::cout << lang[i];
    }
    std::cout << std::endl;
}

void cesarSH(char* lang, int size, int key){
    toUppers(lang, size);
    char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int ABCSize = sizeof(ABC) / sizeof(char) - 1;
    key = abs(key % ABCSize);
    int tmp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < ABCSize; j++){
            if(lang[i] == ABC[j]){
                if(j + key > ABCSize - 1){
                    tmp = ((j + key) % ABCSize);
                    lang[i] = ABC[tmp];
                    break;
                }
                tmp = j;
                lang[i] = ABC[tmp + key];
                break;
            }
        }
    }
}

void deCesarSH(char* lang, int size, int key){
    toUppers(lang, size);
    char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int ABCSize = sizeof(ABC) / sizeof(char) - 1;
    key = abs(key % ABCSize);
    int tmp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < ABCSize; j++){
            if(lang[i] == ABC[j]){
                if(j < key){
                    tmp = ABCSize - key + j;
                    lang[i] = ABC[tmp];
                    break;
                }
                tmp = j - key;
                lang[i] = ABC[tmp];
                break;
            }
        }
    }
}
int srtLength(char *in) {
    int count = 0;
    while(1){
        if(*in++ == '\0') break;
        count++;
    }
    return count;
}

char* shuffle(char* in, int key, int encrypt){
    int length = 0;
    length = srtLength(in);
    if(length == 0) return nullptr;
    const int len = key * (1 + ((length - 1) / key));

    char* out = new char[len];
    if(encrypt == 0) key = len / key;
    int idx = 0;
    for(int i = 0; i < key; i++){
        for(int j = i; j < len; j += key){
            out[idx++] = (*(in + j)) ? *(in + j) : (char) '*';
        }
    }
    out[len] = 0;
    return out;
}




int main() {

    char string[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ ZYXWVUTSRQPONMLKJIHGFEDCBA"};
    int key = 5;
    int size = sizeof(string) / sizeof(char) - 1;
    print(string, size);
    cesarSH(string, size, key);
    print(string, size);
    deCesarSH(string, size, key);
    print(string, size);

    char* msg = "This is string long? long string";
    print(msg, srtLength(msg));
    char *encrypt = shuffle(msg, 4, 1);
    print(encrypt, srtLength(encrypt));
    char *decrypt = shuffle(encrypt, 4, 0);
    print(decrypt, srtLength(decrypt));

    return 0;
}
