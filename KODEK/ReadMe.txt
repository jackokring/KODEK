================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : KODEK Project Overview
===============================================================================

29 Jun 2015: Everything apart from the thead.cpp glue class is written.
-----------------------------------------------------------------------
Added a decompression security warning dialog, so that automated file overwrite is
not done automatically. Must be the DEFCON video on Youtube I watched today.

NOTES:
The thead class must check the TERM state to kill off background threads.
The compression must add in some kind of checksum information.
The decompression must remove and check it.
I must find out how to make a WDK DirectDraw Source Filter for streaming.
I must add some multifile archive support.