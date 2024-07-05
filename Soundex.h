#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
 c = toupper(c);
 const char soundexMapping[26] = "01230120022455012623010202";
 if (c < 'A' || c > 'Z') {
     return '0';
 }
 return soundexMapping[c - 'A'];
}

void generateSoundex(const char *name, char *soundex) {
 int len = strlen(name);
 soundex[0] = toupper(name[0]);
 int sIndex = 1;
 for (int i = 1; i < len && sIndex < 4; i++) {
     char code = getSoundexCode(name[i]);
     if (code != '0' && code != soundex[sIndex - 1]) {
         soundex[sIndex++] = code;
     }
 }
 while (sIndex < 4) {
     soundex[sIndex++] = '0';
 }
 soundex[4] = '\0';
}

int main() {
 char name[] = "Smith";
 char soundex[5];
 generateSoundex(name, soundex);
 printf("Soundex code for %s is %s\n", name, soundex);
 return 0;
}
