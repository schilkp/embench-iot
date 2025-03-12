// Copyright 2025 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

   #include <stdint.h>
   #include <support.h>
   #include "regs/cheshire.h"
   #include "dif/clint.h"
   #include "dif/uart.h"
   #include "params.h"
   #include "util.h"
   #include "printf.h"

   void
   initialise_board ()
   {
    uint32_t rtc_freq = *reg32(&__base_regs, CHESHIRE_RTC_FREQ_REG_OFFSET);
    uint64_t reset_freq = clint_get_core_freq(rtc_freq, 2500);
    uart_init(&__base_uart, reset_freq, __BOOT_BAUDRATE);
   }

   void __attribute__ ((noinline)) __attribute__ ((externally_visible))
   start_trigger ()
   {
   }

   void __attribute__ ((noinline)) __attribute__ ((externally_visible))
   stop_trigger ()
   {
   }
