#include "contiki.h"
#include "dev/leds.h"
#include <stdio.h>

PROCESS(assignment1_process, "Assignment 1 - Part 1");
AUTOSTART_PROCESSES(&assignment1_process);

PROCESS_THREAD(assignment1_process, ev, data)
{
  static struct etimer timer_red;
  static struct etimer timer_green;

  PROCESS_BEGIN();

  printf("Assignment 1 Part 1 started\n");

  etimer_set(&timer_red, 3 * CLOCK_SECOND);
  etimer_set(&timer_green, 5 * CLOCK_SECOND);

  while(1) {

    PROCESS_WAIT_EVENT();

    if(etimer_expired(&timer_red)) {
      leds_toggle(LEDS_RED);
      printf("RED toggle\n");
      etimer_reset(&timer_red);
    }

    if(etimer_expired(&timer_green)) {
      leds_toggle(LEDS_GREEN);
      printf("GREEN toggle\n");
      etimer_reset(&timer_green);
    }
  }

  PROCESS_END();
}