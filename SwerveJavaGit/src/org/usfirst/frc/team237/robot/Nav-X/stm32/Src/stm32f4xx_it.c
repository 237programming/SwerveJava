/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @date    31/10/2014 11:34:33
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/* External variables --------------------------------------------------------*/

extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern I2C_HandleTypeDef hi2c3;
extern SPI_HandleTypeDef hspi1;
extern UART_HandleTypeDef huart6;
extern TIM_HandleTypeDef    TimHandle;
extern DMA_HandleTypeDef hdma_spi1_tx;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles DMA2 Stream2 global interrupt.
*/
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(DMA2_Stream2_IRQn);
  HAL_DMA_IRQHandler(&hdma_spi1_tx);
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
* @brief This function handles USB On The Go FS global interrupt.
*/
void OTG_FS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_FS_IRQn 0 */

  /* USER CODE END OTG_FS_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(OTG_FS_IRQn);
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
  /* USER CODE BEGIN OTG_FS_IRQn 1 */

  /* USER CODE END OTG_FS_IRQn 1 */
}

/**
* @brief This function handles I2C3 event interrupt.
*/
void I2C3_EV_IRQHandler(void)
{
  /* USER CODE BEGIN I2C3_EV_IRQn 0 */

  /* USER CODE END I2C3_EV_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(I2C3_EV_IRQn);
  HAL_I2C_EV_IRQHandler(&hi2c3);
  /* USER CODE BEGIN I2C3_EV_IRQn 1 */

  /* USER CODE END I2C3_EV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/**
* @brief This function handles USB On-The-Go FS Wakeup through EXTI Line18 interrupt.
*/
void OTG_FS_WKUP_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_FS_WKUP_IRQn 0 */

  /* USER CODE END OTG_FS_WKUP_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(OTG_FS_WKUP_IRQn);
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
  /* USER CODE BEGIN OTG_FS_WKUP_IRQn 1 */

  /* USER CODE END OTG_FS_WKUP_IRQn 1 */
}

/**
* @brief This function handles I2C3 error interrupt.
*/
void I2C3_ER_IRQHandler(void)
{
  /* USER CODE BEGIN I2C3_ER_IRQn 0 */

  /* USER CODE END I2C3_ER_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(I2C3_ER_IRQn);
  HAL_I2C_ER_IRQHandler(&hi2c3);
  /* USER CODE BEGIN I2C3_ER_IRQn 1 */

  /* USER CODE END I2C3_ER_IRQn 1 */
}

/**
* @brief This function handles SPI1 global interrupt.
*/
void SPI1_IRQHandler(void)
{
  /* USER CODE BEGIN SPI1_IRQn 0 */

  /* USER CODE END SPI1_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(SPI1_IRQn);
  HAL_SPI_IRQHandler(&hspi1);
  /* USER CODE BEGIN SPI1_IRQn 1 */

  /* USER CODE END SPI1_IRQn 1 */
}

/**
* @brief This function handles USART6 global interrupt.
*/
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_NVIC_ClearPendingIRQ(USART6_IRQn);
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}

/**
* @brief This function handles EXTI Line[9:5] interrupts.
*/
void EXTI9_5_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(EXTI9_5_IRQn);

  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

/* USER CODE BEGIN 1 */

void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle);
}

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
