#include "stateMachine.h"
#include "lightStateMachine.h"
#include "common.h"

/******************************************************************************
 * DEFINES
 * ***************************************************************************/
#define FSM_DBG(...)       printf("FSM  "); printTime(); printf(__VA_ARGS__)


/******************************************************************************
 * PUBLIC FUNCTIONS
 * ***************************************************************************/

/**
 * This function will return a pointer to the specified state machine
 * */

stateMachine_t * getStateMachine ( stateMachineType_t stateMachineType )
{
    stateMachine_t * retSateMachine = NULL;

    ///< Check that the state machine type is valid
    ASSERT(stateMachineType < NUM_OF_FSM);

    switch (stateMachineType)
    {
        case LIGHT_FSM:
        {
            retSateMachine = LIGHT_GetStateMachine();
        }
        break;
        ///////////////////////////////
        default:
        {
            FSM_DBG("Unknown state machine\n");
        }
    }

    return (retSateMachine);
}


