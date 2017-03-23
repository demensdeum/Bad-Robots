/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameOverRuleControllerDelegate.h
 * Author: demensdeum
 *
 * Created on March 24, 2017, 12:06 AM
 */

#ifndef BRGAMEOVERRULECONTROLLERDELEGATE_H
#define BRGAMEOVERRULECONTROLLERDELEGATE_H

class BRGameOverRuleController;

class BRGameOverRuleControllerDelegate {
public:
    BRGameOverRuleControllerDelegate();
    BRGameOverRuleControllerDelegate(const BRGameOverRuleControllerDelegate& orig);
    virtual ~BRGameOverRuleControllerDelegate();
    
    virtual void gameOverRuleControllerDidGameOverCase(BRGameOverRuleController *controller);
    
private:

};

#endif /* BRGAMEOVERRULECONTROLLERDELEGATE_H */

