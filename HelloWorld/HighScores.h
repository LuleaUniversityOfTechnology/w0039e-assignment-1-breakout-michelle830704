#pragma once

#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <string>


class HighScores {
public:
 
    HighScores();                      
    ~HighScores();                     

    // Public Methods
    void LoadFromFile(const std::string& filename);  
    void SaveToFile(const std::string& filename);    
    void AddScore(unsigned int score);               
    void Draw() const;  

    unsigned int* getScores();


private:
    unsigned int* scores;
    size_t size; 
    size_t capacity;
};

#endif 
