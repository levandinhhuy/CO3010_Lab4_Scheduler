/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2025
 *      Author: dinhh
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"

typedef struct
{
	// Pointer to the task (must be a "void (void)" function)
	void (*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	// Save the ID of the task. In this LAB, this will be the index in task List
	uint32_t TaskID;

} sTask;

struct Node
{
	sTask data;
	int32_t next;
};

enum ErrorCode
{
	INITIAL,
	ERROR_SCH_EXCEED_MAX_TASK,
	ERROR_SCH_EMPTY_LIST_CAN_NOT_REMOVED,
	ERROR_SCH_EMPTY_LIST_CAN_NOT_DELETE
};

#define RETURN_ERROR 0
#define RETURN_NORMAL 1
#define RETURN_ADD_ERROR UINT32_MAX

// MUST BE ADJUSTED FOR EACH PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

extern struct Node listData[SCH_MAX_TASKS];
extern int32_t head;
extern int32_t freeHead;
extern enum ErrorCode Error_code_G;

void resetNodeData(int32_t index);
void initFreeList();
void List_init();
int32_t List_getFreeIndex();
void List_freeIndex(int32_t index);
uint8_t List_isEmpty();
void List_insert(int32_t freeIndex);
void List_removeHead();

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);
void SCH_Report_Status();
void SCH_Go_To_Sleep();


#endif /* INC_SCHEDULER_H_ */
