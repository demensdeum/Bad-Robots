/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRMenuController.h
 * Author: demensdeum
 *
 * Created on March 23, 2017, 9:05 PM
 */

#ifndef BRMENUCONTROLLER_H
#define BRMENUCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class BRMenuController: public FSEGTController {
public:
    BRMenuController();
    BRMenuController(const BRMenuController& orig);
    virtual ~BRMenuController();
    
    void beforeStart();
    
    void step();
    
private:

};

#endif /* BRMENUCONTROLLER_H */

