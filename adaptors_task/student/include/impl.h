#pragma once
#include <string>
#include <stack>

using namespace std;

/**
 * @todo isValid - check if given expression is valid - all open brackets are closed
 * by CORRESPONDING closed bracket.
 *
 * @param source - expression that will contain brackets
 * of three types: "()"/"[]"/"{}".
 * May contain other symbols or may not contain anything.
 *
 * @return true if expression is valid
 */
bool isValid(const std::string& source){
    stack <string> openingbrackets;
    for (const auto &ch : source){
        if (openingbrackets.empty()){
            openingbrackets.push(&ch);
        }
        else if ((openingbrackets.top() == "(" && &ch == ")") || (openingbrackets.top() == "[" && &ch == "]") || (openingbrackets.top() == "{" && &ch == "}")) {
            openingbrackets.pop();
        }
        else {
            openingbrackets.push(&ch);
        }
    }
    if (openingbrackets.empty()) {
        return true;
    }
    return false;

}
