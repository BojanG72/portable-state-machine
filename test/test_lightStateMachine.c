#ifdef TEST

#include "unity.h"
#include "common.h"
#include "stateMachine.h"
#include "lightStateMachine.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_lightStateMachine_NeedToImplement(void)
{
    ///< Create a state machine
    stateMachine_t * pLightFsm = NULL;
    msg_t newMsg;
    newMsg.event = RED_TIMEOUT;

    TEST_ASSERT_NULL(pLightFsm);
    pLightFsm = getStateMachine(LIGHT_FSM);
    TEST_ASSERT(pLightFsm);

    pLightFsm->initAndRunStateMachine();
    TEST_ASSERT_EQUAL(RED, pLightFsm->currentState);

    pLightFsm->runMachine(&newMsg);
    TEST_ASSERT_EQUAL(GREEN, pLightFsm->currentState);

    newMsg.event = GREEN_TIMEOUT;
    pLightFsm->runMachine(&newMsg);
    TEST_ASSERT_EQUAL(YELLOW, pLightFsm->currentState);
    pLightFsm->runMachine(&newMsg);
    TEST_ASSERT_EQUAL(YELLOW, pLightFsm->currentState);

    newMsg.event = YELLOW_TIMEOUT;
    pLightFsm->runMachine(&newMsg);
    TEST_ASSERT_EQUAL(RED, pLightFsm->currentState);
}

#endif // TEST
