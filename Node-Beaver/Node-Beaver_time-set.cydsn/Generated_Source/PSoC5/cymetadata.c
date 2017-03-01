/*******************************************************************************
* File Name: cymetadata.c
* 
* PSoC Creator  4.0 Update 1
*
* Description:
* This file defines all extra memory spaces that need to be included.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2016 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include "cytypes.h"


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_CONFIG_ECC_SECTION
#define CY_CONFIG_ECC_SECTION __attribute__ ((__section__(".cyconfigecc"), used))
#endif
CY_CONFIG_ECC_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cyconfigecc"
#else
#error "Unsupported toolchain"
#endif
const uint8 cy_meta_configecc[] = {
    0x02u, 0x52u, 0x00u, 0x40u, 0x02u, 0x64u, 0x00u, 0x40u,
    0x01u, 0x03u, 0x01u, 0x40u, 0x26u, 0x0Au, 0x01u, 0x40u,
    0x0Au, 0x0Bu, 0x01u, 0x40u, 0x1Du, 0x0Cu, 0x01u, 0x40u,
    0x0Fu, 0x0Du, 0x01u, 0x40u, 0x30u, 0x0Eu, 0x01u, 0x40u,
    0x16u, 0x0Fu, 0x01u, 0x40u, 0x01u, 0x15u, 0x01u, 0x40u,
    0x01u, 0x1Bu, 0x01u, 0x40u, 0x02u, 0x40u, 0x01u, 0x40u,
    0x02u, 0x41u, 0x01u, 0x40u, 0x02u, 0x42u, 0x01u, 0x40u,
    0x01u, 0x43u, 0x01u, 0x40u, 0x07u, 0x45u, 0x01u, 0x40u,
    0x03u, 0x46u, 0x01u, 0x40u, 0x03u, 0x47u, 0x01u, 0x40u,
    0x01u, 0x48u, 0x01u, 0x40u, 0x02u, 0x49u, 0x01u, 0x40u,
    0x09u, 0x4Cu, 0x01u, 0x40u, 0x01u, 0x4Du, 0x01u, 0x40u,
    0x03u, 0x50u, 0x01u, 0x40u, 0x02u, 0x51u, 0x01u, 0x40u,
    0x11u, 0x40u, 0x14u, 0x60u, 0x8Cu, 0x0Du, 0x8Fu, 0x0Du,
    0xEEu, 0x08u, 0x40u, 0x54u, 0x49u, 0xFFu, 0x4Au, 0xFFu,
    0x4Bu, 0xFFu, 0x4Fu, 0x01u, 0x50u, 0x18u, 0x5Au, 0x04u,
    0x5Fu, 0x01u, 0x60u, 0x40u, 0x62u, 0x40u, 0x64u, 0x40u,
    0x65u, 0x40u, 0x66u, 0x80u, 0x68u, 0x80u, 0x6Au, 0x80u,
    0x6Cu, 0x80u, 0x6Eu, 0x80u, 0xC0u, 0x14u, 0xC9u, 0xFFu,
    0xCAu, 0xFFu, 0xCBu, 0xFFu, 0xCDu, 0x83u, 0xCEu, 0x03u,
    0xCFu, 0x01u, 0xD0u, 0x18u, 0xD2u, 0x80u, 0xDAu, 0x04u,
    0xDBu, 0x04u, 0xDFu, 0x01u, 0xE0u, 0x40u, 0xE2u, 0x40u,
    0xE4u, 0x40u, 0xE5u, 0x40u, 0xE6u, 0x80u, 0xE8u, 0x80u,
    0xEAu, 0x80u, 0xECu, 0x80u, 0xEEu, 0x80u, 0x42u, 0x80u,
    0x46u, 0x80u, 0x47u, 0x80u, 0x48u, 0x01u, 0x74u, 0x01u,
    0x77u, 0x80u, 0x9Au, 0x80u, 0x9Fu, 0x80u, 0xD0u, 0x91u,
    0xD2u, 0x08u, 0x22u, 0x01u, 0x2Eu, 0x01u, 0x30u, 0x01u,
    0x3Eu, 0x01u, 0x40u, 0x14u, 0x45u, 0xECu, 0x46u, 0x02u,
    0x48u, 0x07u, 0x49u, 0xFFu, 0x4Au, 0xFFu, 0x4Bu, 0xFFu,
    0x4Du, 0x83u, 0x4Eu, 0x03u, 0x4Fu, 0x01u, 0x50u, 0x18u,
    0x54u, 0x01u, 0x58u, 0x04u, 0x5Au, 0x04u, 0x5Bu, 0x04u,
    0x5Fu, 0x01u, 0x60u, 0x40u, 0x62u, 0x40u, 0x64u, 0x40u,
    0x65u, 0x40u, 0x66u, 0x80u, 0x68u, 0x80u, 0x6Au, 0x80u,
    0x6Cu, 0x80u, 0x6Eu, 0x80u, 0x16u, 0x80u, 0x17u, 0x80u,
    0x1Eu, 0x80u, 0x46u, 0x80u, 0x47u, 0x80u, 0x4Du, 0x04u,
    0x4Fu, 0x01u, 0x56u, 0x80u, 0x5Du, 0x04u, 0x5Eu, 0x80u,
    0x5Fu, 0x01u, 0xAFu, 0x20u, 0xC4u, 0x90u, 0xD0u, 0x90u,
    0xD6u, 0xD0u, 0x40u, 0x51u, 0x49u, 0xFFu, 0x4Au, 0xFFu,
    0x4Bu, 0xFFu, 0x4Fu, 0x01u, 0x50u, 0x18u, 0x5Au, 0x04u,
    0x5Fu, 0x01u, 0x60u, 0x40u, 0x62u, 0x40u, 0x64u, 0x40u,
    0x65u, 0x40u, 0x66u, 0x80u, 0x68u, 0x80u, 0x6Au, 0x80u,
    0x6Cu, 0x80u, 0x6Eu, 0x80u, 0x9Eu, 0x01u, 0xAEu, 0x01u,
    0xB0u, 0x01u, 0xB4u, 0x01u, 0xBEu, 0x01u, 0xC0u, 0x41u,
    0xC5u, 0xECu, 0xC6u, 0x02u, 0xC8u, 0x07u, 0xC9u, 0xFFu,
    0xCAu, 0xFFu, 0xCBu, 0xFFu, 0xCDu, 0x83u, 0xCEu, 0x03u,
    0xCFu, 0x01u, 0xD0u, 0x18u, 0xD2u, 0x80u, 0xD4u, 0x01u,
    0xD8u, 0x04u, 0xDAu, 0x04u, 0xDBu, 0x04u, 0xDFu, 0x01u,
    0xE0u, 0x40u, 0xE2u, 0x40u, 0xE4u, 0x40u, 0xE5u, 0x40u,
    0xE6u, 0x80u, 0xE8u, 0x80u, 0xEAu, 0x80u, 0xECu, 0x80u,
    0xEEu, 0x80u, 0x0Du, 0x80u, 0x17u, 0x80u, 0x1Eu, 0x80u,
    0x1Fu, 0x20u, 0x41u, 0x80u, 0x45u, 0x80u, 0x46u, 0x40u,
    0x48u, 0x01u, 0x4Du, 0x04u, 0x4Fu, 0x01u, 0x55u, 0x80u,
    0x5Du, 0x04u, 0x5Eu, 0x80u, 0x5Fu, 0x01u, 0x74u, 0x01u,
    0x76u, 0x40u, 0x77u, 0x80u, 0xC2u, 0x80u, 0xC4u, 0x80u,
    0xD0u, 0x98u, 0xD2u, 0x08u, 0xD6u, 0xD0u, 0xEAu, 0x01u,
    0xEAu, 0x01u, 0x33u, 0x20u, 0xCCu, 0x10u, 0xAFu, 0x20u,
    0xEEu, 0x10u, 0x3Eu, 0x10u, 0xCEu, 0x20u, 0x96u, 0x10u,
    0x08u, 0x20u, 0x0Cu, 0x01u, 0x5Bu, 0x08u, 0x62u, 0x10u,
    0xC2u, 0x06u, 0xD6u, 0x02u, 0xD8u, 0x02u, 0x98u, 0x21u,
    0x9Eu, 0x10u, 0x9Fu, 0x08u, 0x98u, 0x21u, 0x9Eu, 0x10u,
    0x9Fu, 0x08u, 0x96u, 0x10u, 0xAAu, 0x10u, 0xEAu, 0x80u,
    0x13u, 0x28u, 0x16u, 0x10u, 0x78u, 0x01u, 0x7Cu, 0x20u,
    0x98u, 0x21u, 0x9Eu, 0x10u, 0x9Fu, 0x08u, 0xC4u, 0x0Eu,
    0xDEu, 0x03u, 0xABu, 0x20u, 0x00u, 0x01u, 0x0Cu, 0x01u,
    0x0Eu, 0x01u, 0x00u, 0x03u, 0x03u, 0xC0u, 0x00u, 0x00u,
    0x00u, 0x0Bu, 0x0Bu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x60u, 0x00u, 0x00u, 0x00u, 0x60u, 0x00u, 0x60u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_CUST_NVL_SECTION
#define CY_CUST_NVL_SECTION __attribute__ ((__section__(".cycustnvl"), used))
#endif
CY_CUST_NVL_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cycustnvl"
#else
#error "Unsupported toolchain"
#endif
const uint8 cy_meta_custnvl[] = {
    0x00u, 0x00u, 0x40u, 0x05u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_WO_NVL_SECTION
#define CY_WO_NVL_SECTION __attribute__ ((__section__(".cywolatch"), used))
#endif
CY_WO_NVL_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cywolatch"
#else
#error "Unsupported toolchain"
#endif
const uint8 cy_meta_wonvl[] = {
    0xBCu, 0x90u, 0xACu, 0xAFu
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_FLASH_PROT_SECTION
#define CY_FLASH_PROT_SECTION __attribute__ ((__section__(".cyflashprotect"), used))
#endif
CY_FLASH_PROT_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cyflashprotect"
#else
#error "Unsupported toolchain"
#endif
const uint8 cy_meta_flashprotect[] = {
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_META_SECTION
#define CY_META_SECTION __attribute__ ((__section__(".cymeta"), used))
#endif
CY_META_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cymeta"
#else
#error "Unsupported toolchain"
#endif
const uint8 cy_metadata[] = {
    0x00u, 0x01u, 0x2Eu, 0x12u, 0x30u, 0x69u, 0x00u, 0x01u,
    0x00u, 0x00u, 0x00u, 0x00u
};
