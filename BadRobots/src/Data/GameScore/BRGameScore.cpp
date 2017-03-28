/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameScore.cpp
 * Author: demensdeum
 * 
 * Created on March 26, 2017, 7:40 PM
 */

#include <iostream>
#include "BRGameScore.h"

using namespace std;

BRGameScore::BRGameScore() {
    
    score = 0;
    
}

int BRGameScore::getScore() {
    
    return score;
    
}

void BRGameScore::addScore(int score) {
    
    this->score += score;
    
    cout << "Game Score: " << this->score << endl;
    
}

void BRGameScore::reset() {
    
    this->score = 0;
    
}

BRGameScore::BRGameScore(const BRGameScore& orig) {
}

BRGameScore::~BRGameScore() {
}

