#include <iostream>
#include <cstring>

#define DEBUG 0

int main(int argc, char **argv){
    std::string byteStr;

    if(argc < 2 || argv[1][0] != '0' || argv[1][1] != 'x'){
        std::cout << "Usage: " << argv[0] << " <hex_addr>\nEx: " << argv[0] << " 0x010101\n";
        return 1;
    }

    /*
    * Start from last byte (len -2) and back towards until reach the 0x (i > 1)
    */
    for(int i=std::strlen(argv[1])-2; i > 1; i -=2){
        if(DEBUG)
            std::cout << argv[1][i];

        byteStr += "\\x";
        byteStr += argv[1][i];
        byteStr += argv[1][i+1];
    }

    std::cout << "Value in Hex: " << argv[1] << std::endl;
    std::cout << "Value in Byte String: " << byteStr << std::endl;

    return 0;
}