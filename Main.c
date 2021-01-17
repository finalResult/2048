#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4
i
int N[SIZE][SIZE] = {0}, s = 0, st = 0, gO = FALSE;

void FOR_STRING(char head[], char foot[], char str[], int time);
void INIT();
void DRAW();

_Bool u();
_Bool l();
_Bool d();
_Bool r();
_Bool U();
_Bool L();
_Bool D();
_Bool R();
_Bool A();

int main() {
    INIT();
    int i, j, rv;
    char c = ' ';
    do {
        printf("\033[2J\033[H");
        DRAW(N);
        c = _getch();
        if(c == 'q') break;
        if(c == 'w') rv = u();
        if(c == 'a') rv = l();
        if(c == 's') rv = d();
        if(c == 'd') rv = r();
        if(!A(TRUE)) {
            gO = TRUE;
            break;
        }
        else if(rv) A(FALSE);
    } while(1);
    if(gO) printf("\n Game Over\n");
    else printf("\n Game Quit\n");
    return 0;
}

void INIT() {
    srand((intptr_t)(int*)time);
    A();
}

void DRAW() {
    int i, j;
    FOR_STRING("2048.c ", "", "      ", SIZE - 4);
    printf("%-4i | %11i", st++, s);
    FOR_STRING("\n:", "\n", "-----:", SIZE);
    for(i = 0;i < SIZE;i++) {
        printf("|");
        for(j = 0;j < SIZE;j++) {
            if(N[i][j] == 0) printf("     |");
            else printf("%5i|", N[i][j]);
        };
        FOR_STRING("\n:", "\n", "-----:", SIZE);
    }
    FOR_STRING("", "      - W A S D Q -\n", "   ", SIZE - 4);
    FOR_STRING("            ", "", "   ", SIZE - 4);
}

_Bool u() {
    int k = 0;
    while(U()) k++;
    return k != 0;
}

_Bool l() {
    int k = 0;
    while(L()) k++;
    return k != 0;
}

_Bool d() {
    int k = 0;
    while(D()) k++;
    return k != 0;
}

_Bool r() {
    int k = 0;
    while(R()) k++;
    return k != 0;
}

_Bool U() {
    _Bool ch = FALSE;
    int i, j;
    for(i = 1;i < SIZE;i++)
        for(j = 0;j < SIZE;j++)
            if(N[i][j] != 0) {
                if(N[i - 1][j] == 0) {
                    N[i - 1][j] = N[i][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
                if(N[i - 1][j] == N[i][j]) {
                    N[i - 1][j] *= 2;
                    s += N[i - 1][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
            };
    return ch;
}

_Bool L() {
    _Bool ch = FALSE;
    int i, j;
    for(i = 0;i < SIZE;i++)
        for(j = 1;j < SIZE;j++)
            if(N[i][j] != 0) {
                if(N[i][j - 1] == 0) {
                    N[i][j - 1] = N[i][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
                if(N[i][j - 1] == N[i][j]) {
                    N[i][j - 1] *= 2;
                    s += N[i][j - 1];
                    N[i][j] = 0;
                    ch = TRUE;
                }
            };
    return ch;
}

_Bool D() {
    _Bool ch = FALSE;
    int i, j;
    for(i = 0;i < SIZE - 1;i++)
        for(j = 0;j < SIZE;j++)
            if(N[i][j] != 0) {
                if(N[i + 1][j] == 0) {
                    N[i + 1][j] = N[i][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
                if(N[i + 1][j] == N[i][j]) {
                    N[i + 1][j] *= 2;
                    s += N[i + 1][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
            };
    return ch;
}

_Bool R() {
    _Bool ch = FALSE;
    int i, j;
    for(i = 0;i < SIZE;i++)
        for(j = 0;j < SIZE - 1;j++)
            if(N[i][j] != 0) {
                if(N[i][j + 1] == 0) {
                    N[i][j + 1] = N[i][j];
                    N[i][j] = 0;
                    ch = TRUE;
                }
                if(N[i][j + 1] == N[i][j]) {
                    N[i][j + 1] *= 2;
                    s += N[i][j + 1];
                    N[i][j] = 0;
                    ch = TRUE;
                }
            };
    return ch;
}

_Bool A(int t) {
    int c[SIZE * SIZE * 2], i, j, k = 0;
    for(i = 0;i < SIZE;i++)
        for(j = 0;j < SIZE;j++)
            if(N[i][j] == 0) {
                c[k++] = i;
                c[k++] = j;
            };
    if(k == 0) return FALSE;
    if(!t) {
        i = 2 * (rand() % (k / 2));
        N[c[i++]][c[i]] = 2;
    }
    return TRUE;
}

void FOR_STRING(char head[], char foot[], char str[], int time) {
    printf(head);
    for(int i = 0;i < time;i++) printf(str);
    printf(foot);
}