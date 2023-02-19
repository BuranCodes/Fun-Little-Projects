// Buran
// Simple Windows message box
//! This program is not cross-platform since it uses <windows.h>!
#include <windows.h>

int DisplayMsgBox() {
    int msgboxID = MessageBoxW(
        NULL,
        (LPWSTR)L"Hello, World! This program was compiled in TDM-GCC.",
        (LPWSTR)L"Test box",
        MB_OK

    );
    return msgboxID;
}

int main() {
    DisplayMsgBox();
}