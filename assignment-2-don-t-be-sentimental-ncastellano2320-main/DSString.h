/*
 * This file should help you to create a minimal interface for your string class based on
 * a dynamically allocated char array. Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-sting.
 */

#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <vector>
using namespace std;

class DSString
{

private:
    int len;    // the length of the string
    char *data; // a pointer to a character array containing the string with a `\0` terminator
    // Note: we keep the terminator only so we can return a c-string version in function c_str().

public:
    /**
     * Make sure you implement the rule-of-three and use proper memory management.
     * To help you get started, you can implement the following:
     **/

    DSString();
    DSString(const char *new_word); // constructor that converts a cstring
    // you can also provide  DSString(const string &); for std::string

    // rule-of-three
    DSString(const DSString &copy);            // copy constructor
    ~DSString();                               // destructor
    DSString &operator=(const DSString &copy); // assignment operator

    // you can also implement the move versions for the big 5 (C+11)

    int length() const; // returns the length of the string

    char &operator[](int index) const; // returns a reference to the character at the given index

    /**
     * Overloaded operator+ which appends the string in the argument to this string
     */
    DSString operator+(DSString &word_to_add) const;

    /**
     * Standard relational operators to compare and order your strings.
     * Feel free to add additional.
     **/
    bool operator==(const DSString &string) const;
    bool operator!=(const DSString &string) const;
    bool operator<(const DSString &string) const;

    /**
     * The substring method returns a new string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(size_t start, size_t numChars) const;

    /**
     * @brief Returns a new string object with all characters in lowercase
     *
     * @return DSString
     */
    DSString toLower(); // look at the ASCII table for this!

    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. Since data already has a `\0`
     * at the end of the string in DSString so you can just return a pointer to data.
     **/
    [[nodiscard]] char* c_str() const;

    // a conversion to std::string would be nice: string string();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. Overload the stream
     * extraction operator to read a string from the input stream.
     **/
    friend std::ostream &operator<<(std::ostream &stream, const DSString &output);
    friend std::istream &operator>>(std::istream &in, DSString &c);

    // You are free to add more functionality to the class.  For example,
    // you may want to add a find(...) function that will search for a
    // substring within a string or a function that breaks a string into words.

    //Add a function to get rid of non alphabetic charcters.


    vector<DSString> tokenizer();

    vector<DSString> tokenize_by_comma();
};

#endif
