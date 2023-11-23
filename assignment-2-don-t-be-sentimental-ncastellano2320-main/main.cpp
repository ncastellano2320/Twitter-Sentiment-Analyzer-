#include <iostream>
#include "Sentiment_Classifier.h"
#include <chrono>
using namespace std;

int main(int argc, char** argv)
{  
    cout << "I will be a sentiment analyzer!" << endl;

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    //Set Timer
    auto start = chrono::high_resolution_clock::now();

    Sentiment_Classifier classifier;

    classifier.train(argv[1]);
    classifier.predict(argv[2]);
    classifier.evaluatePredictions(argv[3]);

    classifier.create_output();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << "seconds\n";

    return 0;
}