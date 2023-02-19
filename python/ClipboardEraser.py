# Buran
# Automatic clipboard eraser with three methods

import pyperclip
import keyboard
import logging


# The method: Clear after one paste, special thanks to 404_beef on Discord
def clear_clipboard(e):
    line = ', '.join(str(code) for code in keyboard._pressed_events) #! Issue: You need to double copy, then paste. Copying once won't copy anything.
    # '\r' and end='' overwrites the previous line.
    # ' '*40 prints 40 spaces at the end to ensure the previous line is cleared.
    print('\r' + line + ' ' * 40, end='')
    if line == "29, 47": # 29 is CTRL, 47 is V
        pyperclip.copy('') # clipboard cleared

keyboard.hook(clear_clipboard)
keyboard.wait() 