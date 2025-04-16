#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) return "";

    std::vector<std::string> sortedStrs = strs;
    std::sort(sortedStrs.begin(), sortedStrs.end());

    std::string first = sortedStrs.front();
    std::string last = sortedStrs.back();
    int i = 0;

    while (i < first.size() && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}

int main() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = longestCommonPrefix(strs);

    if (!result.empty()) {
        std::cout << "Longest Common Prefix: " << result << std::endl;
    } else {
        std::cout << "No common prefix found." << std::endl;
    }

    return 0;
}
