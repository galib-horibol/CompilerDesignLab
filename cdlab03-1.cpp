#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isAlnum(char c) {
    return isAlpha(c) || isDigit(c);
}

vector<string> KEYWORDS = {
    "int","double","float","char","string","void","bool",
    "if","else","while","for","return","class","public",
    "private","protected","using","namespace","cout","cin","endl"
};

bool isKeyword(const string& tok) {
    for (int i = 0; i < KEYWORDS.size(); i++)
        if (KEYWORDS[i] == tok)
            return true;
    return false;
}

string classifyToken(const string& token) {
    if (token == "") return "UNKNOWN";
    if (isKeyword(token)) return "KEYWORD";

    bool number = true;
    for (int i = 0; i < token.length(); i++)
        if (!isDigit(token[i]))
            number = false;
    if (number) return "CONSTANT (Number)";

    if (token[0] == '"' && token[token.length() - 1] == '"')
        return "CONSTANT (String)";

    if (isAlpha(token[0]) || token[0] == '_') {
        for (int i = 1; i < token.length(); i++)
            if (!isAlnum(token[i]) && token[i] != '_')
                return "UNKNOWN";
        return "IDENTIFIER";
    }

    return "UNKNOWN";
}

bool isOperator(char c) {
    string ops = "+-*/=<>!&|";
    for (int i = 0; i < ops.length(); i++)
        if (c == ops[i])
            return true;
    return false;
}

bool isPunctuation(char c) {
    string punc = ";:,.(){}[]#";
    for (int i = 0; i < punc.length(); i++)
        if (c == punc[i])
            return true;
    return false;
}

void processLine(const string& line) {
    string token = "";

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        if (c == '"') {
            if (token != "") {
                cout << "    '" << token << "' -> " << classifyToken(token) << endl;
                token = "";
            }

            token += c;  
            i++;

            while (i < line.length() && line[i] != '"') {
                token += line[i];
                i++;
            }

            if (i < line.length()) token += '"'; 

            cout << "    '" << token << "' -> CONSTANT (String)" << endl;
            token = "";
            continue;
        }

        if (isSpace(c) || isOperator(c) || isPunctuation(c)) {
            if (token != "") {
                cout << "    '" << token << "' -> " << classifyToken(token) << endl;
                token = "";
            }

            if (isOperator(c))
                cout << "    '" << c << "' -> OPERATOR" << endl;
            else if (isPunctuation(c))
                cout << "    '" << c << "' -> PUNCTUATION" << endl;
        }
        else {
            token += c;
        }
    }

    if (token != "")
        cout << "    '" << token << "' -> " << classifyToken(token) << endl;
}

int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cout << "Error opening file.txt\n";
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        cout << "\n--- Line " << lineNumber++ << ": " << line << " ---" << endl;
        processLine(line);
    }

    file.close();
    return 0;
}
