/*******************************************************************************
* File Name: xbee_reset.h  
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

#if !defined(CY_PINS_xbee_reset_H) /* Pins xbee_reset_H */
#define CY_PINS_xbee_reset_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "xbee_reset_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 xbee_reset__PORT == 15 && ((xbee_reset__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    xbee_reset_Write(uint8 value);
void    xbee_reset_SetDriveMode(uint8 mode);
uint8   xbee_reset_ReadDataReg(void);
uint8   xbee_reset_Read(void);
void    xbee_reset_SetInterruptMode(uint16 position, uint16 mode);
uint8   xbee_reset_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the xbee_reset_SetDriveMode() function.
     *  @{
     */
        #define xbee_reset_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define xbee_reset_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define xbee_reset_DM_RES_UP          PIN_DM_RES_UP
        #define xbee_reset_DM_RES_DWN         PIN_DM_RES_DWN
        #define xbee_reset_DM_OD_LO           PIN_DM_OD_LO
        #define xbee_reset_DM_OD_HI           PIN_DM_OD_HI
        #define xbee_reset_DM_STRONG          PIN_DM_STRONG
        #define xbee_reset_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define xbee_reset_MASK               xbee_reset__MASK
#define xbee_reset_SHIFT              xbee_reset__SHIFT
#define xbee_reset_WIDTH              1u

/* Interrupt constants */
#if defined(xbee_reset__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in xbee_reset_SetInterruptMode() function.
     *  @{
     */
        #define xbee_reset_INTR_NONE      (uint16)(0x0000u)
        #define xbee_reset_INTR_RISING    (uint16)(0x0001u)
        #define xbee_reset_INTR_FALLING   (uint16)(0x0002u)
        #define xbee_reset_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define xbee_reset_INTR_MASK      (0x01u) 
#endif /* (xbee_reset__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define xbee_reset_PS                     (* (reg8 *) xbee_reset__PS)
/* Data Register */
#define xbee_reset_DR                     (* (reg8 *) xbee_reset__DR)
/* Port Number */
#define xbee_reset_PRT_NUM                (* (reg8 *) xbee_reset__PRT) 
/* Connect to Analog Globals */                                                  
#define xbee_reset_AG                     (* (reg8 *) xbee_reset__AG)                       
/* Analog MUX bux enable */
#define xbee_reset_AMUX                   (* (reg8 *) xbee_reset__AMUX) 
/* Bidirectional Enable */                                                        
#define xbee_reset_BIE                    (* (reg8 *) xbee_reset__BIE)
/* Bit-mask for Aliased Register Access */
#define xbee_reset_BIT_MASK               (* (reg8 *) xbee_reset__BIT_MASK)
/* Bypass Enable */
#define xbee_reset_BYP                    (* (reg8 *) xbee_reset__BYP)
/* Port wide control signals */                                                   
#define xbee_reset_CTL                    (* (reg8 *) xbee_reset__CTL)
/* Drive Modes */
#define xbee_reset_DM0                    (* (reg8 *) xbee_reset__DM0) 
#define xbee_reset_DM1                    (* (reg8 *) xbee_reset__DM1)
#define xbee_reset_DM2                    (* (reg8 *) xbee_reset__DM2) 
/* Input Buffer Disable Override */
#define xbee_reset_INP_DIS                (* (reg8 *) xbee_reset__INP_DIS)
/* LCD Common or Segment Drive */
#define xbee_reset_LCD_COM_SEG            (* (reg8 *) xbee_reset__LCD_COM_SEG)
/* Enable Segment LCD */
#define xbee_reset_LCD_EN                 (* (reg8 *) xbee_reset__LCD_EN)
/* Slew Rate Control */
#define xbee_reset_SLW                    (* (reg8 *) xbee_reset__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define xbee_reset_PRTDSI__CAPS_SEL       (* (reg8 *) xbee_reset__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define xbee_reset_PRTDSI__DBL_SYNC_IN    (* (reg8 *) xbee_reset__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define xbee_reset_PRTDSI__OE_SEL0        (* (reg8 *) xbee_reset__PRTDSI__OE_SEL0) 
#define xbee_reset_PRTDSI__OE_SEL1        (* (reg8 *) xbee_reset__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define xbee_reset_PRTDSI__OUT_SEL0       (* (reg8 *) xbee_reset__PRTDSI__OUT_SEL0) 
#define xbee_reset_PRTDSI__OUT_SEL1       (* (reg8 *) xbee_reset__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define xbee_reset_PRTDSI__SYNC_OUT       (* (reg8 *) xbee_reset__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(xbee_reset__SIO_CFG)
    #define xbee_reset_SIO_HYST_EN        (* (reg8 *) xbee_reset__SIO_HYST_EN)
    #define xbee_reset_SIO_REG_HIFREQ     (* (reg8 *) xbee_reset__SIO_REG_HIFREQ)
    #define xbee_reset_SIO_CFG            (* (reg8 *) xbee_reset__SIO_CFG)
    #define xbee_reset_SIO_DIFF           (* (reg8 *) xbee_reset__SIO_DIFF)
#endif /* (xbee_reset__SIO_CFG) */

/* Interrupt Registers */
#if defined(xbee_reset__INTSTAT)
    #define xbee_reset_INTSTAT            (* (reg8 *) xbee_reset__INTSTAT)
    #define xbee_reset_SNAP               (* (reg8 *) xbee_reset__SNAP)
    
	#define xbee_reset_0_INTTYPE_REG 		(* (reg8 *) xbee_reset__0__INTTYPE)
#endif /* (xbee_reset__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_xbee_reset_H */


/* [] END OF FILE */
