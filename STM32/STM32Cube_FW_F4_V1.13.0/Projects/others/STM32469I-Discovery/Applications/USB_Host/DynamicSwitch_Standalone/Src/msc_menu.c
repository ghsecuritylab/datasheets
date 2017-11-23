/**
  ******************************************************************************
  * @file    USB_Host/DynamicSwitch_Standalone/Src/menu.c 
  * @author  MCD Application Team
  * @version V1.0.5
  * @date    03-June-2016
  * @brief   This file implements MSC Menu Functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright � 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
MSC_DEMO_StateMachine msc_demo;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Manages MSC Menu Process.
  * @param  None
  * @retval None
  */
void MSC_MenuProcess(void)
{
  switch(msc_demo.state)
  {
  case MSC_DEMO_START:
    if(Appli_state == APPLICATION_MSC)
    {
      BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
      BSP_LCD_DisplayStringAtLine(19, (uint8_t *)"Press User button to start read and write operations");
      
      /* Wait for User Input */
      while((BSP_PB_GetState(BUTTON_WAKEUP) != SET) && (Appli_state != APPLICATION_DISCONNECT))
      {
      }
      msc_demo.state = MSC_DEMO_FILE_OPERATIONS;
      
      /* Prevent debounce effect for user key */
      HAL_Delay(400);
      
      BSP_LCD_ClearStringLine(19);
    }
    break;
    
  case MSC_DEMO_FILE_OPERATIONS:  
    /* Read and Write File Here */
    if(Appli_state == APPLICATION_MSC)
    {
      MSC_File_Operations();
      
      BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
      BSP_LCD_DisplayStringAtLine(19, (uint8_t *)"Press User button to display disk content");
      
      /* Wait for User Input */
      while((BSP_PB_GetState(BUTTON_WAKEUP) != SET) && (Appli_state != APPLICATION_DISCONNECT))
      {
      }
      msc_demo.state = MSC_DEMO_EXPLORER;
      
      /* Prevent debounce effect for user key */
      HAL_Delay(400);
      
      BSP_LCD_ClearStringLine(19);
    }
    break; 
    
  case MSC_DEMO_EXPLORER:
    /* Display disk content */
    if(Appli_state == APPLICATION_MSC)
    {
      /* Register the file system object to the FatFs module */
      if(f_mount(&USBH_fatfs, "", 0 ) != FR_OK )
      {
        LCD_ErrLog("Cannot Initialize FatFs! \n");
      }
      else
      {
        Explore_Disk("0:/", 1);
        msc_demo.state = MSC_DEMO_START;
        
        /* Prevent debounce effect for user key */
        HAL_Delay(400);
      }
    }
    break;

  default:
    break;
  }
} 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
