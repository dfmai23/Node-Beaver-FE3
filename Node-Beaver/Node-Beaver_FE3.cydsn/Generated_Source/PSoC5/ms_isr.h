/*******************************************************************************
* File Name: ms_isr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ms_isr_H)
#define CY_ISR_ms_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ms_isr_Start(void);
void ms_isr_StartEx(cyisraddress address);
void ms_isr_Stop(void);

CY_ISR_PROTO(ms_isr_Interrupt);

void ms_isr_SetVector(cyisraddress address);
cyisraddress ms_isr_GetVector(void);

void ms_isr_SetPriority(uint8 priority);
uint8 ms_isr_GetPriority(void);

void ms_isr_Enable(void);
uint8 ms_isr_GetState(void);
void ms_isr_Disable(void);

void ms_isr_SetPending(void);
void ms_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ms_isr ISR. */
#define ms_isr_INTC_VECTOR            ((reg32 *) ms_isr__INTC_VECT)

/* Address of the ms_isr ISR priority. */
#define ms_isr_INTC_PRIOR             ((reg8 *) ms_isr__INTC_PRIOR_REG)

/* Priority of the ms_isr interrupt. */
#define ms_isr_INTC_PRIOR_NUMBER      ms_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ms_isr interrupt. */
#define ms_isr_INTC_SET_EN            ((reg32 *) ms_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ms_isr interrupt. */
#define ms_isr_INTC_CLR_EN            ((reg32 *) ms_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ms_isr interrupt state to pending. */
#define ms_isr_INTC_SET_PD            ((reg32 *) ms_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ms_isr interrupt. */
#define ms_isr_INTC_CLR_PD            ((reg32 *) ms_isr__INTC_CLR_PD_REG)


#endif /* CY_ISR_ms_isr_H */


/* [] END OF FILE */
