#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Simple function to calculate similarity percentage
float calculateScore(string resume, string jd) {
    float match = 0;
    stringstream ss(jd);
    string word;
    vector<string> keywords;

    while (ss >> word) {
        if (resume.find(word) != string::npos) {
            match++;
        }
        keywords.push_back(word);
    }
    return (match / keywords.size()) * 100;
}

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;
    string resume = argv[1];
    string jd = argv[2];
    cout << calculateScore(resume, jd);
    return 0;
}