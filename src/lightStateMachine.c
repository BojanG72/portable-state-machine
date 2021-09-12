#include "lightStateMachine.h"
#include "common.h"

/******************************************************************************
 * DEFINES
 * ***************************************************************************/
#define LIGHT_DBG(...)       printf("LIGHT  "); printTime(); printf(__VA_ARGS__)

/******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 * ***************************************************************************/
static void        LIGHT_resetMachine                  ( void );
static state_t     LIGHT_setState                      ( state_t newState );
static void        LIGHT_InitAndRunStateMachine        ( void );
static void        LIGHT_ProcessMsg                    ( msg_t * pCurrentMsg );

/******************************************************************************
 * PRIVATE VARIABLES
 * ***************************************************************************/
static stateMachine_t LIGHT_stateMachine = {
    .currentState = RED,
    .initAndRunStateMachine = LIGHT_InitAndRunStateMachine,
    .runMachine = LIGHT_ProcessMsg,
    .setMachine = LIGHT_setState,
    .resetMachine = LIGHT_resetMachine
};


////////////////////////////////////////////////////////
/// Functions specific to the LIGH FSM
////////////////////////////////////////////////////////
/**
 * This is the starting point for the example state machine
 * */

void LIGHT_InitAndRunStateMachine ( void )
{
    LIGHT_DBG("Reset the state machine to default values\n");
    LIGHT_stateMachine.resetMachine();
}


void LIGHT_ProcessMsg ( msg_t * pCurrentMsg )
{
    ///< Check the current state
    switch (LIGHT_stateMachine.currentState)
    {
        /////////////////////////////////////
        case RED:
        {
            if (pCurrentMsg->event == RED_TIMEOUT)
            {
                LIGHT_DBG("Red light timeout\n");
                LIGHT_setState(GREEN);
            }
        }
        break;
        /////////////////////////////////////
        case YELLOW:
        {
            if (pCurrentMsg->event == YELLOW_TIMEOUT)
            {
                LIGHT_DBG("Yellow light timeout\n");
                LIGHT_setState(RED);
            }
        }
        break;
        /////////////////////////////////////
        case GREEN:
        {
            if (pCurrentMsg->event == GREEN_TIMEOUT)
            {
                LIGHT_DBG("Green light timeout\n");
                LIGHT_setState(YELLOW);
            }
        }
        break;
        default:
        {
            LIGHT_DBG("Invalid state\n");
        }
    }
}

void LIGHT_resetMachine ( void )
{
    ///< Reset the state to RED
    LIGHT_stateMachine.currentState = RED;
}

state_t LIGHT_setState ( state_t newState )
{
    LIGHT_stateMachine.currentState = newState;
    return (LIGHT_stateMachine.currentState);
}


///< Function that will return a pointer to the LIGHT state machine
stateMachine_t * LIGHT_GetStateMachine ( void )
{
    return (&LIGHT_stateMachine);
}
