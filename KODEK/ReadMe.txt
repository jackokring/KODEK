================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : KODEK Project Overview
===============================================================================

04 Jul 2015: Started writing thread.cpp, done main switch and commented function outline.
-----------------------------------------------------------------------------------------
Security dialog only for automation. Middleware for insulating thread.cpp from external
symantics. Still need a checksum block storage strategy, and wrapper layer on algorithm.

29 Jun 2015: Everything apart from the thread.cpp glue class is written.
------------------------------------------------------------------------
Added a decompression security warning dialog, so that automated file overwrite is
not done automatically. Must be the DEFCON video on Youtube I watched today.

NOTES:
The thead class must check the TERM state to kill off background threads.
The compression must add in some kind of checksum information.
The decompression must remove and check it.
I must find out how to make a WDK DirectDraw Source Filter for streaming.
I must add some multifile archive support.