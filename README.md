# memevey-m68k

memevey-m68k is a single dialog box.

memevey-m68k requires Retro68 to compile. Follow the instructions in CMakeLists.txt to compile it (if you're into that).

The release should work just as well. It should work on just about any 68k Macintosh (I got it to work minus the picture in the 128k version of MiniVMac with System Software 1.1g and even the Oct. 4 1983 Sony Test 7.0 beta, but YMMV).

pika.r is a file containing a single PICT resource obtained by:
  1. Selecting part of an image in an image editor and copy/pasting it into a ResEdit resource.
  2. Decompiling the resulting ResEdit file with DeRez.
  
If you know of a better way of getting PICT resources, please tell me!
