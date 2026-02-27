#include <stdio.h>

int main() {
    int *p = NULL;
    *p = 42; // Erreur de segmentation (SIGSEGV) -> Core dump
    return 0;
}
