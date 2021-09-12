#ifndef LIGHTSTATEMACHINE_H
#define LIGHTSTATEMACHINE_H

#include "stateMachine.h"
#include "common.h"


/**
 * All possible states for this state machine
 * */
typedef enum
{
    RED,
    YELLOW,
    GREEN,
    FLASHING_RED,
    ////////////
    NUM_OF_STATES
} LightStates_t;

/**
 * All possible events
 * */
typedef enum
{
    RED_TIMEOUT,
    YELLOW_TIMEOUT,
    GREEN_TIMEOUT,
    //////////////
    NUM_OF_EVENTS
} LightEvents_t;


/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 * ***************************************************************************/
stateMachine_t * LIGHT_GetStateMachine ( void );

#endif // LIGHTSTATEMACHINE_H
