#include "contiki.h"
#include "dev/leds.h"

#include <stdio.h>

/* Bien i dung chung cho 2 thread */
static int i = 0;


/* ================= THREAD 1 ================= */

PROCESS(thread1_process, "Thread 1 - RED");

PROCESS_THREAD(thread1_process, ev, data)
{
  static struct etimer timer1;

  PROCESS_BEGIN();

  etimer_set(&timer1, 3 * CLOCK_SECOND);

  while(1) {

    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer1));

    leds_toggle(LEDS_RED);

    printf("Thread 1: i = %d\n", i);

    i = i + 2;

    etimer_reset(&timer1);
  }

  PROCESS_END();
}


/* ================= THREAD 2 ================= */

PROCESS(thread2_process, "Thread 2 - GREEN");

PROCESS_THREAD(thread2_process, ev, data)
{
  static struct etimer timer2;

  PROCESS_BEGIN();

  etimer_set(&timer2, 5 * CLOCK_SECOND);

  while(1) {

    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer2));

    leds_toggle(LEDS_GREEN);

    printf("Thread 2: i = %d\n", i);

    i = i + 5;

    etimer_reset(&timer2);
  }

  PROCESS_END();
}


AUTOSTART_PROCESSES(&thread1_process, &thread2_process);