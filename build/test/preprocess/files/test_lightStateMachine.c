#include "inc/lightStateMachine.h"
#include "inc/stateMachine.h"
#include "inc/common.h"
#include "/home/bojan/Documents/myRepos/portable-state-machine/vendor/ceedling/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_lightStateMachine_NeedToImplement(void)

{



    stateMachine_t * pLightFsm = 

                                ((void *)0)

                                    ;

    msg_t newMsg;

    newMsg.event = RED_TIMEOUT;



    do {if ((((pLightFsm)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(23))));}} while(0);

    pLightFsm = getStateMachine(LIGHT_FSM);

    do {if ((pLightFsm)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(25)));}} while(0);



    pLightFsm->initAndRunStateMachine();

    UnityAssertEqualNumber((UNITY_INT)((RED)), (UNITY_INT)((pLightFsm->currentState)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);



    pLightFsm->runMachine(&newMsg);

    UnityAssertEqualNumber((UNITY_INT)((GREEN)), (UNITY_INT)((pLightFsm->currentState)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);



    newMsg.event = GREEN_TIMEOUT;

    pLightFsm->runMachine(&newMsg);

    UnityAssertEqualNumber((UNITY_INT)((YELLOW)), (UNITY_INT)((pLightFsm->currentState)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

    pLightFsm->runMachine(&newMsg);

    UnityAssertEqualNumber((UNITY_INT)((YELLOW)), (UNITY_INT)((pLightFsm->currentState)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);



    newMsg.event = YELLOW_TIMEOUT;

    pLightFsm->runMachine(&newMsg);

    UnityAssertEqualNumber((UNITY_INT)((RED)), (UNITY_INT)((pLightFsm->currentState)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}
