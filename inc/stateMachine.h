#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "common.h"

/******************************************************************************
 * PUBLIC DEFINITIONS
 * ***************************************************************************/

/**
 * Type of state  machine
 * */
typedef enum
{
    LIGHT_FSM,
    //////////////
    NUM_OF_FSM
} stateMachineType_t;

/**
 * Maxiumum possible number of states for any state machine
 * */
typedef enum
{
    MAX_STATES = 10
} state_t;

/**
 * Maximum possible types of events for any state machine
 * */
typedef enum
{
    MAX_EVENTS = 10
} event_t;

 /**
  * This is the definition of the messages that are passed when events occur
  * */
typedef struct _msg
{
    event_t event;
} msg_t;

typedef void        (*initFsm)         ( void );
typedef void        (*processMsg)      ( msg_t * pCurrentMsg );
typedef state_t     (*setState)        ( state_t newState );
typedef void        (*resetFsm)        ( void );

/**
 * This structure defines a standard state machine, and would be used to save the current context of the state machine
 * */
typedef struct _stateMachine
{
    state_t             currentState;
    initFsm             initAndRunStateMachine;
    processMsg          runMachine;
    setState            setMachine;
    resetFsm            resetMachine;

} stateMachine_t;


/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 * ***************************************************************************/

stateMachine_t *  getStateMachine ( stateMachineType_t stateMachineType );


#endif // STATEMACHINE_H
