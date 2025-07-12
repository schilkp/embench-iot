#include "printf.h"
#include <stdint.h>

uint64_t cycles_total, instr_total, cycle_count, instret_count;

void initialise_board() { printf("mbench: init\n"); }

void __attribute__((noinline)) __attribute__((externally_visible)) start_trigger() {
#if defined(PROFILE) && PROFILE == 1
  __asm__ volatile("csrr %0, mcycle" : "=r"(cycle_count));
  __asm__ volatile("csrr %0, minstret" : "=r"(instret_count));
  cycles_total = -cycle_count;
  instr_total = -instret_count;
#endif
}

void __attribute__((noinline)) __attribute__((externally_visible)) stop_trigger() {
#if defined(PROFILE) && PROFILE == 1
  __asm__ volatile("csrr %0, mcycle" : "=r"(cycle_count));
  __asm__ volatile("csrr %0, minstret" : "=r"(instret_count));
#endif
  printf("mbench: stop\n");
#if defined(PROFILE) && PROFILE == 1
  cycles_total += cycle_count;
  instr_total += instret_count;
  printf("tot_cycles = %d\n\rinstret = %d\n\r", cycles_total, instr_total);
#endif
}
