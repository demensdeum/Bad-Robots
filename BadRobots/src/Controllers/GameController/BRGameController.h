/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameController.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 10:29 AM
 */

#ifndef BRGAMECONTROLLER_H
#define BRGAMECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTGameController.h>
#include <BadRobots/src/Controllers/ExitController/BRExitController.h>
#include <BadRobots/src/Data/GameScore/BRGameScore.h>
#include <memory>

using namespace std;

class BRGameController: public FSEGTGameController {
public:
    BRGameController();
    BRGameController(const BRGameController& orig);
    virtual ~BRGameController();
    
    virtual void controllerDidFinish(FSEGTController *controller);
    
    virtual void step();
    
private:

    shared_ptr<BRExitController> exitController;
    shared_ptr<BRGameScore> gameScore;
    
};

#endif /* BRGAMECONTROLLER_H */

