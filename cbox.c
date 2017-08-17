/*
 * Copyright (c) 2017, Sohrab Monfared <sohrab.monfared@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  unsigned int pos, row, width, height;
  char char_to_fill = ' ';

  if (argc < 3){

    fprintf(stderr, "Usage: %s <width> <height> [char_to_fill]\n",
      argv[0]);

    return -1;
  }

  pos = 0;
  row = 0;
  width = abs(atoi(argv[1]));
  height = abs(atoi(argv[2]));

  if (argc > 3){
    char_to_fill = argv[3][0];
  }

  while (++pos){

    if ( pos > width * height){
      break;
    }

    if (pos % width == 1){
      putc('+', stdout);
      continue;
    }

    if (pos % width != 0){

      if ( (row == 0 || row == height-1) ){
        putc('-', stdout);
      } else {
        putc(char_to_fill, stdout);
      }

    } else {

      row++;

      puts("+");

      continue;

    }

  }

  return 0;
}
