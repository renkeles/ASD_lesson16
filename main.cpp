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

int main() {

    char string[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ ZYXWVUTSRQPONMLKJIHGFEDCBA"};
    int key = 5;
    int size = sizeof(string) / sizeof(char) - 1;
    print(string, size);
    cesarSH(string, size, key);
    print(string, size);
    deCesarSH(string, size, key);
    print(string, size);



    return 0;
}
