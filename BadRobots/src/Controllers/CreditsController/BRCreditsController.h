/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCreditsController.h
 * Author: demensdeum
 *
 * Created on March 19, 2017, 11:31 AM
 */

#ifndef BRCREDITSCONTROLLER_H
#define BRCREDITSCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class BRCreditsController: public FSEGTController {
public:
    BRCreditsController();
    BRCreditsController(const BRCreditsController& orig);
    virtual ~BRCreditsController();
    
    virtual void beforeStart();
    virtual void step();
    
    int presentTime;
    
private:
    

};

#endif /* BRCREDITSCONTROLLER_H */

