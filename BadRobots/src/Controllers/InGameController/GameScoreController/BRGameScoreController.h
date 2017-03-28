/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameScoreController.h
 * Author: demensdeum
 *
 * Created on March 28, 2017, 11:05 PM
 */

#ifndef BRGAMESCORECONTROLLER_H
#define BRGAMESCORECONTROLLER_H

#include <BadRobots/src/Data/GameScore/BRGameScore.h>
#include <FlameSteelEngine/FSEObject.h>

#include <memory>

using namespace std;

class BRGameScoreController {
public:
    BRGameScoreController();
    BRGameScoreController(const BRGameScoreController& orig);
    virtual ~BRGameScoreController();
    
    shared_ptr<BRGameScore> gameScore;
    shared_ptr<FSEObject> gameScoreObject;
    
    void step();
    
private:

};

#endif /* BRGAMESCORECONTROLLER_H */

