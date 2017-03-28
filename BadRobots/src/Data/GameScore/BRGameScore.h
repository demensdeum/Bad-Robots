/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameScore.h
 * Author: demensdeum
 *
 * Created on March 26, 2017, 7:40 PM
 */

#ifndef BRGAMESCORE_H
#define BRGAMESCORE_H

class BRGameScore {
public:
    BRGameScore();
    BRGameScore(const BRGameScore& orig);
    virtual ~BRGameScore();
    
    int getScore();
    
    void addScore(int score);
    
    void reset();
    
private:

    int score;
    
};

#endif /* BRGAMESCORE_H */

