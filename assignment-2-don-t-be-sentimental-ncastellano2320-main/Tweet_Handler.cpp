//
// Created by ncast on 2/17/2023.
//
#include "Tweet_Handler.h"

void Tweet_Handler::fill_table(DSString& line) {
    int senti;
    DSString tweet;
    //Parse through line to get info---------------------------------------------
    //4,2014351367,Wed Jun 03 01:14:33 PDT 2009,NO_QUERY,cathyleehart,@just_tam21 hahah its kind of the same as adelaides except a bit bigger
    vector<DSString> temp_strings = line.tokenize_by_comma();  //Contains all components of the tweet

    senti = stoi((temp_strings.at(0)).c_str());
    tweet = (temp_strings.at(5).toLower().c_str());

    words_in_one_tweet = tweet.tokenizer();
    for (size_t i = 0; i < words_in_one_tweet.size(); i++) {
        //check if word is a stop word
        if (!is_stop_word(words_in_one_tweet.at(i))) {
            //Check to see if in map
            if (frequency_table.find(words_in_one_tweet.at(i)) != frequency_table.end()) {
                if (senti == 4) {
                    frequency_table.at(words_in_one_tweet.at(i)) += 1;
                } else {
                    frequency_table.at(words_in_one_tweet.at(i)) -= 1;
                }
            } else {
                if (senti == 4) {
                    frequency_table.insert({words_in_one_tweet.at(i),1});
                } else {
                    frequency_table.insert({words_in_one_tweet.at(i),-1});
                }
            }
            //yes then increment sentiment
            //else add to map
            //increment sentiment
        }

    }
}

void Tweet_Handler::analyze_table(DSString &line) {
    int positive = 0;
    int negative = 0;
    DSString id;
    DSString tweet;

    vector<DSString> temp_strings = line.tokenize_by_comma();
    id = (temp_strings.at(0).c_str());
    tweet = (temp_strings.at(4).toLower().c_str());

    words_in_one_tweet = tweet.tokenizer();

    for (auto pos: words_in_one_tweet) {
        if (frequency_table.find(pos) != frequency_table.end()) {
            if (frequency_table.at(pos) < 0) {
                negative++;
            } else if (frequency_table.at(pos) > 0){
                positive++;
            } else {
                positive++;
                negative++;
            }
        }
    }

    if (positive > negative) {
        predictions.emplace_back("4",id);
    } else if (negative > positive) {
        predictions.emplace_back("0",id);
    } else if (negative == positive) {
        predictions.emplace_back("4",id);
    }

}

void Tweet_Handler::compare(DSString &line, int count) {
    DSString senti;

    vector<DSString> temp_strings = line.tokenize_by_comma();
    senti = (temp_strings.at(0).c_str());

    if (senti != predictions.at(count).first) {
        wrong_predictions.emplace_back(senti,predictions.at(count));
    }


}

bool Tweet_Handler::is_stop_word(DSString word) {
    for (auto pos: stop_words) {
        if (word == pos) {
            return true;
        }
    }
    return false;
}

