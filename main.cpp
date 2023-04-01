#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Missing file path parameter" << endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        string filename(argv[i]);
        string outputString;

        string variableFormat = "\\{([A-Z_]+)\\}"; // regex pattern to match the variable format
        regex variableRegex(variableFormat);

        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            cout << "Could not open file " << filename << endl;
            return 2;
        }

        string line;
        bool hasError = false;
        while (getline(inputFile, line)) {
            smatch matches;
            bool hasMatches = regex_search(line, matches, variableRegex);
            while (hasMatches) {
                string matchedString(matches[0]);
                string environmentVariableName = regex_replace(matchedString, variableRegex, "$1");
                cout << "Found environment placeholder for: " << environmentVariableName << endl;
                auto environmentVariable = getenv(environmentVariableName.c_str());
                if (environmentVariable != nullptr) {
                    string value(environmentVariable);
                    line.replace(line.find(matchedString), matchedString.size(), value);
                } else {
                    hasError = true;
                    cout << "Missing environment variable: " << environmentVariableName << endl;
                }

                hasMatches = regex_search(line, matches, variableRegex);
            }
            outputString += line + "\n";
        }

        inputFile.close();

        if (hasError) {
            return 1;
        }

        ofstream outputFile(filename);
        outputFile << outputString;
        outputFile.close();
        cout << "Done." << endl;
    }

    return 0;
}
