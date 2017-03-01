/*******************************************************************************
* File Name: xbee_sclk.h  
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

#if !defined(CY_PINS_xbee_sclk_H) /* Pins xbee_sclk_H */
#define CY_PINS_xbee_sclk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "xbee_sclk_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 xbee_sclk__PORT == 15 && ((xbee_sclk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    xbee_sclk_Write(uint8 value);
void    xbee_sclk_SetDriveMode(uint8 mode);
uint8   xbee_sclk_ReadDataReg(void);
uint8   xbee_sclk_Read(void);
void    xbee_sclk_SetInterruptMode(uint16 position, uint16 mode);
uint8   xbee_sclk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the xbee_sclk_SetDriveMode() function.
     *  @{
     */
        #define xbee_sclk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define xbee_sclk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define xbee_sclk_DM_RES_UP          PIN_DM_RES_UP
        #define xbee_sclk_DM_RES_DWN         PIN_DM_RES_DWN
        #define xbee_sclk_DM_OD_LO           PIN_DM_OD_LO
        #define xbee_sclk_DM_OD_HI           PIN_DM_OD_HI
        #define xbee_sclk_DM_STRONG          PIN_DM_STRONG
        #define xbee_sclk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define xbee_sclk_MASK               xbee_sclk__MASK
#define xbee_sclk_SHIFT              xbee_sclk__SHIFT
#define xbee_sclk_WIDTH              1u

/* Interrupt constants */
#if defined(xbee_sclk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in xbee_sclk_SetInterruptMode() function.
     *  @{
     */
        #define xbee_sclk_INTR_NONE      (uint16)(0x0000u)
        #define xbee_sclk_INTR_RISING    (uint16)(0x0001u)
        #define xbee_sclk_INTR_FALLING   (uint16)(0x0002u)
        #define xbee_sclk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define xbee_sclk_INTR_MASK      (0x01u) 
#endif /* (xbee_sclk__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define xbee_sclk_PS                     (* (reg8 *) xbee_sclk__PS)
/* Data Register */
#define xbee_sclk_DR                     (* (reg8 *) xbee_sclk__DR)
/* Port Number */
#define xbee_sclk_PRT_NUM                (* (reg8 *) xbee_sclk__PRT) 
/* Connect to Analog Globals */                                                  
#define xbee_sclk_AG                     (* (reg8 *) xbee_sclk__AG)                       
/* Analog MUX bux enable */
#define xbee_sclk_AMUX                   (* (reg8 *) xbee_sclk__AMUX) 
/* Bidirectional Enable */                                                        
#define xbee_sclk_BIE                    (* (reg8 *) xbee_sclk__BIE)
/* Bit-mask for Aliased Register Access */
#define xbee_sclk_BIT_MASK               (* (reg8 *) xbee_sclk__BIT_MASK)
/* Bypass Enable */
#define xbee_sclk_BYP                    (* (reg8 *) xbee_sclk__BYP)
/* Port wide control signals */                                                   
#define xbee_sclk_CTL                    (* (reg8 *) xbee_sclk__CTL)
/* Drive Modes */
#define xbee_sclk_DM0                    (* (reg8 *) xbee_sclk__DM0) 
#define xbee_sclk_DM1                    (* (reg8 *) xbee_sclk__DM1)
#define xbee_sclk_DM2                    (* (reg8 *) xbee_sclk__DM2) 
/* Input Buffer Disable Override */
#define xbee_sclk_INP_DIS                (* (reg8 *) xbee_sclk__INP_DIS)
/* LCD Common or Segment Drive */
#define xbee_sclk_LCD_COM_SEG            (* (reg8 *) xbee_sclk__LCD_COM_SEG)
/* Enable Segment LCD */
#define xbee_sclk_LCD_EN                 (* (reg8 *) xbee_sclk__LCD_EN)
/* Slew Rate Control */
#define xbee_sclk_SLW                    (* (reg8 *) xbee_sclk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define xbee_sclk_PRTDSI__CAPS_SEL       (* (reg8 *) xbee_sclk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define xbee_sclk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) xbee_sclk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define xbee_sclk_PRTDSI__OE_SEL0        (* (reg8 *) xbee_sclk__PRTDSI__OE_SEL0) 
#define xbee_sclk_PRTDSI__OE_SEL1        (* (reg8 *) xbee_sclk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define xbee_sclk_PRTDSI__OUT_SEL0       (* (reg8 *) xbee_sclk__PRTDSI__OUT_SEL0) 
#define xbee_sclk_PRTDSI__OUT_SEL1       (* (reg8 *) xbee_sclk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define xbee_sclk_PRTDSI__SYNC_OUT       (* (reg8 *) xbee_sclk__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(xbee_sclk__SIO_CFG)
    #define xbee_sclk_SIO_HYST_EN        (* (reg8 *) xbee_sclk__SIO_HYST_EN)
    #define xbee_sclk_SIO_REG_HIFREQ     (* (reg8 *) xbee_sclk__SIO_REG_HIFREQ)
    #define xbee_sclk_SIO_CFG            (* (reg8 *) xbee_sclk__SIO_CFG)
    #define xbee_sclk_SIO_DIFF           (* (reg8 *) xbee_sclk__SIO_DIFF)
#endif /* (xbee_sclk__SIO_CFG) */

/* Interrupt Registers */
#if defined(xbee_sclk__INTSTAT)
    #define xbee_sclk_INTSTAT            (* (reg8 *) xbee_sclk__INTSTAT)
    #define xbee_sclk_SNAP               (* (reg8 *) xbee_sclk__SNAP)
    
	#define xbee_sclk_0_INTTYPE_REG 		(* (reg8 *) xbee_sclk__0__INTTYPE)
#endif /* (xbee_sclk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_xbee_sclk_H */


/* [] END OF FILE */
