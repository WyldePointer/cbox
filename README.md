### cbox

A piece of code for drawing simple ASCII boxes.

```sh
$ ./cbox 30 10
+----------------------------+
+                            +
+                            +
+                            +
+                            +
+                            +
+                            +
+                            +
+                            +
+----------------------------+
```

```sh
$ ./cbox 15 5 '~'
+-------------+
+~~~~~~~~~~~~~+
+~~~~~~~~~~~~~+
+~~~~~~~~~~~~~+
+-------------+
```

#### Usage
`Usage: ./unbuffered <width> <height> [char_to_fill]`

#### Compiling
`$ cc -o cbox -Wall -pedantic -std=c89 cbox.c`

#### FAQ
Q) What's the "buffered" version?

A) It's the same code but it stores the characters in a line buffer
 which is dynamically allocated. The main reason for that version was comparing
 the performance of (`width` * `height`) times of `putc()` with `malloc()` +
 `width` times of `puts` which indeed turned out to be slower, since `malloc()`
 is a truly expensive call. 

Q) How to store the output in a file?

A) `$ ./cbox 30 10 > /tmp/my.txt`

#### TODO
 - Optimization. (I feel like it should work even faster.)
 - Testing on various compilers on various OS / distributions.
 - `getopt()`
