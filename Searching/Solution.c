// Problem: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/palindrome-split-efe4c78a/

#include <stdio.h>
#include <string.h>

int maxPalindromicSubsequences(char* s) {
    int freq[50] = {0};
    int i = 0;
    int palindromes = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    for (i = 0; i < 50; i++) {
        palindromes += freq[i] / 2; 
    }
    return palindromes;
}

int main() {
    int t;
    char s[1001];
    scanf("%d", &t);
    
    while (t--) {
        scanf("%s", s);
        printf("%d\n", maxPalindromicSubsequences(s));
    }
    return 0;
}
