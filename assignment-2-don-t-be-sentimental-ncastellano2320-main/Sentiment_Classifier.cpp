//
// Created by ncast on 2/17/2023.
//
#include "Sentiment_Classifier.h"

void Sentiment_Classifier::read_file_train(const DSString& the_file) {
    //Have to consider the header line
    ifstream file(the_file.c_str());

    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
    }

    //Have to consider the header line
    DSString header;
    file >> header;

    //Read the process rest of file
    DSString line;
    while (file >> line) {
        container.fill_table(line);
    }

    //Close file
    file.close();
}

void Sentiment_Classifier::read_file_test(const DSString& the_file) {
    //Have to consider the header line
    ifstream file(the_file.c_str());

    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
    }

    //Have to consider the header line
    DSString header;
    file >> header;

    //Read the process rest of file
    DSString line;
    while (file >> line) {
        container.analyze_table(line);
    }

    //Close file
    file.close();
}

void Sentiment_Classifier::read_prediction_file(const DSString &the_file) {
    //Have to consider the header line
    ifstream file(the_file.c_str());

    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
    }

    //Have to consider the header line
    DSString header;
    file >> header;

    //Read the process rest of file with counter
    int count = 0;
    DSString line;
    while (file >> line) {
        container.compare(line,count);
        count++;
    }

    //Close file
    file.close();
}

void Sentiment_Classifier::train(const DSString& file) {
    read_file_train(file);
}

void Sentiment_Classifier::predict(const DSString& file) {
    read_file_test(file);
}

void Sentiment_Classifier::evaluatePredictions(const DSString& file) {
    read_prediction_file(file);
}

void Sentiment_Classifier::create_output() {
    double accuracy = (container.wrong_predictions.size()/10000.00);
    accuracy = 1 - accuracy;

    ofstream output;
    output.open("output_file.txt");

    output << accuracy << endl;
    for (auto pos: container.wrong_predictions) {
        output << pos.second.first << ", " << pos.first << ", " << pos.second.second << endl;
    }

    output.close();

}


