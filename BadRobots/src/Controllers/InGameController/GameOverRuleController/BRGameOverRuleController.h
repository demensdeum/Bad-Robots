/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTGameOverRuleController.h
 * Author: demensdeum
 *
 * Created on March 23, 2017, 11:45 PM
 */

#ifndef FSEGTGAMEOVERRULECONTROLLER_H
#define FSEGTGAMEOVERRULECONTROLLER_H

#include <memory>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

#include <BadRobots/src/Controllers/InGameController/GameOverRuleController/BRGameOverRuleControllerDelegate.h>

using namespace std;

class BRGameOverRuleController {
public:
    BRGameOverRuleController();
    BRGameOverRuleController(const BRGameOverRuleController& orig);
    virtual ~BRGameOverRuleController();
    
    BRGameOverRuleControllerDelegate *delegate;
    
    bool step(shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* FSEGTGAMEOVERRULECONTROLLER_H */

