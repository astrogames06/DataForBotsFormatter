#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

// Cleans each line for bot consumption
std::string cleanForBots(const std::string& line) {
    std::ostringstream out;
    for (char ch : line) {
        if (std::isalnum(ch) || ch == ',' || ch == '.' || ch == '-' || std::isspace(ch)) {
            out << ch;
        }
    }
    return out.str();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: DataForBotsFormatter <input_file> <output_file>\n";
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::string formatted = cleanForBots(line);
        outFile << formatted << '\n';
    }

    std::cout << "Formatted data saved to " << argv[2] << "\n";
    return 0;
}
