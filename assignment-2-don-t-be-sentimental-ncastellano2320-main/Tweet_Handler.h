//
// Created by ncast on 2/17/2023.
//

#ifndef ASSIGNMENT2_SENTIMENT_TWEET_HANDLER_H
#define ASSIGNMENT2_SENTIMENT_TWEET_HANDLER_H

#include "DSString.h"
#include <map>
#include <utility>
#include <sstream>
using namespace std;

class Tweet_Handler {
private:
    //Vector of Stop-Words
    vector<DSString> stop_words = {"a", "an", "and", "the", "is", "of", "or",
                                   "to", "in", "that", "this", "it", "for", "with",
                                   "be", "on", "at", "by", "as", "but", "not", "you",
                                   "are", "have", "has", "was", "were", "am", "if", "do",
                                   "does", "did", "I", "he", "she", "they", "we", "you",
                                   "me", "him", "her", "them", "us", "my", "mine", "your",
                                   "yours", "his", "her", "hers", "our", "ours", "their", "theirs"};

    //Vector that keeps track of the tokenized words in each tweet
    vector<DSString> words_in_one_tweet;

    //Map serving as a frequency table for the sentiment per word
    map<DSString,int> frequency_table;

    //Vector to keep track of predictions made using frequency table (predicted sentiment, tweet id)
    vector<pair<DSString,DSString>> predictions;


public:
    //Vector keeping track of only wrong prediction for output file (correct sentiment, vector of wrong predictions)
    vector<pair<DSString,pair<DSString,DSString>>> wrong_predictions;

    //Function that fills the frequency table or map
    void fill_table(DSString& line);

    //Function that analyzes table to make close to accurate predictions to store in prediction vector
    void analyze_table(DSString& line);

    //Function that compares the correct sentiment with the predicted sentiment and fills vector of evaluated predictions
    void compare(DSString& line, int count);

    //Function to check for stop words
    bool is_stop_word(DSString word);
};



#endif //ASSIGNMENT2_SENTIMENT_TWEET_HANDLER_H
