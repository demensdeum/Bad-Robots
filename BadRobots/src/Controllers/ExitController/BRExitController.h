/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRExitController.h
 * Author: demensdeum
 *
 * Created on March 26, 2017, 3:53 PM
 */

#ifndef BREXITCONTROLLER_H
#define BREXITCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class BRExitController: public FSEGTController {
public:
    BRExitController();
    BRExitController(const BRExitController& orig);
    virtual ~BRExitController();
    
    virtual void step();
    
private:

};

#endif /* BREXITCONTROLLER_H */

