#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stdexcept>

std::string base64_encode(const std::string& input) {
    static const char* const base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string output;
    int val = 0, valb = -6;
    for (unsigned char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            output.push_back(base64_table[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) output.push_back(base64_table[((val << 8) >> (valb + 8)) & 0x3F]);
    while (output.size() % 4) output.push_back('=');
    return output;
}

int main() {
    std::string message;
    std::cout << "input id: ";
    std::getline(std::cin, message);
    std::string encoded_message = base64_encode(message);
    std::cout << encoded_message << std::endl;
    std::cin.ignore();

    return 0;
}
