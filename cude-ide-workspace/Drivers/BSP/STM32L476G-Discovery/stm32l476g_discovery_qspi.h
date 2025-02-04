/**
  ******************************************************************************
  * @file    stm32l476g_discovery_qspi.h
  * @author  MCD Application Team
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm32l476g_discovery_qspi.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L476G_DISCOVERY_QSPI_H
#define __STM32L476G_DISCOVERY_QSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "../Components/n25q128a/n25q128a.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L476G_DISCOVERY
  * @{
  */

/** @addtogroup STM32L476G_DISCOVERY_QSPI
  * @{
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup STM32L476G_DISCOVERY_QSPI_Exported_Constants Exported Constants
  * @{
  */
/* QSPI Error codes */
#define QSPI_OK            ((uint8_t)0x00)
#define QSPI_ERROR         ((uint8_t)0x01)
#define QSPI_BUSY          ((uint8_t)0x02)
#define QSPI_NOT_SUPPORTED ((uint8_t)0x04)
#define QSPI_SUSPENDED     ((uint8_t)0x08)

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup STM32L476G_DISCOVERY_QSPI_Exported_Types Exported Types
  * @{
  */
/* QSPI Info */
typedef struct
{
  uint32_t FlashSize;          /*!< Size of the flash */
  uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
  uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
  uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
  uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} QSPI_Info;

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup STM32L476G_DISCOVERY_QSPI_Exported_Functions Exported Functions
  * @{
  */
uint8_t BSP_QSPI_Init(void);
uint8_t BSP_QSPI_DeInit(void);
uint8_t BSP_QSPI_Read(uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
uint8_t BSP_QSPI_Write(uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
uint8_t BSP_QSPI_Erase_Block(uint32_t BlockAddress);
uint8_t BSP_QSPI_Erase_Sector(uint32_t Sector);
uint8_t BSP_QSPI_Erase_Chip(void);
uint8_t BSP_QSPI_GetStatus(void);
uint8_t BSP_QSPI_GetInfo(QSPI_Info *pInfo);
uint8_t BSP_QSPI_EnableMemoryMappedMode(void);
uint8_t BSP_QSPI_SuspendErase(void);
uint8_t BSP_QSPI_ResumeErase(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L476G_DISCOVERY_QSPI_H */


