#include "HighScores.h"
#include "Play.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "constant.h"



HighScores::HighScores()
    : scores(new unsigned int[5]), size(5), capacity(5) {

    scores[0] = 5;
    scores[1] = 4;
    scores[2] = 3;
    scores[3] = 2;
    scores[4] = 1;

}

HighScores::~HighScores() {
    delete[] scores; 
}

void HighScores::LoadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::vector<unsigned int> tempScores;
        unsigned int score;

        while (file >> score) {
            tempScores.push_back(score);
        }
        file.close();
     
        delete[] scores;
        size = tempScores.size();
        capacity = std::max(capacity, size);
        scores = new unsigned int[capacity];
       

        for (size_t i = 0; i < size; ++i) {
            scores[i] = tempScores[i];
        }
    }else {
        std::cerr << "Failed to open " << filename << " for reading. Initializing default scores." << std::endl;
    
        
            size = 0;
        }
    }


void HighScores::SaveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            file << scores[i] << "\n";
        }
        file.close();
    }else {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
    }
}

void HighScores::AddScore(unsigned int score) {


    std::vector<unsigned int> tempScores;

    for (int i = 0; i < size; i++)
    {
        tempScores.push_back(scores[i]);
    }

    tempScores.push_back(score);

    std::sort(tempScores.rbegin(), tempScores.rend());

    size = size + 1;

    delete[] scores;
    scores = new unsigned int[size];
    for (size_t i = 0; i < size; ++i) {
        scores[i] = tempScores[i];
    }
}

void HighScores::Draw() const {
 
 
}

unsigned int* HighScores::getScores(){

    return scores;

}