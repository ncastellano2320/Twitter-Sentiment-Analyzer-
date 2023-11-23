//
// Created by ncast on 2/17/2023.
//

#ifndef ASSIGNMENT2_SENTIMENT_SENTIMENT_CLASSIFIER_H
#define ASSIGNMENT2_SENTIMENT_SENTIMENT_CLASSIFIER_H

#include "DSString.h"
#include "Tweet_Handler.h"
#include <iostream>
#include <fstream>
using namespace std;

class Sentiment_Classifier {
private:
    Tweet_Handler container;
public:
    //DEFAULT CONSTRUCTOR
    Sentiment_Classifier() = default;

    //READ THE TRAIN FILE
    void read_file_train(const DSString& the_file);

    //READ THE TEST FILE
    void read_file_test(const DSString& the_file);

    //READ THE TEST FILE WITH INITIAL SENTIMENTS
    void read_prediction_file(const DSString& the_file);

    //TRAIN,PREDICT,EVALUATE FUNCTIONS
    void train(const DSString& file);
    void predict(const DSString& file);
    void evaluatePredictions(const DSString& file);

    //GENERATE OUTPUT FILE
    void create_output();
};


#endif //ASSIGNMENT2_SENTIMENT_SENTIMENT_CLASSIFIER_H
