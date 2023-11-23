#include "DSString.h"
#include <cstring>
/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions 
 * from <string.h> or <c string> other than for conversion from a c-sting.
 */

//Default Constructor
DSString::DSString() {

    len = 0;
    data = nullptr;
}

//Constructor with Passed in char array
DSString::DSString(const char *new_word) {

    int i = 0;
    while(new_word[i] != '\0') {
        i++;
    }
    len = i;
    data = new char[len + 1];
    strcpy(data,new_word);
}

//Copy Constructor
DSString::DSString(const DSString &copy) {

    len = copy.length();
    data = new char[len + 1];
    strcpy(data,copy.c_str());
}

//Destructor
DSString::~DSString() {

    delete[] data;
}

//Copy Assignment Operator
DSString &DSString::operator=(const  DSString &copy) {
    if (data != nullptr) {
        delete[] data;
    }
    len = copy.length();
    data = new char[len + 1];
    strcpy(data,copy.c_str());
    return *this;
}

//Function that returns Length of String
int DSString::length() const {
    return len;
}

//Returns that char array at index using a DSString
char &DSString::operator[](int index) const {
    return data[index];
}

DSString DSString::operator+(DSString &word_to_add) const {
    int length = word_to_add.length();

    int combined_len = length + len;

    DSString new_string = new char[combined_len + 1];

    for(int i = 0; i < len; i++){
        new_string[i] = data[i];
    }

    for(int y = len; y < combined_len; y++) {
        new_string[y] = word_to_add[y - len];
    }
    new_string[combined_len] = '\0';
    return new_string;
}
//Check len first if not then return false, compare the data at each index if at any point the data does not equal each other at the same index return false, return true.
bool DSString::operator==(const DSString &string) const {
    if (this->len != string.len) {
        return false;
    }

    for (int i = 0; i < this->len; i++) {
        if (this->data[i] != string[i]) {
            return false;
        }
    }

    return true;

}

bool DSString::operator!=(const DSString &string) const {
    bool not_equal = *this == string;
    return !not_equal;
}

bool DSString::operator<(const DSString &string) const {

    int range = std::min(len,string.length());
    for (int i = 0; i < range; i++) {
        char letter = string[i];
        if (data[i] < letter) {
            return true;
        } else if (data[i] > letter) {
            return false;
        }
    }

    if (len < string.length()) {
        return true;
    }

    return false;
}

DSString DSString::substring(size_t start, size_t numChars) const {
    char *substring = new char[numChars + 1];
    for (size_t i = 0; i < numChars; i++) {
        substring[i] = data[start];
        start++;
    }
    substring[numChars] = '\0';
    DSString sub = substring;
    delete[] substring;

    return sub;
}

DSString DSString::toLower() {

    for (int i = 0; i < len; i++) {
        if (isalpha(data[i])) {
            data[i] = tolower(data[i]);
        }
    }
    return *this;
}

char *DSString::c_str() const {
    return data;
}

std::ostream &operator<<(std::ostream &stream, const DSString &output) {
    stream << output.data;
    return stream;
}

std::istream &operator>>(std::istream &in, DSString &c) {
    char data[1000];
    in.getline(data,1000);

    DSString temp(data);
    c = temp;

    return in;
}

vector<DSString> DSString::tokenizer() {

    vector<DSString> words;
    int start = 0;
    for (int i = 0; i < len; i++) {
        if (!isalpha(data[i])) {
            if (i != start) {
                words.push_back(substring(start,i - start).toLower());
            }
            start = i + 1;
        }
    }
    if (len != start) {
        words.push_back(substring(start,len - start).toLower());
    }
    return words;
}

vector<DSString> DSString::tokenize_by_comma() {
    vector<DSString> words;
    int start = 0;
    for (int i = 0; i < len; i++) {
        if (data[i] == ',') {
            if (i != start) {
                words.push_back(substring(start,i - start).toLower());
            }
            start = i + 1;
        }
    }
    if (len != start) {
        words.push_back(substring(start,len - start).toLower());
    }
    return words;


}
