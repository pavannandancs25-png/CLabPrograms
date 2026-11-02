#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);
    
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int res_idx = 0;
    int open_count = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            open_count++;
            result[res_idx++] = s[i];
        } else if (s[i] == ')') {
            if (open_count > 0) {
                open_count--;
                result[res_idx++] = s[i];
            }
        } else {
            result[res_idx++] = s[i]; 
        }
    }
    result[res_idx] = '\0'; 
    
    if (open_count == 0) {
        return result;
    }
    
    int final_idx = res_idx;
    for (int i = res_idx - 1; i >= 0; i--) {
        if (result[i] == '(' && open_count > 0) {
            open_count--; 
            memmove(&result[i], &result[i + 1], final_idx - i);
            final_idx--;
        }
    }
    
    return result;
}