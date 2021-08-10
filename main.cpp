#include <iostream>
#include <cmath>

int finalShift(int size, int shift){
    bool flag = 0;
    if(shift < 0){
        shift = abs(shift);
        flag = 1;
    }
    if(shift > size){
        if(flag){
            return 0 - abs(shift % size);
        }
        return abs(shift % size);
    } else if(flag){
        return 0 - shift;
    } else{
        return shift;
    }
}

void shiftArray(char* lang, int size, int shift){
    if(shift != 0){
        char tmp = '\0';
        int finShift = finalShift(size, shift);
        if(finShift > 0){
            
        }else if(finShift < 0){

        }
    }
}

void toUppers(char* lang, int size){
    for(size_t i = 0; i < size; i++){
        if((int)lang[i] >= 97 && (int)lang[i] <= 122){
            lang[i] = lang[i] - 32;
        }
    }
}

void print(char* lang, int size){
    for(size_t i = 0; i < size; i++){
        std::cout << lang[i];
    }
    std::cout << std::endl;
}

void cesarSH(char* lang, int size, int key){
    //toUppers(lang, size);
    shiftArray(lang, size, key);
}

int main() {

    char string[] = {"This is string? Yes, it's string"};
    int key = -3;
    int size = sizeof(string) / sizeof(char);
    print(string, size);
    cesarSH(string, size, key);
    print(string, size);




    return 0;
}

