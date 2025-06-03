#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

struct BiometricData {
    std::string Bio_ID;
    double Bio_height;
    double Bio_weight;
    double Bio_handLength;
    double Bio_footSize;
    double Bio_faceRatio;

    static BiometricData fromString(const std::string& line) {
        BiometricData data;
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, data.Bio_ID, ',');
        std::getline(ss, token, ','); data.Bio_height = std::stod(token);
        std::getline(ss, token, ','); data.Bio_weight = std::stod(token);
        std::getline(ss, token, ','); data.Bio_handLength = std::stod(token);
        std::getline(ss, token, ','); data.Bio_footSize = std::stod(token);
        std::getline(ss, token, ','); data.Bio_faceRatio = std::stod(token);
        return data;
    }
};

bool isMatch(const BiometricData& a, const BiometricData& b) {
    double tolerance = 0.05;
    return (
        std::abs(a.Bio_height - b.Bio_height) <= tolerance &&
        std::abs(a.Bio_weight - b.Bio_weight) <= tolerance * 100 &&
        std::abs(a.Bio_handLength - b.Bio_handLength) <= tolerance * 100 &&
        std::abs(a.Bio_footSize - b.Bio_footSize) <= tolerance * 100 &&
        std::abs(a.Bio_faceRatio - b.Bio_faceRatio) <= tolerance
    );
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: BioData.exe <file1.txt> <file2.txt> ...\n";
        return 1;
    }

    std::vector<BiometricData> dataList;

    // Read biometric data from each file
    for (int i = 1; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open " << argv[i] << "\n";
            return 1;
        }
        std::string line;
        if (std::getline(file, line) && !line.empty()) {
            dataList.push_back(BiometricData::fromString(line));
        } else {
            std::cerr << "Error: File " << argv[i] << " is empty or invalid\n";
            return 1;
        }
        file.close();
    }

    // Compare biometric data
    for (size_t i = 0; i < dataList.size(); ++i) {
        for (size_t j = i + 1; j < dataList.size(); ++j) {
            bool match = isMatch(dataList[i], dataList[j]);
            std::cout << "Comparing " << dataList[i].Bio_ID << " and " << dataList[j].Bio_ID << ": ";
            std::cout << (match ? "Match" : "No match") << std::endl;
        }
    }

    return 0;
}
