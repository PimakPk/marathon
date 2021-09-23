#include "header.h"

void outputInConsolePlus(long long i, long long j, long long k) {
    mx_printint(i);
    mx_printstr(" + ");
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}
void outputInConsoleSub(long long i, long long j, long long k) {
    mx_printint(i);
    mx_printstr(" - ");
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}
void outputInConsoleMult(long long i, long long j, long long k) {
    mx_printint(i);
    mx_printstr(" * ");
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}
void outputInConsoleDiv(long long i, long long j, long long k) {
    mx_printint(i);
    mx_printstr(" / ");
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}

void outputAndLogic(char *operand1, char *operation, char *operand2, char *result,
                        int operand1_len, int operand2_len, int res_len) {
    if (*operation == '?') {
        outputAndLogic(operand1, "+", operand2, result,
                        operand1_len, operand2_len, res_len);
        outputAndLogic(operand1, "-", operand2, result,
                        operand1_len, operand2_len, res_len);
        outputAndLogic(operand1, "*", operand2, result,
                        operand1_len, operand2_len, res_len);
        outputAndLogic(operand1, "/", operand2, result,
                        operand1_len, operand2_len, res_len);
        return;
    }
    bool iIsZero = false;
    if (operand1[0] == '-') {
        iIsZero = true;
        operand1++;
        operand1_len--;
    } 
    bool jIsZero = false;
    if (operand2[0] == '-') {
        jIsZero = true;
        operand2++;
        operand2_len--;
    }
    bool kIsZero = false;
    if (result[0] == '-') {
        kIsZero = true;
        result++;
        res_len--;
    }
    long long first_num = mx_atoi(operand1);
    long long second_num = mx_atoi(operand2);
    long long third_num = mx_atoi(result);
    for (long long i = 0; i < mx_pow(10, operand1_len); i++) {
        if (first_num > 0) {
            i = first_num;
        }
        char *i_str = mx_itoa(i);
        int i_str_length = mx_strlen(i_str);
        bool iIsCorrect = true;
        for (int i_i = 0; i_i < operand1_len - i_str_length; i_i++) {
            if (mx_isdigit(operand1[i_i]) && operand1[i_i] != '0') {
                iIsCorrect = false;
                break;
            }
        }
        for (int i_i = operand1_len - i_str_length, i_str_i = 0; i_i < operand1_len; i_i++, i_str_i++) {
            if (operand1[i_i] != '?' && operand1[i_i] != i_str[i_str_i]) {
                iIsCorrect = false;
                break;
            }
        }
        free(i_str);
        i_str = NULL;
        if (!iIsCorrect) {
            continue;
        }
        for (long long j = 0; j < mx_pow(10, operand2_len); j++) {  
            if (second_num > 0) {
                j = second_num;
            }
            char *j_str = mx_itoa(j);
            int j_str_length = mx_strlen(j_str);
            bool jIsCorrect = true;
            for (int j_i = 0; j_i < operand2_len - j_str_length; j_i++) {
                if (mx_isdigit(operand2[j_i]) && operand2[j_i] != '0') {
                    jIsCorrect = false;
                    break;
                }
            }
            for (int j_i = operand2_len - j_str_length, j_str_i = 0; j_i < operand2_len; j_i++, j_str_i++) {
                if (operand2[j_i] != '?' && operand2[j_i] != j_str[j_str_i]) {
                    jIsCorrect = false;
                    break;
                }
            }
            free(j_str);
            j_str = NULL;
            if (!jIsCorrect) {
                continue;
            }
            for (long long k = 0; k < mx_pow(10, res_len); k++) {
                if (third_num > 0) {
                    k = third_num;
                }
                char *k_str = mx_itoa(k);
                int k_str_length = mx_strlen(k_str);
                bool kIsCorrect = true;
                for (int k_i = 0; k_i < res_len - k_str_length; k_i++) {
                    if (mx_isdigit(result[k_i]) && result[k_i] != '0') {
                        kIsCorrect = false;
                        break;
                    }
                }
                for (int k_i = res_len - k_str_length, k_str_i = 0; k_i < res_len; k_i++, k_str_i++) {
                    if (result[k_i] != '?' && result[k_i] != k_str[k_str_i]) {
                        kIsCorrect = false;
                        break;
                    }
                }
                free(k_str);
                k_str = NULL;
                if (!kIsCorrect) {
                    continue;
                }
                //output
                if (iIsZero) {
                    i *= -1;
                }
                if (jIsZero) {
                    j *= -1;
                }
                if (kIsZero) {
                    k *= -1;
                }
                if (*operation == '+') {
                    if (i + j == k) {
                        outputInConsolePlus(i, j, k);
                    }
                }
                else if (*operation == '-') {
                        if (i - j == k) {
                        outputInConsoleSub(i, j, k);
                    }
                }
                else if (*operation == '*') {
                        if (i * j == k) {
                        outputInConsoleMult(i, j, k);
                    }
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == k) {
                        outputInConsoleDiv(i, j, k);
                    }
                }
                if (iIsZero) {
                    i *= -1;
                }
                if (jIsZero) {
                    j *= -1;
                }
                if (kIsZero) {
                    k *= -1;
                }
                if (third_num > 0) {
                    break;
                }
            }
            if (second_num > 0) {
                break;
            }
        }
        if (first_num > 0) {
            break;
        }
    }
    if (iIsZero) {
        operand1--;
    }
    if (jIsZero) {
        operand2--;
    }
    if (kIsZero) {
        result--;
    }
}

