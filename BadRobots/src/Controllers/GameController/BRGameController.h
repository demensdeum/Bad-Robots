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

class BRGameController: public FSEGTGameController {
public:
    BRGameController();
    BRGameController(const BRGameController& orig);
    virtual ~BRGameController();
    
    virtual void controllerDidFinish(FSEGTController *controller);
    
private:

};

#endif /* BRGAMECONTROLLER_H */

