
#include <vector>
#include <algorithm>

#include "DSString.h"

using namespace std;

int main()
{
    //Testing Constructor----------------------------------------------------------
    DSString myString = "Hello, World!";
    cout << myString << endl;
    //-----------------------------------------------------------------------------

    //Testing Copy Constructor-----------------------------------------------------
    DSString original = "Word to Copy!";
    DSString copy = original;
    cout << copy << endl;
    //-----------------------------------------------------------------------------

    //Testing Copy Assignment Operator---------------------------------------------
    DSString newString = "Name";
    newString = "!Nino";
    cout << newString << endl;
    //-----------------------------------------------------------------------------

    //Testing Substring Function---------------------------------------------------
    DSString testSubString = "Hello my name is nino!";
    cout << "substr: " << testSubString.substring(0, 8) << endl;
    //-----------------------------------------------------------------------------

    //Testing Length of DSString Function------------------------------------------
    DSString hi = "Hi";
    cout << hi.length() << endl;
    //-----------------------------------------------------------------------------

    //Testing Bracket Operator-----------------------------------------------------
    cout << testSubString[3] << endl;
    //-----------------------------------------------------------------------------

    //Testing Add Operator---------------------------------------------------------
    DSString first_word = "Hello";
    DSString second_word = "World!";
    DSString combined_words = first_word + second_word;
    cout << combined_words << endl;
    //-----------------------------------------------------------------------------

    //Testing Comparison == Operator-----------------------------------------------
    DSString Word1 = "One";
    DSString Word2 = "One";
    bool equal = false;
    if (Word1 == Word2) {
        equal = true;
        cout << "These strings are equal!" << endl;
    } else {
        cout << "Not Equal!" << endl;
    }
    //-----------------------------------------------------------------------------

    //Testing Not Equal != Operator------------------------------------------------
    DSString Word3 = "Five";
    DSString Word4 = "Ten";
    bool equal2 = true;
    if (Word3 != Word4) {
        equal = false;
        cout << "Not Equal" << endl;
    } else {
        cout << "They are equal!" << endl;
    }
    //-----------------------------------------------------------------------------

    //Testing Less Than < Operator-------------------------------------------------
    DSString Word5 = "Ten!";
    DSString Word6 = "Ten";
    bool less_than = false;
    if (Word5 < Word6) {
        equal = true;
        cout << "Is less than!" << endl;
    } else {
        cout << "Is not less than!" << endl;
    }
    //-----------------------------------------------------------------------------

    //Testing To Lower Function----------------------------------------------------
    testSubString.toLower();
    cout << testSubString << endl;
    //-----------------------------------------------------------------------------

    //Testing Tokenizer Function---------------------------------------------------
    DSString sentence = "This, IS, a, Sentence, That Shows separation.";
    cout << sentence.length() << endl;
    vector<DSString> token = sentence.tokenizer();
    for (size_t i = 0; i < token.size(); i++) {
        cout << token.at(i) << endl;
    }
    //-----------------------------------------------------------------------------

    DSString wow = "4,hello,by";
    vector<DSString> words = wow.tokenize_by_comma();
    for (int i = 0; i < words.size(); i++) {
        cout << words.at(i) << endl;
    }
    return 0;
}
