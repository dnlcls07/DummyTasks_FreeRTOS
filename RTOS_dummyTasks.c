/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    RTOS_dummyTasks.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"


void dummy_task1(void)
{
	uint8_t counter = 0;
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(2000);
	xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{
		PRINTF("IN TASK 1: %i +++++++++++++++\r\n", counter);
		counter++;
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}

void dummy_task2(void)
{
	uint8_t counter = 0;
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(1000);
	xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{
		PRINTF("IN TASK 2: %i ***************\r\n", counter);
		counter++;
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}

void dummy_task3(void)
{
	uint8_t counter = 0;
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(4000);
	xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{
		PRINTF("IN TASK 3: %i ---------------\r\n", counter);
		counter++;
		vTaskDelayUntil(&xLastWakeTime, xPeriod);
	}
}

int main(void)
{
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	TaskHandle_t dummy1Handle = NULL;
	TaskHandle_t dummy2Handle = NULL;
	TaskHandle_t dummy3Handle = NULL;

	xTaskCreate(dummy_task1,"DUMMY1",110,NULL,2,&dummy1Handle);
	xTaskCreate(dummy_task2,"DUMMY2",110,NULL,3,&dummy2Handle);
	xTaskCreate(dummy_task3,"DUMMY3",110,NULL,2,&dummy3Handle);
	vTaskStartScheduler();

	for (;;)
	{
		__asm("NOP");
	}
}
