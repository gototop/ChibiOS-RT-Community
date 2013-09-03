/*
    Nil RTOS - Copyright (C) 2012 Giovanni Di Sirio.

    This file is part of Nil RTOS.

    Nil RTOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Nil RTOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "nil.h"

/*
 * Thread 1.
 */
THD_WORKING_AREA(waThread1, 128);
THD_FUNCTION(Thread1, arg) {

  (void)arg;

  while (true) {
//    gpioSetPad(GPIOC, GPIOC_LED4);
    chThdSleepMilliseconds(500);
//    gpioClearPad(GPIOC, GPIOC_LED4);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Thread 2.
 */
THD_WORKING_AREA(waThread2, 128);
THD_FUNCTION(Thread2, arg) {

  (void)arg;

  while (true) {
//    gpioSetPad(GPIOC, GPIOC_LED3);
    chThdSleepMilliseconds(250);
//    gpioClearPad(GPIOC, GPIOC_LED3);
    chThdSleepMilliseconds(250);
  }
}

/*
 * Threads static table, one entry per thread. The number of entries must
 * match NIL_CFG_NUM_THREADS.
 */
THD_TABLE_BEGIN
  THD_TABLE_ENTRY("thread1", Thread1, NULL, waThread1, sizeof(waThread1))
  THD_TABLE_ENTRY("thread2", Thread2, NULL, waThread2, sizeof(waThread2))
THD_TABLE_END

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations:
   * - HW specific initialization.
   * - Nil RTOS initialization.
   */
//  hwInit();
  chSysInit();

  /* This is now the idle thread loop, you may perform here a low priority
     task but you must never try to sleep or wait in this loop.*/
  while (true) {
  }
}