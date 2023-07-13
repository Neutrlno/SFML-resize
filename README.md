# SFML-resize

Updating Win32 window contents during resizes using callbacks specifically for SFML 2.6.0.

This modification is based on the [pull request](https://github.com/SFML/SFML/pull/1604/files?diff=unified&w=0) by [hobby8](https://github.com/hobby8)

The code has been slightly altered in WindowImplWin32.cpp: WM_PAIN changed to WM_TIMER.
This alteration allows the window to receive callbacks even when the window size doesn't change (e.g. when the cursor is grabbed but not moved).
