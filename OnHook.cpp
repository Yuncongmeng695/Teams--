#include <windows.h>
#include <stdio.h>
#include <conio.h>

volatile int running = 0; // 控制循环运行状态

void simulateKeyPress(WORD key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &input, sizeof(INPUT));
}

DWORD WINAPI checkInput(LPVOID lpParam) {
    while (1) {
        if (_kbhit()) { // 检测按键按下
            char ch = _getch(); // 获取按键字符
            if ((ch == 's')||(ch == 'S')) {
                running = 0; // 暂停
                printf("/****Stop!*****/\n");
            }
            else if ((ch == 'c')||(ch == 'C')) {
                running = 1; // 继续
                printf("/****Run!*****/\n");
            }
            else if ((ch == 'b') || (ch == 'B')) {
                running = 255;
                printf("/*****Break!*****/\n");
            }
        }
        Sleep(100); // 稍微休眠以减少CPU占用
    }
    return 0;
}

int main() {
    int count = 0;

    printf("v1.1\nPut 'C' to start\nPut 'S' to stop\nPut 'B' to Break the program\n");

    HANDLE hThread = CreateThread(NULL, 0, checkInput, NULL, 0, NULL); // 创建线程检查输入

    while (1) {
        if (running) {
            printf("On Hook Time:%d s\n", count++);
            simulateKeyPress(VK_SPACE); // 模拟空格键输入
            Sleep(1000); // 每秒输出一次
        }
        else {
            Sleep(100); // 暂停时稍微休眠以减少CPU占用
        }
        if (running == 255) {
            break;
        }
    }

    CloseHandle(hThread); // 关闭线程句柄
    return 0;
}
