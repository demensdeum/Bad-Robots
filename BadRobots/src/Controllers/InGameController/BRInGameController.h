/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRInGameController.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 10:30 AM
 */

#ifndef BRINGAMECONTROLLER_H
#define BRINGAMECONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTSceneController.h>

class BRInGameController: public FSEGTSceneController {
public:
    BRInGameController();
    BRInGameController(const BRInGameController& orig);    
    virtual ~BRInGameController();
    
    virtual void step();
    virtual void beforeStart();
    
private:

};

#endif /* BRINGAMECONTROLLER_H */

