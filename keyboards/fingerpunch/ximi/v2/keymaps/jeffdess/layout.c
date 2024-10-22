/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "layout.h"

#ifdef RGB_MATRIX_ENABLE

// Layout
//
// ┌────────────────────────┐                 ┌────────────────────────┐
// │ 18  17  12  11  06  05 │                 │ 26  27  32  33  38  39 │
// │────────────────────────┤                 ├────────────────────────│
// │ 19  16  13  10  07  04 │                 │ 25  28  31  34  37  40 │
// ├────────────────────────┤                 ├────────────────────────┤
// │ 20  15  14  09  08  03 │                 │ 24  29  30  35  36  41 │
// └───────────────────┬────┴───────┐ ┌───────┴────┬───────────────────┘
//                     │ 02  01  00 │ │ 21  22  23 │
//                     └────────────┘ └────────────┘
//
//

// clang-format off
led_config_t g_led_config = { {
//COL   00     01   02   03   04   05              ROW
    { NO_LED,  17,  12,  11,   5,   4          },//00
    { NO_LED,  16,  13,  10,   6,   3          },//01
    { NO_LED,  15,  14,   9,   7,   2          },//02
    { NO_LED,   8,   1,   0, NO_LED, NO_LED    },//03
    { NO_LED,  35,  30,  29,  23,  22          },//00
    { NO_LED,  34,  31,  28,  24,  21          },//01
    { NO_LED,  33,  32,  27,  25,  20          },//02
    { NO_LED,  26,  19,  18, NO_LED,  NO_LED   } //03
}, {
   //LEFT
   //thumb1 ▼      thumb2 ▼     thumb3 ▼       C0 R3 ▼       C0 R2 ▼       C0 R1 ▼       C1 R1 ▼
                  {  89,  54 }, {  74,  49 }, {  75,  34 }, {  75,  21 }, {  75,   8 }, {  60,   6 },
   //C1 R2 ▼       C1 R3 ▼       thumb4 ▼      C2 R3 ▼       C2 R2 ▼       C2 R1 ▼       C3 R1 ▼
    {  60,  19 }, {  60,  32 }, {  58,  48 }, {  46,  25 }, {  46,  12 }, {  46,   0 }, {  29,   7 },
   //C3 R2 ▼       C3 R3 ▼       C4 R3 ▼       C4 R2 ▼       C4 R1 ▼       C5 R2 ▼       C5 R3 ▼
    {  30,  20 }, {  31,  33 }, {  17,  42 }, {  15,  30 }, {  13,  17 },
    //RIGHT
   //thumb1 ▼      thumb2 ▼     thumb3 ▼       C0 R3 ▼       C0 R2 ▼       C0 R1 ▼       C1 R1 ▼
                  { 135,  54 }, { 150,  49 }, { 149,  34 }, { 149,  21 }, { 149,   8 }, { 163,   6 },
   //C1 R2 ▼       C1 R3 ▼       thumb4 ▼      C2 R3 ▼       C2 R2 ▼       C2 R1 ▼       C3 R1 ▼
    { 163,  19 }, { 163,  32 }, { 166,  48 }, { 178,  25 }, { 178,  12 }, { 178,   0 }, { 195,   7 },
   //C3 R2 ▼       C3 R3 ▼       C4 R3 ▼       C4 R2 ▼       C4 R1 ▼       C5 R2 ▼       C5 R3 ▼
    { 194,  20 }, { 193,  33 }, { 206,  42 }, { 209,  30 }, { 211,  17 }
}, {
    //LEFT
    1, 1, 4, 4, 4, 4,
    4, 4, 1, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    //RIGHT
    1, 1, 4, 4, 4, 4,
    4, 4, 1, 4, 4, 4, 4,
    4, 4, 4, 4, 4
} };
#endif
