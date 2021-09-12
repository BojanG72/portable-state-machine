#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "time.h"

#define USE_ASSERT (1)
#ifdef USE_ASSERT
#define ASSERT(x)  assert(x)
#else
#define ASSERT (x)  void()
#endif

//////////////////////////////////////////////////
/// COMMON FUNCTION PROTOTYPES
//////////////////////////////////////////////////
void    printTime  (void);

#endif // COMMON_H
