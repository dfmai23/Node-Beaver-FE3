/*******************************************************************************
* File Name: sd_timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "sd_timer.h"

static sd_timer_backupStruct sd_timer_backup;


/*******************************************************************************
* Function Name: sd_timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  sd_timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void sd_timer_SaveConfig(void) 
{
    #if (!sd_timer_UsingFixedFunction)
        sd_timer_backup.TimerUdb = sd_timer_ReadCounter();
        sd_timer_backup.InterruptMaskValue = sd_timer_STATUS_MASK;
        #if (sd_timer_UsingHWCaptureCounter)
            sd_timer_backup.TimerCaptureCounter = sd_timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!sd_timer_UDB_CONTROL_REG_REMOVED)
            sd_timer_backup.TimerControlRegister = sd_timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: sd_timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  sd_timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void sd_timer_RestoreConfig(void) 
{   
    #if (!sd_timer_UsingFixedFunction)

        sd_timer_WriteCounter(sd_timer_backup.TimerUdb);
        sd_timer_STATUS_MASK =sd_timer_backup.InterruptMaskValue;
        #if (sd_timer_UsingHWCaptureCounter)
            sd_timer_SetCaptureCount(sd_timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!sd_timer_UDB_CONTROL_REG_REMOVED)
            sd_timer_WriteControlRegister(sd_timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: sd_timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  sd_timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void sd_timer_Sleep(void) 
{
    #if(!sd_timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(sd_timer_CTRL_ENABLE == (sd_timer_CONTROL & sd_timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            sd_timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            sd_timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    sd_timer_Stop();
    sd_timer_SaveConfig();
}


/*******************************************************************************
* Function Name: sd_timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  sd_timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void sd_timer_Wakeup(void) 
{
    sd_timer_RestoreConfig();
    #if(!sd_timer_UDB_CONTROL_REG_REMOVED)
        if(sd_timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                sd_timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
