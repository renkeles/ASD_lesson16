#include <iostream>

void toUppers(char* lang, size_t size){
    for(size_t i = 0; i < size; i++){
        if((int)lang[i] >= 97 && (int)lang[i] <= 122){
            lang[i] = lang[i] - 32;
        }
    }
}

void print(char* lang, size_t size){
    for(size_t i = 0; i < size; i++){
        std::cout << lang[i];
    }
    std::cout << std::endl;
}

int main() {

    char string[] = {"This is string? Yes, it's string"};
    size_t size = sizeof(string) / sizeof(char);
    print(string, size);
    toUppers(string, size);
    print(string, size);




    return 0;
}
