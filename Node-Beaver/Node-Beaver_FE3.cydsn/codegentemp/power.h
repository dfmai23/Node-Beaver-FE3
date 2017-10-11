/*******************************************************************************
* File Name: power.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_power_H) /* Pins power_H */
#define CY_PINS_power_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "power_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 power__PORT == 15 && ((power__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    power_Write(uint8 value);
void    power_SetDriveMode(uint8 mode);
uint8   power_ReadDataReg(void);
uint8   power_Read(void);
void    power_SetInterruptMode(uint16 position, uint16 mode);
uint8   power_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the power_SetDriveMode() function.
     *  @{
     */
        #define power_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define power_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define power_DM_RES_UP          PIN_DM_RES_UP
        #define power_DM_RES_DWN         PIN_DM_RES_DWN
        #define power_DM_OD_LO           PIN_DM_OD_LO
        #define power_DM_OD_HI           PIN_DM_OD_HI
        #define power_DM_STRONG          PIN_DM_STRONG
        #define power_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define power_MASK               power__MASK
#define power_SHIFT              power__SHIFT
#define power_WIDTH              1u

/* Interrupt constants */
#if defined(power__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in power_SetInterruptMode() function.
     *  @{
     */
        #define power_INTR_NONE      (uint16)(0x0000u)
        #define power_INTR_RISING    (uint16)(0x0001u)
        #define power_INTR_FALLING   (uint16)(0x0002u)
        #define power_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define power_INTR_MASK      (0x01u) 
#endif /* (power__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define power_PS                     (* (reg8 *) power__PS)
/* Data Register */
#define power_DR                     (* (reg8 *) power__DR)
/* Port Number */
#define power_PRT_NUM                (* (reg8 *) power__PRT) 
/* Connect to Analog Globals */                                                  
#define power_AG                     (* (reg8 *) power__AG)                       
/* Analog MUX bux enable */
#define power_AMUX                   (* (reg8 *) power__AMUX) 
/* Bidirectional Enable */                                                        
#define power_BIE                    (* (reg8 *) power__BIE)
/* Bit-mask for Aliased Register Access */
#define power_BIT_MASK               (* (reg8 *) power__BIT_MASK)
/* Bypass Enable */
#define power_BYP                    (* (reg8 *) power__BYP)
/* Port wide control signals */                                                   
#define power_CTL                    (* (reg8 *) power__CTL)
/* Drive Modes */
#define power_DM0                    (* (reg8 *) power__DM0) 
#define power_DM1                    (* (reg8 *) power__DM1)
#define power_DM2                    (* (reg8 *) power__DM2) 
/* Input Buffer Disable Override */
#define power_INP_DIS                (* (reg8 *) power__INP_DIS)
/* LCD Common or Segment Drive */
#define power_LCD_COM_SEG            (* (reg8 *) power__LCD_COM_SEG)
/* Enable Segment LCD */
#define power_LCD_EN                 (* (reg8 *) power__LCD_EN)
/* Slew Rate Control */
#define power_SLW                    (* (reg8 *) power__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define power_PRTDSI__CAPS_SEL       (* (reg8 *) power__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define power_PRTDSI__DBL_SYNC_IN    (* (reg8 *) power__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define power_PRTDSI__OE_SEL0        (* (reg8 *) power__PRTDSI__OE_SEL0) 
#define power_PRTDSI__OE_SEL1        (* (reg8 *) power__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define power_PRTDSI__OUT_SEL0       (* (reg8 *) power__PRTDSI__OUT_SEL0) 
#define power_PRTDSI__OUT_SEL1       (* (reg8 *) power__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define power_PRTDSI__SYNC_OUT       (* (reg8 *) power__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(power__SIO_CFG)
    #define power_SIO_HYST_EN        (* (reg8 *) power__SIO_HYST_EN)
    #define power_SIO_REG_HIFREQ     (* (reg8 *) power__SIO_REG_HIFREQ)
    #define power_SIO_CFG            (* (reg8 *) power__SIO_CFG)
    #define power_SIO_DIFF           (* (reg8 *) power__SIO_DIFF)
#endif /* (power__SIO_CFG) */

/* Interrupt Registers */
#if defined(power__INTSTAT)
    #define power_INTSTAT            (* (reg8 *) power__INTSTAT)
    #define power_SNAP               (* (reg8 *) power__SNAP)
    
	#define power_0_INTTYPE_REG 		(* (reg8 *) power__0__INTTYPE)
#endif /* (power__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_power_H */


/* [] END OF FILE */
