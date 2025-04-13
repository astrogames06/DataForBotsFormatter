#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

std::string cleanForBots(const std::string& line) {
    std::string result;
    for (char ch : line) {
        if (std::isalnum(ch) || ch == ',' || ch == '.' || ch == '-' || ch == ' ') {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::ifstream in("raw_data.txt");
    std::ofstream out("formatted_data.txt");

    if (!in || !out) {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::string cleanLine = cleanForBots(line);
        out << cleanLine << "\n";
    }

    std::cout << "Data cleaned.\n";
    return 0;
}
